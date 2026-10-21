#pragma force_active on
typedef signed short s16;
typedef unsigned char u8;

struct WolfSub {
    u8 pad[5];
    u8 enabled : 1;
    u8 other : 7;
    u8 disabled;
};

extern "C" {
void fn_125_DEE4(void* obj, void* arg);
void fn_125_E53C(s16* dest, const s16* src);
int fn_125_DFC4(s16* dest, const s16* src, void* arg);
}

extern "C" void fn_125_DF34(u8* obj, const s16* src, void* arg) {
    s16 local[4];
    WolfSub* sub = reinterpret_cast<WolfSub*>(obj + 0xC);
    if (src[0] & 1) {
        bool flag = sub->enabled;
        if (flag == true && sub->disabled == 0) {
            fn_125_DEE4(sub, arg);
        }
    }
    fn_125_E53C(local, src);
    fn_125_DFC4(reinterpret_cast<s16*>(obj + 4), local, arg);
}
