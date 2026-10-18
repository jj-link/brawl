#pragma force_active on
// Bitfield layout: the second bit from the top of the byte at offset 0xA4 (mask 0x40) is the flag.
struct FtFlags {
    unsigned char high : 1;
    unsigned char flag : 1;
    unsigned char low : 6;
};

static inline FtFlags* flagsAt(void* object) {
    return reinterpret_cast<FtFlags*>(static_cast<unsigned char*>(object) + 0xA4);
}

extern "C" void fn_92_12740(void* object, bool value) {
    flagsAt(object)->flag = value;
}
