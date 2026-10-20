#pragma force_active on
typedef short s16;
typedef int s32;

extern "C" void fn_115_18374(unsigned char* obj, void* arg);
extern "C" void fn_115_186D4(s16* dst, const s16* src);
extern "C" s32 fn_115_18454(unsigned char* obj, s16* src, void* arg);

extern "C" void fn_115_183C4(unsigned char* self, const s16* src, void* arg) {
    unsigned char* sub = self + 0xc;
    s16 local;
    if (src[0] & 1) {
        unsigned char bit = (sub[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && sub[6] == 0) {
            fn_115_18374(sub, arg);
        }
    }
    fn_115_186D4(&local, src);
    fn_115_18454(self + 4, &local, arg);
}
