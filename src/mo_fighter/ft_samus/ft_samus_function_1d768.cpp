#pragma force_active on
struct SamusCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_94_1D768(void* object, bool selected) {
    SamusCallbackFlags* flags = reinterpret_cast<SamusCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = selected;
}
