#pragma force_active on
struct PokeCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_116_111F0(void* object, bool selected) {
    PokeCallbackFlags* flags = reinterpret_cast<PokeCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = selected;
}
