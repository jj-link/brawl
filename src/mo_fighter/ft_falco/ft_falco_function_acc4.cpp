#include <types.h>
#pragma force_active on

extern "C" bool fn_108_ACC4(void*, char eventKind) {
    char observedKind = 12;
    return eventKind == observedKind;
}
