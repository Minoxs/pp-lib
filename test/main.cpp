#include "shared/Beatmap.h"
#include "pp/performance/Osu/OsuScore.h"
#include "diff/calculator/DifficultyCalculator.h"

using namespace pp;

int main() {
    auto b = new Beatmap(0);
    b->SetMode(EGamemode::Osu);
    b->SetNumHitCircles(176);
    b->SetNumSliders(145);
    b->SetNumSpinners(1);
    auto mods = EMods::HardRock;
    b->SetDifficultyAttribute(mods, Beatmap::Aim, 3.062f);
    b->SetDifficultyAttribute(mods, Beatmap::Speed, 2.216f);
    b->SetDifficultyAttribute(mods, Beatmap::OD, 10.0f);
    b->SetDifficultyAttribute(mods, Beatmap::AR, 10.0f);
    b->SetDifficultyAttribute(mods, Beatmap::MaxCombo, 476.0f);
    b->SetDifficultyAttribute(mods, Beatmap::Flashlight, 1.931f);
    b->SetDifficultyAttribute(mods, Beatmap::SliderFactor, 0.982f);
    b->SetDifficultyAttribute(mods, Beatmap::SpeedNoteCount, 77.565f);

    auto s = OsuScore(
            0,
            EGamemode::Osu,
            0,
            0,
            3705245,
            476,
            281,
            37,
            4,
            0,
            39,
            22,
            HardRock,
            *b
            );

    printf("PP: %f\nAcc:%f\n", s.TotalValue(), s.Accuracy());
    return 0;
}
