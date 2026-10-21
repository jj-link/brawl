#pragma force_active on
extern "C" void fn_91_D9D0(void*, void*);
extern "C" void fn_91_DAB8(short*, const short*);
extern "C" void fn_91_DAB0(void*, short*, void*);

struct Flags5 {
    unsigned char f : 1;
    unsigned char rest : 7;
};

extern "C" void fn_91_DA20(unsigned char* object, short* src, void* arg) {
    short tmp[4];
    unsigned char* p = object + 0xc;
    if (src[0] & 4) {
        Flags5* fl = reinterpret_cast<Flags5*>(p + 5);
        bool flag = (bool)fl->f;
        if (flag == 1 && p[6] == 0) {
            fn_91_D9D0(p, arg);
        }
    }
    fn_91_DAB8(tmp, src);
    fn_91_DAB0(object + 4, tmp, arg);
}
