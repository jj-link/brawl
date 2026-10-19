#pragma force_active on
extern "C" bool fn_110_8EF4(void*, char eventKind) {
    char observedKind = 12;
    return eventKind == observedKind;
}
