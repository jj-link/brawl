#pragma force_active on

class FirstObj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};

class SecondObj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void* arg, float f1, float f2);
};

struct Context {
    char pad[0xC];
    FirstObj* first;
    SecondObj* second;
};

extern "C" {
void fn_802A2304(Context* self, void* arg, float f1, float f2) {
    self->first->v11();
    if (self->second != 0) {
        self->second->v11(arg, f1, f2);
    }
}
}
