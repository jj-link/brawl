#pragma force_active on
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual void fn_8004781C();
    virtual void fn_80046A28();
    virtual void fn_8004810C();
    virtual void fn_800480DC();
    virtual void fn_801AB1C4();
    virtual void fn_801B269C();
    virtual void fn_801B26E4(int);
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AB290();
    virtual void fn_801B2EEC();
    virtual void fn_801B3050(int, float);
};
struct Owner {
    char pad[0x6e0];
    Class_8042B6D0* obj;
    char pad2[8];
    unsigned char flag1;
    char pad3[2];
    unsigned char flag2;
    char pad4[0x10];
    float a;
    float b;
    float c;
    char pad5[8];
    float d;
};
extern "C" void fn_800741EC(Owner* self, int unused, int arg) {
    if (self->flag2 && self->flag1) {
        if (self->obj) self->obj->fn_8004810C();
        if (self->obj) self->obj->fn_801B26E4(arg);
        float value = self->b * (self->d * (self->a * self->c));
        if (self->obj) self->obj->fn_801B3050(0, value);
    }
}