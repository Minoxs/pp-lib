#pragma once

#include "HitObject.h"
#include "shared/Beatmap.h"
#include "shared/Common.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

class FullBeatmap : public Beatmap {
public:
	std::vector<HitObject *> HitObjects;
};

DIFF_NAMESPACE_END
