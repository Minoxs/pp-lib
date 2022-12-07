#pragma once

#include "HitObject.h"
#include "shared/Common.h"

using namespace shared;

DIFF_NAMESPACE_BEGIN

class Skill {
public:
	explicit Skill(std::vector<EMods> *mods) {
		_mods = mods;
	}

	virtual void Process(DifficultyHitObject *current) = 0;

	virtual double DifficultyValue() = 0;

protected:
	std::vector<EMods> *_mods;
};

DIFF_NAMESPACE_END
