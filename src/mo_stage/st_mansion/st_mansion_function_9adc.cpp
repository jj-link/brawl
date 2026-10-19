#include <types.h>

#pragma force_active on

struct Pad {
    char pad[0x3c];
};

struct Self : Pad {
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void vf(void*, void*, void*);

    char pad1[0x80];
    void* arg5;
    char pad2[0x94];
    void* elem;
    char pad3[0x14];
    void* arg6;
};

extern "C" void processAnim__6GroundFv(void*);

extern "C" void fn_47_9ADC(Self* self) {
    processAnim__6GroundFv(self);
    if (self->elem != 0)
        self->vf(self->elem, self->arg5, self->arg6);
}
