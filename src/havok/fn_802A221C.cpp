#pragma force_active on

class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

class Obj {
public:
    virtual void release(int flag);
    virtual void v1();
    char pad[8];
    Sub* m0C;
    Sub* m10;
};

extern "C" void fn_802A221C(Obj* self) {
    self->m0C->v6();
    if (self->m10) {
        self->m10->v6();
        self->m10 = 0;
    }
    if (self) {
        self->release(1);
    }
}
