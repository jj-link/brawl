#pragma force_active on
extern "C" {
extern void fn_801AAC18(void*, int);
extern char lbl_80466380[];

struct Base {
    virtual void v0(int);  // 0x8
    virtual void v1();     // 0xc
    virtual void v2();     // 0x10
    virtual void v3();     // 0x14
    virtual void v4();     // 0x18
    virtual void v5();     // 0x1c
    virtual void v6();     // 0x20
    virtual void v7();     // 0x24
    virtual void v8();     // 0x28
    virtual void v9();     // 0x2c
    virtual void v10();    // 0x30
    virtual void v11();    // 0x34
    virtual void fn38(int); // 0x38
};

struct Obj : Base {
    char pad[0x11C - 4];
    Base* sub;
    char pad2[0x124 - 0x11C - 4];
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
};

void* fn_801AFD90(Obj* arg0) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80466380;
        switch (*(char*)((char*)arg0 + 0x121)) {
        case 1:
            Base* sub = arg0->sub;
            if (sub != 0) {
                sub->v0(1);
            }
            break;
        }
        if (arg0->f1 != 0) {
            arg0->fn38(arg0->f1);
        }
        if (arg0->f2 != 0) {
            arg0->fn38(arg0->f2);
        }
        if (arg0->f3 != 0) {
            arg0->fn38(arg0->f3);
        }
        if (arg0->f4 != 0) {
            arg0->fn38(arg0->f4);
        }
        if (arg0->f5 != 0) {
            arg0->fn38(arg0->f5);
        }
        if (arg0 != 0) {
            fn_801AAC18(arg0, 0);
        }
    }
    return arg0;
}
}
