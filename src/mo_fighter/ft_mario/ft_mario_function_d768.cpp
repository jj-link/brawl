#pragma force_active on
extern "C" void fn_91_D718(void* a, void* b);
extern "C" void fn_91_DAB8(short* dst, const short* src);
extern "C" void fn_91_D7F8(void* a, short* b, void* c);

struct Flags5 {
    unsigned char f : 1;
    unsigned char rest : 7;
};

extern "C" void fn_91_D768(unsigned char* object, short* src, void* arg) {
    short tmp[4];
    unsigned char* p = object + 0xc;
    if (src[0] & 2) {
        Flags5* fl = reinterpret_cast<Flags5*>(p + 5);
        bool flag = (bool)fl->f;
        if (flag == 1 && p[6] == 0) {
            fn_91_D718(p, arg);
        }
    }
    fn_91_DAB8(tmp, src);
    fn_91_D7F8(object + 4, tmp, arg);
}
