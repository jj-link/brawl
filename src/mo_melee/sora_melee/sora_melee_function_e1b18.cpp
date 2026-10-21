#pragma force_active on
#include <types.h>

struct VBase {
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
};

struct SNoArg : VBase {
    virtual SNoArg* f26();
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s32 unkC;
};

struct SArg : VBase {
    virtual SArg* f26(void* arg);
};

extern "C" void fn_27_E1B18(void* self, void* unused, void* arg) {
    SNoArg* p = ((SNoArg*)self)->f26();
    SNoArg* q = (SNoArg*)((SArg*)self)->f26(arg);
    *(s16*)((char*)q + 4) = *(s16*)((char*)p + 4);
    *(s16*)((char*)q + 6) = *(s16*)((char*)p + 6);
    *(s16*)((char*)q + 8) = *(s16*)((char*)p + 8);
    *(s32*)((char*)q + 12) = *(s32*)((char*)p + 12);
}
