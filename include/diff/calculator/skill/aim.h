#pragma once

#include "diff/calculator/Skill.h"
#include "shared/Common.h"

DIFF_NAMESPACE_BEGIN

class Aim : public Skill {
public:
	Aim(const std::vector<EMods> &mods, bool withSliders);

	void Process(DifficultyHitObject current) override;
	double DifficultyValue() override;
};

DIFF_NAMESPACE_END
