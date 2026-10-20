#pragma force_active on
struct PikachuPoolFlag {
    short flags;
    char pad[6];
};

struct PikachuPoolByte {
    unsigned char high : 1;
    unsigned char low : 7;
};

extern "C" {
void fn_98_DF6C(unsigned char*, void*);
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
int fn_98_E200(unsigned char*, PikachuPoolFlag*, void*);
}

extern "C" void fn_98_E170(unsigned char* self, const PikachuPoolFlag* flags, void* accesser) {
    unsigned char* sub = self + 0xc;
    if (flags->flags & 4) {
        PikachuPoolByte* b = reinterpret_cast<PikachuPoolByte*>(sub + 5);
        bool bit = b->high;
        if (bit == true && sub[6] == 0) {
            fn_98_DF6C(sub, accesser);
        }
    }
    PikachuPoolFlag local;
    fn_98_E208(&local, *flags);
    fn_98_E200(self + 4, &local, accesser);
}
