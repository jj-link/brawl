#include <types.h>
#pragma force_active on

extern "C" {
extern char __RTTI__18soEffectModuleImpl[];
extern char __RTTI__14soEffectModule[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_41_2834(void*, void*, void*, void*);
void fn_41_2890(void*, short);
void fn_27_1D8FC8(void*, int);
extern char lbl_27_bss_8B4[];
extern char lbl_41_data_409C[];
}

class IEnemyVt {
public:
    virtual void v2();
    virtual void v3(void*, void*);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int, int);
    virtual void v9();
    virtual void v10();
    virtual void v11(void*, int);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(int);
};

struct Tmp {
    short s8;
    void* sC;
    void* s10;
    char s14[0x1c];
};

extern "C" void fn_41_30618(char* self) {
    Tmp t;

    IEnemyVt* a = *(IEnemyVt**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x14);
    a->v8(2, 0);
    if (lbl_41_data_409C != 0) {
        IEnemyVt* b = *(IEnemyVt**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x20);
        b->v11(lbl_41_data_409C, 0);
    }
    IEnemyVt* c = *(IEnemyVt**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x20);
    c->v27(0);
    *(int*)(self + 0x2368) = 0;
    *(void**)(self + 0x236c) = self + 0x2368;
    *(int*)(self + 0x2370) = 1;
    char* obj = *(char**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x88);
    char* eff = (char*)__dynamic_cast(obj, 0, __RTTI__18soEffectModuleImpl, __RTTI__14soEffectModule, 1);
    *(void**)(eff + 0x50) = self + 0x236c;
    fn_41_2834(t.s14, lbl_27_bss_8B4, lbl_27_bss_8B4, lbl_27_bss_8B4);
    t.s8 = 0x10;
    t.sC = self + 0x226c;
    t.s10 = t.s14;
    IEnemyVt* d = *(IEnemyVt**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x6c);
    d->v3(&t.sC, &t.s8);
    fn_27_1D8FC8(self + 0xc, 0);
    *(char*)(self + 0x21b4) = 1;
    fn_41_2890(t.s14, -1);
}
