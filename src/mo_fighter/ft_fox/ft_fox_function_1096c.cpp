#pragma force_active on
struct FoxCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_97_1096C(void* object, bool selected) {
    reinterpret_cast<FoxCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4
    )->selected = selected;
}
