#pragma force_active on
typedef short s16;
typedef int s32;

extern "C" {
void fn_115_D294(void* obj, void* arg);
void fn_115_D71C(s16* destination, const s16* source);
s32 fn_115_D374(void* obj, s16* src, void* arg);
}

extern "C" void fn_115_D2E4(unsigned char* self, const s16* param, void* arg) {
    unsigned char* sub = self + 0xC;
    s16 tmp[4];

    if ((*param & 1) != 0) {
        unsigned char bit = (sub[5] >> 7) & 1;
        unsigned int flag = bit != 0;
        if (flag == 1 && sub[6] == 0) {
            fn_115_D294(sub, arg);
        }
    }

    fn_115_D71C(tmp, param);
    fn_115_D374(self + 4, tmp, arg);
}
