#pragma force_active on

typedef signed short s16;
typedef unsigned char u8;

struct State {
    u8 pad0[0x1C];
    int current;
    u8 pad20[0x1C];
    int saved;
};

class Inner {
public:
    virtual void unused();
    virtual State* get();
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
    virtual void work(int);

    u8 pad4[0x88];
    Inner* inner;
    u8 pad90[0xD5];
    u8 upper : 4;
    u8 mode : 2;
    u8 lower : 2;
};

extern "C" {
extern const float lbl_27_rodata_344;

void fn_27_1B614(Owner*, int, int, int, s16*, int, float);

void fn_27_16FB4(Owner* self, int arg) {
    struct Key {
        s16 value;
        s16 pad;
    };

    Key b;
    Key a;
    State* state = self->inner->get();
    int current = state->current;

    if (current != -1) {
        if (state->saved == -1) {
            state->saved = current;
            state->current = -1;

            a.value = 0x20;
            fn_27_1B614(self, arg, -1, 1, &a.value, 0,
                        lbl_27_rodata_344);

            b.value = 0x80;
            fn_27_1B614(self, arg, -1, 0, &b.value, 0,
                        lbl_27_rodata_344);

            self->mode = 1;
        } else {
            self->work(arg);
        }
    }
}
}
