#pragma force_active on
struct WarioCallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

static inline WarioCallbackFlags* callbackFlags(void* object) {
    return reinterpret_cast<WarioCallbackFlags*>(static_cast<unsigned char*>(object) + 0xA4);
}

extern "C" void fn_110_12934(void* object, bool selected) {
    callbackFlags(object)->selected = selected;
}
