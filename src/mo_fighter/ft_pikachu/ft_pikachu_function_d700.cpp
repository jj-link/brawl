#pragma force_active on
struct PikachuPoolFlag {
    short value;
};

struct PikachuSubState {
    char pad[5];
    unsigned char hi : 1;
    unsigned char lo : 7;
    unsigned char guard;
};

extern "C" {
void fn_98_D4FC(void*, void*);
PikachuPoolFlag* fn_98_E208(PikachuPoolFlag*, const PikachuPoolFlag&);
void* fn_98_D790(void*, PikachuPoolFlag*, void*);
}

extern "C" void fn_98_D700(char* self, const PikachuPoolFlag* flags, void* accesser) {
    PikachuSubState* sub = reinterpret_cast<PikachuSubState*>(self + 0xc);
    if (flags->value & 1) {
        bool hi = sub->hi;
        if (hi == 1 && sub->guard == 0) {
            fn_98_D4FC(sub, accesser);
        }
    }
    PikachuPoolFlag local;
    fn_98_E208(&local, *flags);
    fn_98_D790(self + 4, &local, accesser);
}
