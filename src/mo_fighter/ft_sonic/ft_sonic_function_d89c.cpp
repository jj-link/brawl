#pragma force_active on
extern "C" {
void fn_123_D538(void* a, void* b);
void fn_123_ED34(short* dst, const short* src);
int fn_123_D92C(void* a, short* b, void* c);
}

struct SonicFlags {
    unsigned char enabled : 1;
    unsigned char rest : 7;
};

extern "C" void fn_123_D89C(unsigned char* self, const short* src, void* arg) {
    short local[4];
    unsigned char* p = self + 0xC;
    if ((src[0] & 1) != 0) {
        SonicFlags* f = reinterpret_cast<SonicFlags*>(p + 5);
        bool e = f->enabled;
        if (e == true && p[6] == 0) {
            fn_123_D538(p, arg);
        }
    }
    fn_123_ED34(local, src);
    fn_123_D92C(self + 4, local, arg);
}
