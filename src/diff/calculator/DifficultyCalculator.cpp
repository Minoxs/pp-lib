#include <utility>

#include "diff/calculator/DifficultyCalculator.h"

DIFF_NAMESPACE_BEGIN

DifficultyCalculator::DifficultyCalculator(FullBeatmap *beatmap) : _beatmap(beatmap) {
}

BeatmapDifficulty DifficultyCalculator::Calculate(const std::vector<EMods> &mods) {
	preProcess(mods);

	auto skills = CreateSkills(_beatmap, mods, _clockRate);

	if (_beatmap->NumHitObjects() == 0) {
		return CreateDifficultyAttributes(_beatmap, mods, skills, _clockRate);
	}

	auto objects = CreateDifficultyHitObjects(_beatmap, _clockRate);

	for (auto &object: objects) {
		for (auto &skill: skills) {
			skill->Process(object);
		}
	}

	return CreateDifficultyAttributes(_beatmap, mods, skills, _clockRate);
}

void DifficultyCalculator::preProcess(const std::vector<EMods> &mods) {
}

DIFF_NAMESPACE_END
