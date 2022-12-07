#pragma once

#include "diff/calculator/Skill.h"
#include "shared/Common.h"

DIFF_NAMESPACE_BEGIN

class Speed : public Skill {
public:
	explicit Speed(const std::vector<EMods> &mods);

	void Process(DifficultyHitObject* current) override;
	double DifficultyValue() override;
	double RelevantNoteCount();
};

DIFF_NAMESPACE_END
