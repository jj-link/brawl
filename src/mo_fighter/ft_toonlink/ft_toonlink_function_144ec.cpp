#pragma force_active on
struct ToonLinkCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_121_144EC(void* object, bool selected) {
    ToonLinkCallbackFlags* flags =
        reinterpret_cast<ToonLinkCallbackFlags*>(
            static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = selected;
}
