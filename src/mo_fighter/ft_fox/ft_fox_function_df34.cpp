#pragma force_active on
typedef signed short s16;
typedef signed int s32;

extern "C" void fn_97_DEE4(void* p, s32 a);
extern "C" void fn_97_E624(s16* d, const s16* s);
extern "C" void fn_97_DFC4(void* p, s16* d, s32 a);

struct Sub {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char next;
};

extern "C" void fn_97_DF34(unsigned char* self, s16* src, s32 arg) {
    s16 buf[4];
    Sub* sub = reinterpret_cast<Sub*>(self + 0xC);
    if (src[0] & 1) {
        bool f = sub->flag;
        if (f == true && sub->next == 0) {
            fn_97_DEE4(sub, arg);
        }
    }
    fn_97_E624(buf, src);
    fn_97_DFC4(self + 4, buf, arg);
}
