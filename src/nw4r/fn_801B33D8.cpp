#pragma force_active on
extern "C" {
extern char lbl_804663C8[];
extern void fn_801AFD90(void* arg0, int flag);

struct Obj33D8 {
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
    virtual void fn38(int);
    char pad[0x138 - 4];
    int m138;
};

void* fn_801B33D8(Obj33D8* arg0) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_804663C8;
        if (arg0->m138 != 0) {
            arg0->fn38(arg0->m138);
        }
        fn_801AFD90(arg0, 0);
    }
    return arg0;
}
}
