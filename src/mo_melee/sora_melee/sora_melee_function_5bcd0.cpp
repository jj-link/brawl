#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void* self, const char* name, int category, int a, int b, bool c);
extern const char lbl_27_data_6300[];
extern const char lbl_27_data_6308[];

struct fn_27_Obj {
    char pad[0x3C];
    const char* p;
    int i;
    float f;
    unsigned char b;
};

void* fn_27_5BCD0(void* self) {
    fn_27_Obj* o = (fn_27_Obj*)self;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_27_data_6300, 0, 0, 13, true);
    o->i = 0;
    o->p = lbl_27_data_6308;
    o->f = 1.0f;
    o->b = 0;
    return self;
}
}
#include <so/so_module_accesser.h>
extern "C" {
extern void* lbl_27_bss_F0;
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}
extern "C" void* fn_27_5BD3C(void* self, int flag) {
    if (self) {
        lbl_27_bss_F0 = 0;
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
extern "C" {
extern void* g_GameGlobal;
unsigned int getSlowRate__10GameGlobalCFv(void*);
unsigned int fn_8004E958(void*);
unsigned int fn_8004E96C(void*);

struct fn_27_Obj2 {
    char pad[0x40];
    int i;
    float f;
    unsigned char b;
};

void fn_27_5BDA0(fn_27_Obj2* o) {
    if (getSlowRate__10GameGlobalCFv(g_GameGlobal) != 1) {
        if (fn_8004E958(g_GameGlobal) == 1) {
            o->i = 0;
        } else if (fn_8004E96C(g_GameGlobal) == 1) {
            o->i = 2;
        } else {
            o->i = 1;
        }
        o->b = 1;
        o->f = 1.0f / (float)getSlowRate__10GameGlobalCFv(g_GameGlobal);
    } else {
        o->i = 0;
        o->b = 0;
        o->f = 1.0f;
    }
}
}
