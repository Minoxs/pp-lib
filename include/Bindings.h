#pragma once
#ifndef PP_LIB_BINDINGS_H
#define PP_LIB_BINDINGS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float Aim;
    float Speed;
    float OD;
    float AR;
    float MaxCombo;
    float FlashLight;
    float SliderFactor;
    float SpeedNoteCount;
} BeatmapInfo;

BeatmapInfo stTest();
float aTest(BeatmapInfo a);

int runTest();

#ifdef __cplusplus
};
#endif

#endif //PP_LIB_BINDINGS_H
