#include "diff/calculator/osu/OsuDifficultyCalculator.h"
#include "diff/calculator/osu/OsuDifficultyHitObject.h"
#include "diff/calculator/skill/aim.h"
#include "diff/calculator/skill/flashlight.h"
#include "diff/calculator/skill/speed.h"

DIFF_NAMESPACE_BEGIN

BeatmapDifficulty OsuDifficultyCalculator::CreateDifficultyAttributes(FullBeatmap* beatmap, const std::vector<EMods> &mods, const std::vector<Skill*> &skills, double clockRate) {
	auto ret = BeatmapDifficulty {
		.Aim =  0,
		.Speed =  0,
		.OD = 0,
		.AR = 0,
		.MaxCombo = 0,
		.FlashLight = 0,
		.SliderFactor = 0,
		.SpeedNoteCount = 0
	};

	if (beatmap->HitObjects.empty()) return ret;

	double aimRating = sqrt(skills[0]->DifficultyValue()) * DIFFICULTY_MULTIPLIER;
	double aimRatingNoSliders = sqrt(skills[1]->DifficultyValue()) * DIFFICULTY_MULTIPLIER;
	double speedRating = sqrt(skills[2]->DifficultyValue()) * DIFFICULTY_MULTIPLIER;
	double speedNotes = ((Speed*) skills[2])->RelevantNoteCount();
	double flashlightRating = sqrt(skills[3]->DifficultyValue()) * DIFFICULTY_MULTIPLIER;
	double sliderFactor = aimRating > 0 ? aimRatingNoSliders / aimRating : 1;

	double baseAimPerformance = pow(5 * std::max(1.0, aimRating / 0.0675f) - 4, 3) / 100000;
	double baseSpeedPerformance = pow(5 * std::max(1.0, speedRating / 0.0675f) - 4, 3) / 100000;
	double baseFlashlightPerformance = 0.0f;

	if (std::find(mods.begin(), mods.end(), EMods::Flashlight) != mods.end()) {
		baseFlashlightPerformance = pow(flashlightRating, 2.0f) * 25.0f;
	}

	double basePerformance = pow(
					pow(baseAimPerformance, 1.1f) +
					pow(baseSpeedPerformance, 1.1f) +
					pow(baseFlashlightPerformance, 1.1),
					1.0f / 1.1f
	);

	// TODO FINISH TRANSPILING

	return ret;
}

std::vector<DifficultyHitObject *> OsuDifficultyCalculator::CreateDifficultyHitObjects(FullBeatmap* beatmap, double clockRate) {
	auto objects = std::vector<DifficultyHitObject *>(beatmap->HitObjects.size()-1);

	for (int i = 1; i < beatmap->HitObjects.size(); ++i) {
		HitObject* lastLast = (i > 1) ? beatmap->HitObjects[i - 2] : nullptr;
		objects[i-1] = new OsuDifficultyHitOject(beatmap->HitObjects[i], beatmap->HitObjects[i-1], lastLast, clockRate, &objects, i-1);
	}

	return objects;
}

std::vector<Skill*> OsuDifficultyCalculator::CreateSkills(FullBeatmap* beatmap, const std::vector<EMods> &mods, double clockRate) {
	auto ret = std::vector<Skill *>(4);

	ret[0] = new Aim(mods, true);
	ret[1] = new Aim(mods, false);
	ret[2] = new Speed(mods);
	ret[3] = new Flashlight(mods);

	return ret;
}

DIFF_NAMESPACE_END
