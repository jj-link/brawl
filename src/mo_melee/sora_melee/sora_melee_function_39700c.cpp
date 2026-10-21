#pragma force_active on

typedef unsigned int u32;

class Component {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(u32, u32);
    virtual u32 v10(u32);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(u32);
};

struct Manager {
    unsigned char pad0[0x3C];
    Component* action;
    unsigned char pad40[0x14];
    Component* state;
    unsigned char pad58[0x0C];
    Component* check;
};

struct Object {
    unsigned char pad0[0xD8];
    Manager* manager;
};

extern "C" void fn_27_39700C(void*, Object* self) {
    if (self->manager->check->v17(0x22000016) == 0) {
        if (self->manager->state->v10(0) == 1U) {
            self->manager->action->v9(0, 1);
        }
    }
}
