#pragma force_active on
struct Obj {
    int pad0;
    int pad4;
    int field8;
};

class Base {
public:
    virtual void v0();
    virtual void v3(Obj* obj);
    virtual void v4();
};

extern "C" void fn_20_2E5C(Base* self, Obj* obj) {
    if (obj->field8 != 0) {
        self->v4();
        self->v3(obj);
    }
}
