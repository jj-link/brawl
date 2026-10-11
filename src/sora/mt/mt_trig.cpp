#include <mt/mt_trig.h>

// pi/2
#define HALF_PI 1.5707964f
// 2^24 / (2*pi)
#define RAD_TO_FIXED_PT 2670176.8f
// (2*pi) / 2^24
#define FIXED_PT_TO_RAD 3.7450704e-7f

// Quarter-turn and reduce range to [0, 2^24)
static inline s32 reduceRange(s32 fixedPtAngle) {
    return (fixedPtAngle + 0x400000) & 0x00FFFFFF;
}

// Fit to range [-2^22, 2^22), i.e. [-pi/2, pi/2)
static inline s32 fitToRange(s32 theta) {
    if (theta > 0x800000)
        theta = 0x1000000 - theta;
    theta -= 0x400000;

    return theta;
}

// 9th order Taylor polynomial approximation of sin(x)
static inline float taylor(float x) {
    const float C1 = 1.0f;            // 1
    const float C2 = -0.16666657f;    // -1/3!
    const float C3 = 0.0083330255f;   // 1/5!
    const float C4 = -0.00019807414f; // -1/7!
    const float C5 = 0.000002601887f; // 1/9!
    return x * (C1 + ((x * x) * (C2 + ((x * x) * (C3 + ((x * x) * (C4 + (C5 * (x * x)))))))));
}

float mtSinf(float angle) {
    return taylor(FIXED_PT_TO_RAD * fitToRange(reduceRange((RAD_TO_FIXED_PT * angle))));
}

float mtCosf(float angle) {
    return mtSinf(angle + HALF_PI);
}

void mtSinCosf(float rad, float* sinOut, float* cosOut) {
    s32 fixedAngle;
    s32 sinReduced;
    s32 cosReduced;
    fixedAngle = RAD_TO_FIXED_PT * rad;
    sinReduced = fixedAngle + 0x400000;
    sinReduced &= 0x00FFFFFF;
    fixedAngle = RAD_TO_FIXED_PT * (rad + HALF_PI);
    cosReduced = fixedAngle + 0x400000;
    cosReduced &= 0x00FFFFFF;
    sinReduced = fitToRange(sinReduced);
    cosReduced = fitToRange(cosReduced);

    float cosAngle;
    float sinSquare;
    float cosSquare;
    float sinAngle;
    sinAngle = FIXED_PT_TO_RAD * sinReduced;
    cosAngle = FIXED_PT_TO_RAD * cosReduced;
    sinSquare = sinAngle * sinAngle;
    cosSquare = cosAngle * cosAngle;
    float sinApprox = sinAngle * (1.0f + sinSquare * (-0.16666657f + sinSquare *
        (0.0083330255f + sinSquare * (-0.00019807414f + 0.000002601887f * sinSquare))));
    float cosApprox = cosAngle * (1.0f + cosSquare * (-0.16666657f + cosSquare *
        (0.0083330255f + cosSquare * (-0.00019807414f + 0.000002601887f * cosSquare))));
    *sinOut = sinApprox;
    *cosOut = cosApprox;
}
