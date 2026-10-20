#pragma force_active on
struct PikachuPoolFlag {
    short flag;
    char pad[0x6];
};

struct PikachuPoolBits {
    unsigned char pad[5];
    unsigned char hi : 1;
    unsigned char rest : 7;
    unsigned char after;
};

extern "C" {
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void fn_98_CD2C(void*, void*);
void fn_98_CFC0(void*, PikachuPoolFlag*, void*);
}

extern "C" void fn_98_CF30(char* self, PikachuPoolFlag* energy, void* accesser) {
    PikachuPoolBits* bits = reinterpret_cast<PikachuPoolBits*>(self + 0xc);
    if (energy->flag & 1) {
        bool b = bits->hi;
        if (b == true && bits->after == 0) {
            fn_98_CD2C(bits, accesser);
        }
    }
    PikachuPoolFlag local;
    fn_98_E208(&local, *energy);
    fn_98_CFC0(self + 4, &local, accesser);
}
