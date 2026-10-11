#include <math.h>

// The original operates on the full FPR value without a single-precision round.
extern "C" double fn_114_C4CC(double value) {
    return fabs(value);
}
