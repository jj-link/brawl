#pragma force_active on
extern "C" void* fn_14_3EC();
extern "C" void fn_16_AF8(void*);
extern "C" int fn_8014B864(int);
extern int lbl_805A0434;

class Obj {
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
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v14(int);
    virtual void v15(int);
};

extern "C" int fn_14_7CB4(void* self) {
    unsigned char* p = (unsigned char*)self;
    int r;
    if (p[0x40] == 0) {
        fn_14_3EC();
        r = fn_8014B864(lbl_805A0434);
    } else {
        r = 1;
    }
    if (r != 0 && *(int*)(p + 0x2b0) != 7) {
        Obj* o = *(Obj**)(p + 0x204);
        o->v15(*(int*)(p + 0x1e4));
        if (*(int*)(p + 0x2570) != 0) {
            fn_16_AF8(p + 0x2570);
        }
        Obj* n = *(Obj**)(p + 0x1fc);
        int c;
        while ((c = *(int*)((char*)n + 0xe4)) != 0) {
            if (c != 0) {
                n->v14(c - 1);
            }
        }
        return 2;
    }
    return *(int*)(p + 0x24c4);
}
