#include "Bindings.h"
#include "pp/performance/Beatmap.h"
#include "pp/performance/Osu/OsuScore.h"

using namespace pp;

BeatmapInfo stTest() {
    return {
        1.0f,
        1.0f,
        3.2f,
        10.0f,
        476.0f,
        0.0f,
        3.2f,
        99.83f
    };
}

float aTest(BeatmapInfo a) {
    printf("Aim: %f\nMaxCombo: %f\n", a.Aim, a.MaxCombo);
    return a.SpeedNoteCount;
}

int runTest() {
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

    int ret = (int) s.TotalValue();
    printf("PP: %f\nAcc:%f\n", s.TotalValue(), s.Accuracy());
    return ret;
}
