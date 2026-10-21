#pragma force_active on

typedef unsigned int u32;

class Status {
public:
    char pad[8];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual u32 getState();
    virtual float getValue();
};

struct ModuleTable {
    char pad[0xBC];
    Status* status;
};

struct ModuleAccesser {
    char pad[0xD8];
    ModuleTable* modules;
};

struct Object {
    char pad[0x60];
    ModuleAccesser* accesser;
};

struct Vec2 {
    float x, y;
};

extern float lbl_27_rodata_65B8;

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    ModuleAccesser*, u32, u32);
extern "C" int fn_27_30F064(Object*, Vec2*, Vec2*);
extern "C" int fn_27_1DAF80(Object*, u32);

extern "C" int fn_27_30EF60(Object* self, u32 flags) {
    if (flags & 7)
        return 0;

    int ready = 0;
    if (flags & 8) {
        if (self->accesser->modules->status->getState() == 1)
            ready = 1;
    }

    if (ready) {
        Vec2 zero = { lbl_27_rodata_65B8, lbl_27_rodata_65B8 };
        float value =
            getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                self->accesser, 0xFA0, 0);
        Vec2 result = {
            -self->accesser->modules->status->getValue(), value
        };
        return fn_27_30F064(self, &result, &zero);
    }

    return fn_27_1DAF80(self, flags);
}
