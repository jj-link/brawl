#pragma force_active on
struct KoopaCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_102_1BCC4(void* object, bool selected) {
    reinterpret_cast<KoopaCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4
    )->selected = selected;
}
