#include <types.h>
#pragma force_active on

struct Sender {
    char reserved[0x3c];
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
    virtual s32 getCategory();
};

struct Target {
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
    virtual void fn(s32, void*);
};

struct Modules {
    char pad[0x54];
    Target* target;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Event {
    s32 kind;
    char pad4[4];
    Sender* sender;
};

extern "C" void fn_27_1DB0F0(void*, Event*, Accesser*, void*, int);

extern "C" void fn_107_1F814(void* self, Event* event, Accesser* accesser, void* object, int eventType) {
    switch (event->kind) {
    case 0x3E:
        switch (event->sender->getCategory()) {
        case 5:
        case 15:
            accesser->modules->target->fn(3, event);
            break;
        }
        break;
    }
    fn_27_1DB0F0(self, event, accesser, object, eventType);
}
