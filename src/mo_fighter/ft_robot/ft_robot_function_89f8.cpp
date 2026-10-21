#include <types.h>
#pragma force_active on

struct StatusModule {
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
    virtual s32 statusRequest(s32);
};

struct WorkModule {
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
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void flagSet(s32, s32, bool, s32);
};

struct Modules {
    char pad0[0x5C];
    WorkModule* work;
    char pad60[4];
    StatusModule* status;
};

struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

struct Event {
    s32 kind;
};

extern "C" void fn_27_1324D4(void*, Event*, Accesser*, void*, s32);

extern "C" void fn_120_89F8(void* self, Event* event, Accesser* accesser, void* object, s32 eventType) {
    switch (event->kind) {
    case 0x456:
        if (accesser->modules->status->statusRequest(0x12000042) != 0) {
            s32 a = 0;
            accesser->modules->work->flagSet(0xE, a, a, 8);
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, object, eventType);
}
