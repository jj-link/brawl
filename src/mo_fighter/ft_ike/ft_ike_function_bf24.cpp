#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct IkeSub {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
    u8 after;
};

extern "C" void fn_119_BED4(void* self, void* arg);
extern "C" s16* fn_119_C52C(s16* destination, const s16* source);
extern "C" s32 fn_119_BFB4(u8* obj, s16* src, void* arg);

extern "C" void fn_119_BF24(u8* self, s16* p, void* arg) {
    s16 tmp[4];
    IkeSub* sub = reinterpret_cast<IkeSub*>(self + 0xC);
    if ((p[0] & 1) != 0) {
        bool f = sub->flag;
        if (f == true && sub->after == 0) {
            fn_119_BED4(sub, arg);
        }
    }
    fn_119_C52C(tmp, p);
    fn_119_BFB4(self + 4, tmp, arg);
}
