#pragma force_active on
extern "C" {
void fn_91_D630(void*, int);
void fn_91_DAB8(short*, const short*);
void fn_91_D710(void*, short*, int);
}

struct FlagByte {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_91_D680(unsigned char* self, short* src, int arg)
{
    short buf[2];
    unsigned char* p = self + 0xc;
    if (src[0] & 1) {
        bool bit = reinterpret_cast<FlagByte*>(p + 5)->hi;
        if (bit == 1 && p[6] == 0) {
            fn_91_D630(p, arg);
        }
    }
    fn_91_DAB8(buf, src);
    fn_91_D710(self + 4, buf, arg);
}
