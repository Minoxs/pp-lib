#pragma once

#include "diff/calculator/HitObject.h"
#include "shared/Common.h"

DIFF_NAMESPACE_BEGIN

class OsuDifficultyHitOject : public DifficultyHitObject {
public:
	OsuDifficultyHitOject(HitObject *current, HitObject *prevObject, HitObject *prevPrevObject, double clockRate, std::vector<DifficultyHitObject *> *objects, int index);
};

DIFF_NAMESPACE_END
