#pragma force_active on
struct PikachuPoolFlag {
    short value;
};

extern "C" {
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void fn_98_DA34(void*, void*);
void fn_98_DCC8(void*, PikachuPoolFlag*, void*);
}

extern "C" void fn_98_DC38(char* self, PikachuPoolFlag* flags, void* accesser) {
    unsigned char* sub = reinterpret_cast<unsigned char*>(self + 0xc);
    if (flags->value & 4) {
        unsigned char bit = (sub[5] >> 7) & 1;
        bool flag = bit;
        if (flag == true && sub[6] == 0) {
            fn_98_DA34(sub, accesser);
        }
    }
    PikachuPoolFlag local;
    fn_98_E208(&local, *flags);
    fn_98_DCC8(self + 4, &local, accesser);
}
