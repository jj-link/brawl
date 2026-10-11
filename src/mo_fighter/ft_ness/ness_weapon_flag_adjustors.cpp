extern "C" {
void fn_101_15CAC(void*, bool);
bool fn_101_15C98(void*);
}

// Original adjustors forward the raw EABI argument word to the bool entry.
extern "C" void fn_101_163B4(void* object, unsigned int selected) {
    typedef void (*NessRawFlagSetter)(void*, unsigned int);
    reinterpret_cast<NessRawFlagSetter>(fn_101_15CAC)(
        reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x88), selected);
}
extern "C" bool fn_101_163BC(void* object) {
    return fn_101_15C98(reinterpret_cast<void*>(reinterpret_cast<unsigned long>(object) - 0x88));
}
