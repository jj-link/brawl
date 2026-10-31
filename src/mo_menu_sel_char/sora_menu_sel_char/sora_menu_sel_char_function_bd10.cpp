#pragma force_active on
struct Obj {
    virtual Obj* f0();
    virtual Obj* f1();
    virtual Obj* f2();
    virtual Obj* f3();
    virtual Obj* f4();
    virtual Obj* f5();
};
struct Ctx {
    char pad[8];
    Obj* field;
};
extern "C" Obj* fn_10_BD10(Ctx* self) {
    Obj* obj = self->field;
    if (obj == 0)
        return obj;
    return obj->f5();
}