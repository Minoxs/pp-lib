#pragma once

#include "FullBeatmap.h"
#include "Skill.h"
#include "shared/Beatmap.h"
#include "shared/Common.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

typedef struct {
	f64 StarRating;
	f64 Aim;
	f64 Speed;
	f64 OD;
	f64 AR;
	f64 MaxCombo;
	f64 FlashLight;
	f64 SliderFactor;
	f64 SpeedNoteCount;
} BeatmapDifficulty;

class DifficultyCalculator {
public:
	explicit DifficultyCalculator(FullBeatmap *beatmap);

	BeatmapDifficulty Calculate(const std::vector<EMods> &mods);

	static double DifficultyRange(double difficulty, double min, double mid, double max) {
		if (difficulty > 5)
			return mid + (max - mid) * (difficulty - 5) / 5;
		if (difficulty < 5)
			return mid - (mid - min) * (5 - difficulty) / 5;
		return mid;
	};

protected:
	FullBeatmap *_beatmap;
	double _clockRate = 0;

	virtual BeatmapDifficulty CreateDifficultyAttributes(FullBeatmap *beatmap, const std::vector<EMods> &mods, const std::vector<Skill *> &skills, double clockRate) = 0;
	virtual std::vector<DifficultyHitObject *> CreateDifficultyHitObjects(FullBeatmap *beatmap, double clockRate) = 0;
	virtual std::vector<Skill *> CreateSkills(FullBeatmap *beatmap, const std::vector<EMods> &mods, double clockRate) = 0;

private:
	void preProcess(const std::vector<EMods> &mods);
};

DIFF_NAMESPACE_END
