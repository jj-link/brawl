#pragma force_active on
struct GanonCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_109_11520(void* object, bool selected) {
    reinterpret_cast<GanonCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4
    )->selected = selected;
}
