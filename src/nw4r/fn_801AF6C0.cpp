#pragma force_active on

class Class_80466388 {
public:
    virtual void fn_801AFEB4();
    virtual void fn_801AE668(int, int, void*);
};

class Owner {
public:
    char pad[0x124];
    Class_80466388* slot124;
    Class_80466388* slot128;
    Class_80466388* slot12C;
    Class_80466388* slot130;
    Class_80466388* slot134;
};

extern "C" int fn_801AF6C0(Owner* self, Class_80466388* arg1) {
    if (arg1 == 0) {
        return 0;
    }
    if (arg1 == self->slot124) {
        self->slot124->fn_801AE668(0x10003, 0, self);
        self->slot124 = 0;
        return 1;
    }
    if (arg1 == self->slot128) {
        self->slot128->fn_801AE668(0x10003, 0, self);
        self->slot128 = 0;
        return 1;
    }
    if (arg1 == self->slot12C) {
        self->slot12C->fn_801AE668(0x10003, 0, self);
        self->slot12C = 0;
        return 1;
    }
    if (arg1 == self->slot130) {
        self->slot130->fn_801AE668(0x10003, 0, self);
        self->slot130 = 0;
        return 1;
    }
    if (arg1 == self->slot134) {
        self->slot134->fn_801AE668(0x10003, 0, self);
        self->slot134 = 0;
        return 1;
    }
    return 0;
}
