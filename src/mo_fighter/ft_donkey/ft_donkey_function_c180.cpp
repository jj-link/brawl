#pragma force_active on
typedef short s16;
typedef int s32;

extern "C" {
void fn_92_C130(void* a, void* b);
void fn_92_C870(s16* destination, const s16* source);
s32 fn_92_C210(void* a, s16* b, void* c);
}

extern "C" void fn_92_C180(unsigned char* self, const s16* src, void* arg) {
    unsigned char* sub = self + 0xC;
    if ((*src & 1) != 0) {
        unsigned char bit = (sub[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && sub[6] == 0) {
            fn_92_C130(sub, arg);
        }
    }
    s16 tmp[4];
    fn_92_C870(tmp, src);
    fn_92_C210(self + 4, tmp, arg);
}
