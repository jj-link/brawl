#pragma force_active on
// Shared leaf callbacks referenced by the module's existing virtual tables.
// Only the byte-bitfield at offset 0xA4 is accessed.
struct CallbackFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

static inline CallbackFlags* callbackFlags(void* object) {
    return reinterpret_cast<CallbackFlags*>(static_cast<unsigned char*>(object) + 0xA4);
}

extern "C" void fn_119_13274(void* object, bool selected) {
    callbackFlags(object)->selected = selected;
}
