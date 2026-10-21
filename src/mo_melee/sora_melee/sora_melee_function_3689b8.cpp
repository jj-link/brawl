#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_91F78;
extern const float lbl_27_rodata_7B20;
}

class Target {
    char pad[0x3C];

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
    virtual int test();
};

struct Owner {
    char pad[8];
    Target* target;
};

struct Params {
    float pad0;
    float decrease;
    float pad8;
    float increase;
};

struct State {
    Owner* owner;
    Params* params;
    int counter;
    float value;
    float limit;
};

extern "C" void fn_27_3689B8(State* self) {
    if (lbl_27_data_91F78) {
        if (self->counter == 0) {
            Target* target = self->owner->target;
            if (target->test()) {
                if (self->value > lbl_27_rodata_7B20) {
                    self->value -= self->params->decrease;
                    if (self->value < lbl_27_rodata_7B20) {
                        self->value = lbl_27_rodata_7B20;
                    }
                }
            } else {
                if (self->value < self->limit) {
                    self->value += self->params->increase;
                    if (self->value > self->limit) {
                        self->value = self->limit;
                    }
                }
            }
        }
        self->counter = (self->counter + 1) % 60;
    }
}
