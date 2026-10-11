// Shared leaf callbacks referenced by the Lucario module's existing virtual tables.
// The concrete object layout is not exposed by the headers; only byte 0xA4 is used.
struct LucarioCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

static inline LucarioCallbackFlags* callbackFlags(void* object) {
    return reinterpret_cast<LucarioCallbackFlags*>(static_cast<unsigned char*>(object) + 0xA4);
}

extern "C" bool fn_118_13A10(void* object) {
    return callbackFlags(object)->selected != 0;
}

extern "C" void fn_118_13A24(void* object, bool selected) {
    callbackFlags(object)->selected = selected;
}

extern "C" bool fn_118_13A34(void*, char eventKind) {
    char observedKind = 12;
    return eventKind == observedKind;
}

extern "C" bool fn_118_13A50(void*) {
    return false;
}

extern "C" bool fn_118_13A58(void*) {
    return true;
}
