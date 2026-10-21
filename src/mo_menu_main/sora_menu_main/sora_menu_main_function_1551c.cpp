#pragma force_active on
typedef unsigned int u32;

struct Mgr {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(void*);
};

struct Elem {
    char pad[0x10];
    void* v;
};

struct Holder {
    char pad[0x3c];
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
};

struct Owner {
    char pad0[0x64c];
    Elem** arr;
    char pad1[4];
    Mgr* mgr;
    char pad2[0x14];
    Holder* holder;
};

extern "C" void fn_2_1551C(Owner* self) {
    for (u32 i = 0; i < 6; i++) {
        self->mgr->vf13(self->arr[i]->v);
    }
    if (self->holder) {
        self->holder->h23();
        self->holder = 0;
    }
}
