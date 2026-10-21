#pragma force_active on
extern "C" {
void fn_120_C5C4(unsigned char* a, void* b);
short* fn_120_CC1C(short* destination, const short* source);
int fn_120_C6A4(unsigned char* a, short* b, void* c);
}

struct Flags5 {
    unsigned char hi : 1;
    unsigned char rest : 7;
};

extern "C" void fn_120_C614(unsigned char* a, const short* b, void* c) {
    unsigned char* sub = a + 0xC;
    if ((b[0] & 1) != 0) {
        Flags5* f = reinterpret_cast<Flags5*>(sub + 5);
        bool v = f->hi;
        if (v == true && sub[6] == 0) {
            fn_120_C5C4(sub, c);
        }
    }
    short local[4];
    fn_120_CC1C(local, b);
    fn_120_C6A4(a + 4, local, c);
}
