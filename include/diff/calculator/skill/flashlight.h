#pragma once

#include "diff/calculator/Skill.h"
#include "shared/Common.h"

DIFF_NAMESPACE_BEGIN

class Flashlight : public Skill {
public:
	Flashlight(const std::vector<EMods> &mods);

	void Process(DifficultyHitObject current) override;
	double DifficultyValue() override;
};

DIFF_NAMESPACE_END
