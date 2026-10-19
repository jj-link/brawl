#pragma force_active on
struct LinkCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_93_144A0(void* object, bool selected) {
    reinterpret_cast<LinkCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4
    )->selected = selected;
}
