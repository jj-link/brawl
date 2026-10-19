#pragma force_active on
struct RobotCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_120_13988(void* object, bool selected) {
    RobotCallbackFlags* flags = reinterpret_cast<RobotCallbackFlags*>(
        static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = selected;
}
