#pragma force_active on
struct Helper {
    virtual void v1();
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
    virtual void v15(void* arg);
};

struct Elem {
    char pad[0x10];
    void* val;
};

struct Owner {
    char pad[0xac];
    Helper* helper;
    Elem* items[1];
};

extern "C" {
void fn_10_145F0(Owner* self, int idx) {
    self->helper->v15(self->items[idx]->val);
}
}
