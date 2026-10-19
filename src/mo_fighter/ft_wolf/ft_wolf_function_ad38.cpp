#pragma force_active on
extern "C" bool fn_125_AD38(void*, char eventKind) {
    char observedKind = 12;
    return eventKind == observedKind;
}
