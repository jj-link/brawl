#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

namespace {
struct SnakeFlags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};
}

extern "C" {
void fn_122_13A3C(void* a, void* b);
s16* fn_122_13B24(s16* destination, const s16* source);
void fn_122_13B1C(void* a, s16* b, void* c);
}

extern "C" void fn_122_13A8C(u8* obj, const s16* src, void* arg) {
    s16 local[4];
    u8* p = obj + 0xC;
    if (src[0] & 4) {
        bool enabled = reinterpret_cast<SnakeFlags*>(p + 5)->enabled;
        if (enabled == true && p[6] == 0) {
            fn_122_13A3C(p, arg);
        }
    }
    fn_122_13B24(local, src);
    fn_122_13B1C(obj + 4, local, arg);
}
