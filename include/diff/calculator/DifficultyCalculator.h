#pragma once

#include "FullBeatmap.h"
#include "Skill.h"
#include "shared/Beatmap.h"
#include "shared/Common.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

typedef struct {
	double Aim;
	double Speed;
	double StarRating;
	double OD;
	double AR;
	double MaxCombo;
	double FlashLight;
	double SliderFactor;
	double SpeedNoteCount;
} BeatmapDifficulty;

class DifficultyCalculator {
public:
	explicit DifficultyCalculator(FullBeatmap *beatmap);

	BeatmapDifficulty Calculate(const std::vector<EMods> &mods);

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
