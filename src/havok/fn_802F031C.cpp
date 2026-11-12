#pragma force_active on

extern "C" {
extern char lbl_804883B8[];
extern float lbl_805A4488;
extern float lbl_805A44A0;

struct Flag { int m_finishing; };

struct Obj {
    char* ptr;
    unsigned short size;
    unsigned short flag;
    unsigned char pad2[0x1C];
    float f;
};

static inline void baseCtor(Obj* self, Flag f) { self->flag = 1; }

void fn_802F031C(Obj* self, Flag fl) {
    baseCtor(self, fl);
    self->ptr = lbl_804883B8;
    if (fl.m_finishing != 0 && lbl_805A4488 == self->f) {
        self->f = lbl_805A44A0;
    }
}
}
