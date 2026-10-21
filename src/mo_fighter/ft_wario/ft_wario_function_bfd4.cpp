#pragma force_active on
typedef short s16;
typedef int s32;
typedef unsigned char u8;

extern "C" {
void fn_110_BF84(void* a, void* b);
s16* fn_110_C6C4(s16* destination, const s16* source);
void fn_110_C064(void* a, const s16* b, void* c);
}

extern "C" void fn_110_BFD4(u8* self, const s16* flags, void* arg) {
    s16 tmp[2];
    u8* p = self + 0xC;
    if ((flags[0] & 1) != 0) {
        u8 bit = (p[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && p[6] == 0) {
            fn_110_BF84(p, arg);
        }
    }
    fn_110_C6C4(tmp, flags);
    fn_110_C064(self + 4, tmp, arg);
}
