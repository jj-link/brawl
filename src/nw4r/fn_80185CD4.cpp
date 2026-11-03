#include <types.h>
#pragma force_active on

struct Rect {
    float x1, x2, y1, y2;
};

struct Input {
    int unk0;
    int first;
    char pad[0x14];
    int second;
};

struct Pair {
    int a;
    int b;
};

extern "C" Rect fn_80187BB4(void*, int mode, Input* input);
extern "C" Pair fn_8018352C(void*, int, int, int);

class Class_8046585C {
public:
    virtual void fn_801858D0();
    virtual void fn_80187CEC();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_80185CD4();
    virtual void fn_80183024();
    virtual void fn_80185E14();
    virtual void fn_80185C4C();
    virtual void fn_80185C78();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_80185CA4();
    virtual void fn_80185CBC();
    virtual void fn_80182B40();
    virtual void fn_80185A18();
    virtual void fn_80183164();
    virtual void fn_80183180();
    virtual void fn_80183210();
    virtual void fn_80185EA4();
    virtual void fn_80185B14();
    virtual void fn_80185BB8();
    virtual void fn_80183618();
    virtual void fn_8018342C();
    virtual void fn_80187CDC();
    virtual void fn_80187CB4();
    virtual void fn_80185F34(Pair* p, Rect* r, u8 b);
    virtual void fn_80186048(Pair* p, Input* in, Rect* r, u8 b);
    virtual void fn_80186628(Pair* p, Input* in, Rect* r, u8 b);
    virtual void fn_80186D6C(Pair* p, Input* in, Rect* r, u8 b);

    char pad4[0xb5 - 4];
    u8 unkB5;
    char padB6[0xfc - 0xb6];
    Input* unkFC;
    u8 unk100;
};

extern "C" void fn_80185CD4(Class_8046585C* self) {
    self->fn_8018342C();
    Rect s = fn_80187BB4(self, self->unk100, self->unkFC);
    Pair q;
    Pair p = fn_8018352C(self, *(int*)&s.y1, *(int*)&s.x2, *(int*)&s.x1);
    q = p;
    self->fn_80185F34(&q, &s, self->unkB5);
    switch (self->unk100) {
    case 1:
        self->fn_80186048(&q, self->unkFC, &s, self->unkB5);
        break;
    case 4:
        self->fn_80186628(&q, self->unkFC, &s, self->unkB5);
        break;
    case 8:
        self->fn_80186D6C(&q, self->unkFC, &s, self->unkB5);
        break;
    }
}
