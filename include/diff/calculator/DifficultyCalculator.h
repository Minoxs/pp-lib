#pragma once

#include "shared/Common.h"
#include "shared/Beatmap.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

class DifficultyCalculator {
    explicit DifficultyCalculator(Beatmap beatmap);
};

DIFF_NAMESPACE_END
