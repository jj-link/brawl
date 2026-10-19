#pragma force_active on
struct SonicCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_123_13D78(void* object, bool selected) {
    SonicCallbackFlags* flags = reinterpret_cast<SonicCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = selected;
}
