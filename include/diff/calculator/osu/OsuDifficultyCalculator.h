#pragma once

#include "diff/calculator/DifficultyCalculator.h"
#include "diff/calculator/FullBeatmap.h"
#include "shared/Common.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

class OsuDifficultyCalculator : public DifficultyCalculator {
public:
	explicit OsuDifficultyCalculator(FullBeatmap *beatmap) : DifficultyCalculator(beatmap) {}

protected:
	BeatmapDifficulty CreateDifficultyAttributes(FullBeatmap *beatmap, const std::vector<EMods> &mods, const std::vector<Skill *> &skills, double clockRate) override;
	std::vector<DifficultyHitObject *> CreateDifficultyHitObjects(FullBeatmap *beatmap, double clockRate) override;
	std::vector<Skill *> CreateSkills(FullBeatmap *beatmap, const std::vector<EMods> &mods, double clockRate) override;

private:
	const double DIFFICULTY_MULTIPLIER = 0.0675f;
};

DIFF_NAMESPACE_END
