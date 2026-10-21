#include <types.h>
#pragma force_active on

struct FirstModule {
    char pad[8];

    virtual u32 v0();
    virtual u32 v1();
    virtual u32 v2();
    virtual u32 v3();
    virtual u32 v4();
    virtual u32 v5();
    virtual u32 v6();
    virtual u32 v7();
    virtual u32 v8();
    virtual u32 v9();
    virtual u32 v10();
    virtual u32 v11();
    virtual u32 v12();
    virtual u32 v13();
    virtual u32 v14();
    virtual u32 v15();
    virtual u32 v16();
    virtual u32 v17();
    virtual u32 v18();
    virtual u32 v19();
    virtual u32 v20();
    virtual u32 v21();
    virtual u32 v22();
    virtual u32 v23();
    virtual u32 v24();
    virtual u32 v25();
    virtual u32 v26();
    virtual u32 v27();
    virtual u32 v28();
    virtual u32 v29();
    virtual u32 v30();
    virtual u32 v31();
    virtual u32 v32();
    virtual u32 v33();
    virtual u32 v34();
    virtual u32 v35();
    virtual u32 v36();
    virtual u32 v37();
    virtual u32 v38();
    virtual u32 v39();
    virtual u32 v40();
    virtual u32 v41();
    virtual u32 v42();
    virtual u32 v43();
};

struct Module {
    virtual u32 v0();
    virtual u32 v1();
    virtual u32 v2();
    virtual u32 v3();
    virtual u32 v4();
    virtual u32 v5();
    virtual u32 v6();
    virtual u32 v7();
    virtual u32 v8();
    virtual u32 v9();
    virtual u32 v10();
    virtual u32 v11();
    virtual u32 v12();
    virtual u32 v13();
    virtual u32 v14();
    virtual u32 v15();
    virtual u32 v16();
    virtual u32 v17(u32 arg);
    virtual u32 v18();
    virtual u32 v19();
    virtual u32 v20();
    virtual u32 v21();
    virtual u32 v22();
    virtual u32 v23();
    virtual u32 v24();
    virtual u32 v25();
    virtual u32 v26();
    virtual u32 v27();
    virtual u32 v28();
    virtual u32 v29();
    virtual u32 v30();
    virtual u32 v31();
    virtual u32 v32();
    virtual u32 v33();
    virtual u32 v34();
    virtual u32 v35();
    virtual u32 v36();
    virtual u32 v37();
    virtual u32 v38();
    virtual u32 v39();
    virtual u32 v40();
    virtual u32 v41();
    virtual u32 v42();
    virtual u32 v43();
    virtual u32 v44();
    virtual u32 v45();
    virtual u32 v46();
    virtual u32 v47();
    virtual u32 v48(u32 arg);
};

#define FIELD(p, off, T) (*(T*)((char*)(p) + (off)))

extern "C" bool fn_27_184360(void*, void* p) {
    FirstModule* a = FIELD(FIELD(p, 0xd8, void*), 0x38, FirstModule*);
    if (a->v43() == 1U) {
        return false;
    }

    Module* b = FIELD(FIELD(p, 0xd8, void*), 0x54, Module*);
    if (b->v48(0) == 1U) {
        return false;
    }

    Module* c = FIELD(FIELD(p, 0xd8, void*), 0x64, Module*);
    return c->v17(0x22000014) == 0;
}
