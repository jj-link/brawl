#pragma force_active on
typedef signed short s16;
typedef signed int s32;

extern "C" void fn_120_C6AC(void* obj, void* arg);
extern "C" s16* fn_120_CC1C(s16* destination, const s16* source);
extern "C" s32 fn_120_C78C(void* obj, s16* data, void* arg);

extern "C" void fn_120_C6FC(void* robot, const s16* src, void* arg) {
    unsigned char* p = (unsigned char*)robot + 0xC;
    s16 tmp[4];
    if (src[0] & 1) {
        unsigned char bit = (p[5] >> 7) & 1;
        if ((bool)bit == true && p[6] == 0) {
            fn_120_C6AC(p, arg);
        }
    }
    fn_120_CC1C(tmp, src);
    fn_120_C78C((unsigned char*)robot + 4, tmp, arg);
}
