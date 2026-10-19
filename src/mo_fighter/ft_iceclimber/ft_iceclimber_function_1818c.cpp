#pragma force_active on
struct IceClimberCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_105_1818C(void* object, bool selected) {
    IceClimberCallbackFlags* flags =
        reinterpret_cast<IceClimberCallbackFlags*>(
            static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = selected;
}
