#pragma force_active on

struct Actor;

struct Situation {
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual int v14() = 0;
};

struct Handler {
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual void v14(Actor*) = 0;
};

struct ModuleBase {
    int a, b;
};

struct Module : ModuleBase {
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18(Actor*, int, int*, void*, int) = 0;
    virtual void v1C() = 0;
    virtual void v20(Actor*, int, void*) = 0;
    virtual void v24() = 0;
    virtual void v28() = 0;
    virtual void v2C() = 0;
    virtual void v30() = 0;
    virtual void v34() = 0;
    virtual void v38() = 0;
    virtual void v3C() = 0;
    virtual void v40() = 0;
    virtual void v44() = 0;
    virtual void v48() = 0;
    virtual void v4C() = 0;
    virtual void v50() = 0;
    virtual void v54() = 0;
    virtual void v58() = 0;
    virtual void v5C() = 0;
    virtual void v60() = 0;
    virtual void v64() = 0;
    virtual void v68() = 0;
    virtual void v6C() = 0;
    virtual void v70() = 0;
    virtual void v74() = 0;
    virtual void v78() = 0;
    virtual void v7C() = 0;
    virtual void v80() = 0;
    virtual void v84() = 0;
    virtual void v88() = 0;
    virtual void v8C() = 0;
    virtual void v90() = 0;
    virtual void v94() = 0;
    virtual void v98() = 0;
    virtual void v9C() = 0;
    virtual Module* vA0() = 0;
};

struct Modules {
    char pad00[0x14];
    Situation* situation;
    char pad18[0x20];
    Module* module;
};

struct Actor {
    char pad00[0xD8];
    Modules* modules;
};

struct Params {
    char pad00[0xC];
    float value;
    char pad10[0x2C];
    char data[4];
};

extern "C" int fn_27_63914(Actor*, Params*, float, int);
extern float lbl_41_rodata_E80;
extern float lbl_41_rodata_E84;

extern "C" void fn_41_34F98(Handler* self, Actor* actor, Params* params) {
    int out;
    int result;
    int situation = actor->modules->situation->v14();

    self->v14(actor);
    actor->modules->module->vA0()->v20(actor, 0, params->data);
    result = fn_27_63914(actor, params, lbl_41_rodata_E84, 0);

    if (params->value > lbl_41_rodata_E80) {
        actor->modules->module->vA0()->v18(
            actor, situation, &out, params->data, result);
    }
}
