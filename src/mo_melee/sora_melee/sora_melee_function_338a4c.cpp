#pragma force_active on
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

struct Sub {
    u8 pad[5];
    u8 flagA : 1;
    u8 pad2 : 7;
    u8 flagB;
};

extern "C" void fn_27_338DAC(u8* self, u32 arg);
extern "C" s32 fn_27_338AE4(u8* self, s16* p, u32 arg);

extern "C" void fn_27_338A4C(u8* self, const s16& p, u32 arg) {
    bool first = (p & 1) != 0;
    Sub* sub = (Sub*)(self + 0xc);
    if (first) {
        bool b = sub->flagA;
        if (b == true && sub->flagB == 0) {
            fn_27_338DAC((u8*)sub, arg);
        }
    }
    s16 v = p;
    fn_27_338AE4(self + 4, &v, arg);
}
