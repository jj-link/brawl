#pragma force_active on
typedef unsigned int u32;

struct Word7C {
    u32 top : 8;
    u32 low : 24;
};

struct Word38 {
    u32 hi : 29;
    u32 f : 1;
    u32 lo : 2;
};

extern "C" void fn_27_2EEC4(unsigned char* self, u32 a, u32 b) {
    if (a == 1) {
        Word7C* inner = (Word7C*)(*(unsigned char**)(self + 4) + 0x7c);
        inner->top = 0;
    } else {
        u32 one = 1;
        Word7C* inner = (Word7C*)(*(unsigned char**)(self + 4) + 0x7c);
        inner->top = one;
    }
    if (b == 1) {
        ((Word38*)(self + 0x38))->f = a;
    }
}
