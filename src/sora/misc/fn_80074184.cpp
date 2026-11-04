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
    virtual void fn_801B26E4();
    virtual void fn_801AAFDC();
    virtual int fn_801AAFE8();
};
struct Object {
    char pad[0x6e0];
    Class_8042B6D0* child;
    char pad2[8];
    unsigned char flag;
};
extern "C" int fn_80074184(Object* self) {
    if (self->flag == 0) return 1;
    int result = 0;
    if (self->child != 0 && self->child->fn_801AAFE8() != 0) {
        result = 1;
    }
    return result;
}