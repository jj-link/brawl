#pragma force_active on
extern "C" void fn_802E8B8C(void*, void*);
extern "C" void fn_802EE0F8(void*, void*, int);
extern "C" void fn_802F0668(void*);

struct Sub { int x; };
struct Obj0 {
    virtual void v0();
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
    virtual void v14();
    virtual void del(void*);
    int pad[2];
};
struct Obj : Obj0, Sub {
    void* p;
    void* arr[6];
};

extern "C" void fn_802E97AC(Obj* self) {
    if (self->p != 0) {
        fn_802EE0F8(self->p, self->arr, 6);
        for (int i = 0; i < 6; i++) {
            fn_802E8B8C(self->arr[i], (Sub*)self);
            fn_802F0668(self->arr[i]);
            self->arr[i] = 0;
        }
        self->del(self->p);
        self->p = 0;
    }
}
