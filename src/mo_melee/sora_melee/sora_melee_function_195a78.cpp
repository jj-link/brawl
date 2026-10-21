#pragma force_active on

typedef int s32;

#define VF(n) virtual s32 f##n();

struct Base {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
    VF(10) VF(11) VF(12) VF(13) VF(14) VF(15)
    virtual s32 f16(s32);
    VF(17)
    virtual s32 f18(s32);
};

struct Padding {
    char pad[0x3c];
};

struct X : Padding {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
    VF(10) VF(11) VF(12) VF(13) VF(14) VF(15) VF(16) VF(17) VF(18) VF(19)
    VF(20) VF(21) VF(22) VF(23) VF(24) VF(25) VF(26) VF(27) VF(28) VF(29)
    VF(30) VF(31) VF(32) VF(33) VF(34) VF(35) VF(36) VF(37) VF(38) VF(39)
    VF(40)
};

struct Mid {
    char pad[0xa8];
    Base* base;
};

struct Self {
    char pad0[8];
    X* x;
    char pad1[0xd8 - 0xc];
    Mid* mid;
};

extern "C" s32 fn_27_195A78(Self* __restrict self) {
    switch (self->mid->base->f18(0)) {
    case 3:
    case 4:
    case 6:
        if (self->mid->base->f16(0) != 0x34) {
            return 0x2d;
        }
        break;

    case 5:
        switch (self->x->f40()) {
        case 0x20:
            return 0x2d;
        }
        break;
    }

    return -1;
}
