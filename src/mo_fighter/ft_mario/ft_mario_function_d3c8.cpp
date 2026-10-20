#pragma force_active on
extern "C" {
void fn_91_D378(void* self, int arg);
void fn_91_DAB8(short* destination, const short* source);
void fn_91_D458(void* self, short* data, int arg);
}

struct FlagByte {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_91_D3C8(unsigned char* self, short* src, int arg)
{
    short buf[2];
    unsigned char* p = self + 0xc;
    if (src[0] & 1) {
        bool bit = reinterpret_cast<FlagByte*>(p + 5)->hi;
        if (bit == 1 && p[6] == 0) {
            fn_91_D378(p, arg);
        }
    }
    fn_91_DAB8(buf, src);
    fn_91_D458(self + 4, buf, arg);
}
