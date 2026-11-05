#pragma force_active on
#include <types.h>

typedef signed short s16;
typedef unsigned char u8;

struct soAnimChr {
    char pad0[0x1C];
    int m1c;
    char pad20[0x1C];
    int m3c;
    char pad40[4];
};

extern "C" void reset__9soAnimChrFv(soAnimChr*);

struct Arr {
    virtual void unused();
    virtual soAnimChr* get();
};

struct P8 { char p[8]; };
struct Res : P8 {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

struct Ke {
    char pad[4];
    Res* r;
};

struct Mid {
    char pad[0xD8];
    Ke* k;
};

class Owner {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void work(int, int);

    char pad4[0x88];
    Arr* arr;
    char pad90[0x165 - 0x90];
    u8 upper : 4;
    u8 mode : 2;
    u8 lower : 2;
    char pad166[0x168 - 0x166];
    Mid* mid;
};

extern "C" {
extern const float lbl_27_rodata_344;

void fn_27_1B614(Owner*, int, int, int, s16*, int, float);

void fn_27_16E88(Owner* self, int arg) {
    struct Key {
        s16 value;
        s16 pad;
    };

    Key b;
    Key a;
    soAnimChr* state = self->arr->get();

    if (state->m1c != -1 || state->m3c != -1) {
        self->work(arg, 1);
        reset__9soAnimChrFv(state);
        state->m1c = -1;
        reset__9soAnimChrFv((soAnimChr*)((char*)state + 0x20));
        state->m3c = -1;
        self->mid->k->r->v8();

        a.value = 0x20;
        fn_27_1B614(self, arg, -1, 1, &a.value, 0, lbl_27_rodata_344);

        b.value = 0x80;
        fn_27_1B614(self, arg, -1, 0, &b.value, 0, lbl_27_rodata_344);

        self->mode = 1;
    }
}
}
