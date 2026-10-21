#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct WolfEntry {
    u8 pad[5];
    u8 enabled : 1;
    u8 otherFlags : 7;
    u8 b6;
    bool isEnabled() const { return enabled; }
};

extern "C" void fn_125_DDFC(void* obj, void* arg);
extern "C" void fn_125_E53C(s16* dest, const s16* src);
extern "C" s32 fn_125_DEDC(void* obj, s16* data, void* arg);

extern "C" void fn_125_DE4C(void* self, s16* src, void* arg) {
    u8* base = (u8*)self;
    WolfEntry* p = (WolfEntry*)(base + 0xC);
    s16 tmp[4];
    if (src[0] & 1) {
        if (p->isEnabled() == true && p->b6 == 0) {
            fn_125_DDFC(p, arg);
        }
    }
    fn_125_E53C(tmp, src);
    fn_125_DEDC(base + 4, tmp, arg);
}
