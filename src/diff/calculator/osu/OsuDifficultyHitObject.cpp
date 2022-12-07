#include "diff/calculator/osu/OsuDifficultyHitObject.h"

DIFF_NAMESPACE_BEGIN

OsuDifficultyHitOject::OsuDifficultyHitOject(HitObject *current, HitObject *prevObject, HitObject *prevPrevObject, double clockRate, std::vector<DifficultyHitObject *> *objects, int index) : DifficultyHitObject(current, prevObject, prevPrevObject, clockRate, objects, index) {

}

DIFF_NAMESPACE_END
