#pragma force_active on
typedef unsigned char u8;

struct Parameters {
    float unused0;
    float speed;
    float unused8;
    float low;
    float high;
    float step;
    float upper;
    float lower;
    float value;
    char pad24[0x70 - 0x24];
    float scales[3];
};

struct Position {
    float x;
    float y;
    char pad8[0x20 - 8];
    u8 count;
};

struct StageBase {
    char pad0[0x3C];
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
    virtual Parameters* getParameters(int);
};

struct Stage : StageBase {
    char pad40[0x14C - 0x40];
    void* object;
    char pad150[8];
    Position* position;
    char pad15C[0x168 - 0x15C];
    float speed;
    float value;
    char pad170[8];
    u8 direction;
    char pad179[0x198 - 0x179];
    u8 scaleEnabled;
};

struct Input {
    float x, y;
};

struct GameMode {
    char pad[0xE];
    u8 flags;
};

struct Global {
    char pad[8];
    GameMode* mode;
};

extern "C" {
extern float lbl_74_rodata_D0;
extern float lbl_74_rodata_10C;
extern Global* g_GameGlobal;

void fn_27_26399C(void*);

void fn_74_4D8C(Stage* self, int index, const Input* input) {
    Parameters* param = self->getParameters(index);
    if (param == 0)
        return;

    float y = input->y;
    fn_27_26399C(self->object);

    float old;
    float delta = lbl_74_rodata_D0;
    if (delta == y)
        return;

    old = self->position->y;
    if (y < param->low) {
        if (self->direction == 1)
            delta += param->step;
        else
            delta -= param->step;
    } else if (y >= param->high) {
        if (self->direction == 1)
            delta += lbl_74_rodata_10C * param->step;
        else
            delta -= lbl_74_rodata_10C * param->step;
    }

    self->position->y = old + delta;

    if (self->direction == 1 && self->position->y > param->upper)
        self->direction = 0;

    if (self->direction == 0 && self->position->y < param->lower)
        self->direction = 1;

    self->value = param->value;
    self->position->count++;

    if (self->position->count >= 15)
        self->position->count = 14;

    self->speed = param->speed;

    if (self->scaleEnabled == 1) {
        GameMode* mode = g_GameGlobal->mode;
        if (mode) {
            switch ((int)((mode->flags >> 5) & 7)) {
            case 0:
                self->speed *= param->scales[0];
                break;
            case 1:
                self->speed *= param->scales[1];
                break;
            case 2:
                self->speed *= param->scales[2];
                break;
            }
        }
    }
}
}
