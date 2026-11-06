#pragma force_active on

#include <types.h>

extern "C" {
void fn_8019C668(void*, void*);
void** fn_801B5DC0(void**, void*);
void** fn_801A7550(void**, void*);
}

extern int lbl_8059E908;
extern int lbl_8059E90C;

class Class_8046585C {
public:
    virtual void fn_801858D0();
    virtual void fn_80187CEC();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_80185CD4();
    virtual void fn_80183024();
    virtual void fn_80185E14();
    virtual void fn_80185C4C();
    virtual void fn_80185C78();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_80185CA4();
    virtual void fn_80185CBC();
    virtual void fn_80182B40();
    virtual void fn_80185A18();
    virtual void fn_80183164();
    virtual void fn_80183180();
    virtual void fn_80183210();
    virtual int fn_80185EA4();
    virtual void fn_80185B14();
    virtual void fn_80185BB8();
    virtual int fn_80183618();
    virtual int fn_8018342C();
    virtual void fn_80187CDC();
    virtual void fn_80187CB4();
    virtual void fn_80185F34();
    virtual void fn_80186048(void**, int);
    virtual void fn_80186628(void**, int);
};

struct Owner {
    char pad0[0xF8];
    char elems1[0x20 * 0x10C];
    char elems2[0x20 * 0x30];
    char pad3[0x10];
    Class_8046585C* obj;
};

extern "C" void fn_801AC9E0(Owner* arg0) {
    if (arg0->obj != 0) {
        int n1;
        int n2;
        void* sp14;
        void* sp10;
        void* spC;
        void* sp8;
        char* elem;
        int unk50 = arg0->obj->fn_80185EA4();

        n1 = arg0->obj->fn_80183618();
        n2 = arg0->obj->fn_8018342C();

        if (unk50 != 0) {
            fn_8019C668(arg0->obj, (char*)arg0 + 0x2878);
        }

        if (n1 != 0) {
            int* p = (u32)n1 < (u32)lbl_8059E908 ? &n1 : &lbl_8059E908;
            elem = (char*)arg0 + 0x2278;
            int n = *p;
            for (int i = 0; i < (u32)n; i++) {
                fn_801B5DC0(&sp14, elem);
                spC = sp14;
                arg0->obj->fn_80186048(&spC, i);
                elem += 0x30;
            }
        }

        if (n2 != 0) {
            int* p = (u32)n2 < (u32)lbl_8059E90C ? &n2 : &lbl_8059E90C;
            elem = (char*)arg0 + 0xF8;
            int n = *p;
            for (int j = 0; j < (u32)n; j++) {
                fn_801A7550(&sp10, elem);
                sp8 = sp10;
                arg0->obj->fn_80186628(&sp8, j);
                elem += 0x10C;
            }
        }
    }
}
