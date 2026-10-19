#pragma force_active on
namespace {
struct Mod {
    virtual void v08() = 0;
    virtual void v0C() = 0;
    virtual void v10() = 0;
    virtual void v14() = 0;
    virtual void v18() = 0;
    virtual void v1C() = 0;
    virtual void v20() = 0;
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
    virtual int call(int) = 0;
};
struct L3 {
    unsigned char pad[0x64];
    Mod* mod;
};
struct L2 {
    unsigned char pad[0xD8];
    L3* next;
};
struct Obj {
    unsigned char pad[0x60];
    L2* next;
};
}

extern "C" int fn_117_20B0C(Obj* obj) {
    return obj->next->next->mod->call(0x22000005);
}
