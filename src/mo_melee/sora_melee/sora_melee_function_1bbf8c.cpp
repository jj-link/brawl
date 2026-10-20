#pragma force_active on
typedef signed int s32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x18];
    s32 f18;
};

extern "C" void* fn_27_1BBF8C(Obj* p, s32 idx) {
    s32 i = (p->f18 >> 27) + idx;
    if (i >= 8) {
        i -= 8;
    }
    return (u8*)p + 0x1c + i * 12;
}
