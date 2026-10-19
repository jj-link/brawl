#include <wn/weapon.h>
#pragma force_active on

extern "C" bool fn_101_CED8(void*, char eventKind) {
    char observedKind = 12;
    return eventKind == observedKind;
}
