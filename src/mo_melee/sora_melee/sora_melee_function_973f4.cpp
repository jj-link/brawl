#pragma force_active on
class ObjA {
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
    virtual void v12();
    virtual void v13();
};

class ObjB {
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
    virtual void v12();
    virtual void v13(void* arg);
};

struct Owner {
    char pad[0x30];
    ObjA* m30;
    char pad2[4];
    ObjB* m38;
};

extern "C" {
void fn_27_973F4(Owner* self, void* arg) {
    self->m30->v13();
    if (self->m38 != 0) {
        self->m38->v13(arg);
    }
}
}
