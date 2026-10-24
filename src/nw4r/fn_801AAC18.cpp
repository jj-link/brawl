#pragma force_active on
extern "C" {
extern void fn_8019D88C(void* p, int flag);
extern char lbl_804662B0[];

struct Child {
    virtual void m0(int);
    virtual void m1();
};

struct Obj {
    void* vtbl;
    unsigned char pad[0xd0];
    Child* child;
    char unkD8;
    char flag;
};

void* fn_801AAC18(Obj* arg0) {
    if (arg0 != 0) {
        Child* child = arg0->child;
        arg0->vtbl = lbl_804662B0;
        if (child != 0) {
            switch (arg0->flag) {
            case 1:
                if (child != 0) {
                    child->m0(1);
                }
                break;
            default:
                break;
            }
        }
        fn_8019D88C(arg0, 0);
    }
    return arg0;
}
}
