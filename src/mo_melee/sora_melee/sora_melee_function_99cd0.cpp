#pragma force_active on

struct Item {
    int a;
    int b;
};

class Obj {
public:
    virtual void v0();
    virtual Item* v1(int i);
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

class Owner {
public:
    char pad[0x5C];
    Obj* m_obj;
};

extern "C" void fn_27_9FBD8(Item* work);

extern "C" void fn_27_99CD0(Owner* self) {
    int count = self->m_obj->v3();
    for (int i = 0; i < count; i++) {
        if (self->m_obj->v1(i)->b > 0) {
            fn_27_9FBD8(self->m_obj->v1(i));
        }
    }
    self->m_obj->v8();
}
