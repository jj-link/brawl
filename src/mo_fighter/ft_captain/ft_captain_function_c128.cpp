#pragma force_active on
extern "C" {
void fn_100_CD4C(unsigned char* self, void* arg);
void fn_100_C648(short* destination, const short* source);
void fn_100_C1B8(unsigned char* self, short* data, void* arg);
}

struct CaptainFlaggedSub {
    unsigned char pad[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char zero;
};

extern "C" void fn_100_C128(unsigned char* self, short* arg, void* p) {
    short tmp[4];
    CaptainFlaggedSub* sub = reinterpret_cast<CaptainFlaggedSub*>(self + 0xC);
    if (arg[0] & 1) {
        bool on = sub->enabled;
        if (on == true && sub->zero == 0) {
            fn_100_CD4C(self + 0xC, p);
        }
    }
    fn_100_C648(tmp, arg);
    fn_100_C1B8(self + 4, tmp, p);
}
