#pragma once

#include "shared/Common.h"

DIFF_NAMESPACE_BEGIN

// TODO IMPLEMENT THIS STUFF ?
class HitObject {
};

// TODO IMPLEMENT THIS STUFF ?
class DifficultyHitObject {
public:
	DifficultyHitObject(HitObject *current, HitObject *prevObject, HitObject *prevPrevObject, double clockRate, std::vector<DifficultyHitObject *> *objects, int index);
};


DIFF_NAMESPACE_END
