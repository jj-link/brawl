extern "C" bool fn_101_15CBC(void*, char);

// Preserve the original complete EABI argument word; the predicate interprets char.
extern "C" bool fn_101_1634C(void* object, unsigned int eventKind) {
    typedef bool (*NessRawKindEntry)(void*, unsigned int);
    return reinterpret_cast<NessRawKindEntry>(fn_101_15CBC)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x48), eventKind);
}
