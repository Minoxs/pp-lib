#pragma once

#include "HitObject.h"
#include "shared/Beatmap.h"
#include "shared/Common.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

// TODO IMPLEMENT BEATMAP LOADER
class FullBeatmap : public Beatmap {
public:
	std::vector<HitObject *> HitObjects;
	s32 MaxCombo;
	s32 HitCircleCount;
	s32 SliderCount;
	s32 SpinnerCount;
	f64 AR;
	f64 OD;
};

DIFF_NAMESPACE_END
