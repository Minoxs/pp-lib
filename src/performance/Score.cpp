#include <pp/Common.h>

#include <pp/performance/Score.h>

PP_NAMESPACE_BEGIN

Score::Score(
	s64 scoreId,
	EGamemode mode,
	s64 userId,
	s32 beatmapId,
	s32 score,
	s32 maxCombo,
	s32 num300,
	s32 num100,
	s32 num50,
	s32 numMiss,
	s32 numGeki,
	s32 numKatu,
	EMods mods
)
:
_scoreId{scoreId},
_mode{mode},
_userId{userId},
_beatmapId{beatmapId},
_score{std::max(0, score)},
_maxCombo{std::max(0, maxCombo)},
_num300{std::max(0, num300)},
_num100{std::max(0, num100)},
_num50{std::max(0, num50)},
_numMiss{std::max(0, numMiss)},
_numGeki{std::max(0, numGeki)},
_numKatu{std::max(0, numKatu)},
_mods{mods}
{
}

PP_NAMESPACE_END
