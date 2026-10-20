#pragma force_active on
typedef short s16;

extern "C" void fn_97_E19C(void* p, void* q);
extern "C" void fn_97_E624(s16* dst, const s16* src);
extern "C" void fn_97_E27C(void* p, s16* q, void* r);

extern "C" void fn_97_E1EC(unsigned char* self, s16* src, void* arg) {
    unsigned char* sub = self + 0xC;
    if (src[0] & 1) {
        unsigned char bit = (sub[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && sub[6] == 0) {
            fn_97_E19C(sub, arg);
        }
    }
    s16 local[4];
    fn_97_E624(local, src);
    fn_97_E27C(self + 4, local, arg);
}
