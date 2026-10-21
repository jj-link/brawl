#pragma force_active on
typedef signed short s16;
typedef int s32;

extern "C" {
void fn_123_D13C(void* self, void* arg);
void fn_123_ED34(s16* destination, const s16* source);
void fn_123_D530(void* self, s16* data, void* arg);
}

struct Sonic12 {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char disabled;
};

extern "C" void fn_123_D4A0(unsigned char* self, const s16* src, void* arg) {
    s16 local[4];
    Sonic12* p = reinterpret_cast<Sonic12*>(self + 0xC);
    if (src[0] & 1) {
        bool on = p->flag;
        if (on == true && p->disabled == 0) {
            fn_123_D13C(p, arg);
        }
    }
    fn_123_ED34(local, src);
    fn_123_D530(self + 4, local, arg);
}
