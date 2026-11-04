#include <so/model/so_model_module_simple.h>

struct GanonAccesser;
class Class_6DA4 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10ECC();
    virtual void fn_109_116D8();
    virtual bool fn_109_116D4(int, GanonAccesser*);
    virtual void fn_109_116D0();
    virtual void fn_109_116CC();
    virtual void fn_109_116C4();
    virtual void fn_109_1170C();
    virtual void fn_109_11704();
    virtual void fn_109_116FC();
    virtual void fn_109_116F4();
    virtual void fn_109_116EC();
    virtual void fn_109_11684();
    virtual void fn_109_116B8();
    virtual void fn_109_116AC();
    virtual void fn_109_116A4();
    virtual int fn_109_11698();
};
class Class_71D8 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10E70();
    virtual void fn_109_119D4();
    virtual void fn_109_119CC();
    virtual void fn_109_119C4();
    virtual void fn_109_119BC(void*);
    virtual void fn_109_119B4();
    virtual void fn_109_119AC();
    virtual void fn_109_119A4();
    virtual void fn_109_1199C();
    virtual void fn_109_11994();
    virtual void fn_109_1198C();
    virtual void fn_109_11984(int);
    virtual void fn_109_1197C();
    virtual void fn_109_1192C(int);
    virtual void fn_109_11974();
    virtual void fn_109_11964();
};
struct GanonModules {
    void* resource;
    soModelModule* model;
    unsigned char pad08[0x34];
    Class_71D8* catchModule;
    unsigned char pad40[0x30];
    Class_6DA4* status;
};
struct GanonAccesser {
    unsigned char pad00[0xD8];
    GanonModules* modules;
};
struct GanonFighter {
    unsigned char pad00[0x60];
    GanonAccesser* accesser;
};
struct GanonEvent {
    int kind;
    unsigned char handled;
    unsigned char flag;
    unsigned char pad06[2];
    int node;
    int code;
    unsigned char pad10[0xC];
    unsigned char flag1C;
};
struct GanonObject {
    unsigned char pad00[0x28];
    void* field28;
};
extern "C" void fn_109_DCBC(GanonEvent*, GanonAccesser*, GanonObject*, int);
extern "C" void fn_27_1324D4(GanonFighter*, GanonEvent*, GanonAccesser*, GanonObject*, int);

#pragma force_active on
extern "C" void fn_109_86B8(GanonFighter* self, GanonEvent* event, GanonAccesser* accesser, GanonObject* object, int value) {
    int kind = accesser->modules->status->fn_109_11698();
    switch (event->kind) {
    case 4:
        fn_109_DCBC(event, accesser, object, value);
        break;
    case 8:
        if (event->code == 0xE6 && kind == 0x114) {
            accesser->modules->status->fn_109_116D4(0x11C, accesser);
            event->handled = 1;
            event->flag1C = 0;
            accesser->modules->catchModule->fn_109_119BC(object->field28);
            return;
        }
        if (kind == 0x113 && event->code == 0xE7) {
            accesser->modules->status->fn_109_116D4(0x118, accesser);
            event->handled = 1;
            event->node = accesser->modules->model->getCorrectNodeId(0x12C);
            return;
        }
        if (kind == 0x113 && event->code == 0xE8) {
            accesser->modules->status->fn_109_116D4(0x119, accesser);
            event->handled = 1;
            event->node = accesser->modules->model->getCorrectNodeId(0x12C);
            return;
        }
        break;
    case 14:
        switch (kind) {
        case 0x11C:
        case 0x11D:
            self->accesser->modules->catchModule->fn_109_1192C(0);
            self->accesser->modules->catchModule->fn_109_11984(0);
            if (event->flag == 0)
                self->accesser->modules->status->fn_109_116D4(0x3B, self->accesser);
            return;
        }
        break;
    }
    fn_27_1324D4(self, event, accesser, object, value);
}
