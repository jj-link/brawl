#pragma force_active on
extern "C" void fn_118_CDC4(unsigned char* obj, void* arg);
extern "C" void fn_118_D24C(short* dst, short* src);
extern "C" void fn_118_CEA4(unsigned char* obj, short* buf, void* arg);

struct Bits5 {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_118_CE14(unsigned char* self, short* flag, void* arg) {
    unsigned char* sub = self + 0xc;
    short buf[4];
    if (*flag & 1) {
        Bits5* b = reinterpret_cast<Bits5*>(sub + 5);
        bool hi = b->hi;
        if (hi == 1 && sub[6] == 0) {
            fn_118_CDC4(sub, arg);
        }
    }
    fn_118_D24C(buf, flag);
    fn_118_CEA4(self + 4, buf, arg);
}
