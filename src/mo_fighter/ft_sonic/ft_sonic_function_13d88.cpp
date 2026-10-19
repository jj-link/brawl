#pragma force_active on
extern "C" bool fn_123_13D88(void* object, char eventKind)
{
    (void)object;
    char observedKind = 12;
    return eventKind == observedKind;
}
