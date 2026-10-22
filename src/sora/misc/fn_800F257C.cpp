#pragma force_active on

struct Object {
    unsigned char pad[0x60];
    int state;
};

typedef int (*StateFn)(Object*);

struct StateTable {
    StateFn func0;
    StateFn func1;
};

extern "C" void fn_800F261C(Object* self);
extern "C" void fn_800F2498(Object* self);
extern "C" struct StateTable lbl_80408C70[];

extern "C" void fn_800F257C(Object* self) {
    int orig = self->state;
    fn_800F261C(self);

    StateFn f1 = lbl_80408C70[self->state].func1;
    if (f1) {
        self->state = f1(self);
    }

    if (self->state != orig) {
        StateFn f0 = lbl_80408C70[self->state].func0;
        if (f0) {
            f0(self);
        }
    }

    fn_800F2498(self);
}
