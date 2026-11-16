#pragma force_active on
extern "C" {
extern void fn_8019D88C(void* p, int flag);
extern char lbl_80466270[];
extern char lbl_804662B0[];

class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
};

class Class_80466278 {
public:
    virtual void fn_801AC270();
    virtual void fn_801AB9D8();
    virtual void fn_801AC1AC();
    virtual void fn_801AC328();
    virtual void fn_801AC2F8();
    virtual void fn_801AB788();
    virtual void fn_801AAC9C();
    virtual void fn_801AAE34();
    virtual void fn_801AAFDC();
    virtual void fn_801AAFE8();
    virtual void fn_801AAA70();
    virtual void fn_801ABE70();
    virtual void fn_801ABFFC(int);
    char pad[0xd4 - 4];
    Object_vptr_0* child;
    char padD8;
    char flag;
    char padDA[0xe4 - 0xda];
    int count;
};

inline void cleanup(Class_80466278* arg0) {
    if (arg0 != 0) {
        Object_vptr_0* child = arg0->child;
        *(void**)arg0 = lbl_804662B0;
        if (child != 0) {
            switch (arg0->flag) {
            case 1:
                if (child != 0) {
                    child->slot0(1);
                }
                break;
            default:
                break;
            }
        }
        fn_8019D88C(arg0, 0);
    }
}

inline void removeLast(Class_80466278* arg0, int count) {
    if (count != 0) {
        arg0->fn_801ABFFC(count - 1);
    }
}

void* fn_801AC1AC(Class_80466278* arg0) {
    if (arg0 != 0) {
        *(void**)arg0 = lbl_80466270;
        while (arg0->count != 0) {
            removeLast(arg0, arg0->count);
        }
        cleanup(arg0);
    }
    return arg0;
}
}
