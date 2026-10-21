#pragma force_active on
extern "C" void* getInstance__9itManagerFv();
extern "C" void* getItemFromInstanceId__9itManagerFi(void*, int);
extern "C" int fn_27_28DC8C(void*);
extern "C" float getParamFloat__8BaseItemFUl(void*, unsigned long);
extern "C" const float lbl_68_rodata_D0;

struct Sub {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Mid {
    char pad0[0x14];
    Sub* s;
};

struct Obj {
    char pad0[0x1a4];
    Mid* mid;
    int id;
};

extern "C" int fn_68_CA28(Obj* self) {
    if (self->id == 0) {
        return 0;
    }
    void* mgr = getInstance__9itManagerFv();
    if (mgr == 0) {
        return 0;
    }
    self = (Obj*)getItemFromInstanceId__9itManagerFi(mgr, self->id);
    if (self == 0) {
        return 0;
    }
    if (fn_27_28DC8C(self) == 0) {
        return 0;
    }
    if (self->mid->s->v3() == 2) {
        return 0;
    }
    return lbl_68_rodata_D0 == getParamFloat__8BaseItemFUl(self, 0x3ee);
}
