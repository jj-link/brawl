#pragma force_active on
#include <types.h>

extern "C" {

extern char lbl_27_data_7AA38[];
bool fn_27_2C2C18(void*);
void __dt__20tyFigListDataManagerFv(void*, int);
void __destroy_arr(void*, void* (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_27_2C2490(void*, int);

struct ObjBase {
    unsigned char padding0[8];
    unsigned char active;
    unsigned char padding9[7];
};
struct Obj : ObjBase {
    virtual void slot0(int);
};

struct Container {
    virtual void fn_27_7B274();
    virtual Obj** fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
    virtual void fn_27_7B0B0(int);
};

struct Root {
    char pad[8];
    Container container;
};

void* fn_27_2C0CD4(Root* self, int arg1) {
    if (self != 0) {
        *(void**)self = &lbl_27_data_7AA38;
        for (int i = 0; i < self->container.fn_27_7AB50(); ++i) {
            Obj** entry = self->container.fn_27_7AC18(i);
            if (*entry != 0) {
                if (fn_27_2C2C18(*entry)) {
                    if (*entry != 0) {
                        ((Obj*)*entry)->slot0(1);
                    }
                    self->container.fn_27_7B0B0(i);
                    --i;
                } else {
                    ((Obj*)*entry)->active = 1;
                }
            }
        }
        __dt__20tyFigListDataManagerFv(*(void**)((char*)self + 4), 1);
        *(void**)((char*)self + 4) = 0;
        if ((char*)self + 8) {
            __destroy_arr((void*)((char*)self + 0x10), fn_27_2C2490, 0xcUL, 0x40UL);
        }
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

}