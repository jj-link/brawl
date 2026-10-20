#pragma force_active on
extern "C" void fn_118_CB0C(unsigned char* self, int arg);
extern "C" void fn_118_D24C(short* dst, short* src);
extern "C" int fn_118_CBEC(unsigned char* self, short* src, int arg);

struct Flags {
    unsigned char pad[5];
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char rest : 6;
    unsigned char next;
};

extern "C" void fn_118_CB5C(unsigned char* self, short* src, int arg) {
    unsigned char* p = self + 0xC;
    if (src[0] & 1) {
        Flags* f = reinterpret_cast<Flags*>(p);
        bool flag = f->b7;
        if (flag == true && p[6] == 0) {
            fn_118_CB0C(p, arg);
        }
    }
    short tmp[4];
    fn_118_D24C(tmp, src);
    fn_118_CBEC(self + 0x4, tmp, arg);
}
