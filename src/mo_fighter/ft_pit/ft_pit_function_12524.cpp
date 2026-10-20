#pragma force_active on
typedef short s16;
typedef int s32;

extern "C" {
void fn_112_124D4(void* p, void* q);
s16* fn_112_125BC(s16* destination, const s16* source);
s32 fn_112_125B4(void* p, s16* q, void* r);
}

struct PitFlags {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char b6;
};

extern "C" void fn_112_12524(unsigned char* self, const s16* src, void* arg) {
    PitFlags* sub = reinterpret_cast<PitFlags*>(self + 0xC);
    if (src[0] & 1) {
        bool e = sub->flag;
        if (e == true && sub->b6 == 0) {
            fn_112_124D4(sub, arg);
        }
    }
    s16 tmp;
    fn_112_125BC(&tmp, src);
    fn_112_125B4(self + 4, &tmp, arg);
}
