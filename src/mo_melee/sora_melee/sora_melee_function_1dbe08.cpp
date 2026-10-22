#include <types.h>
#pragma force_active on

extern "C" void fn_27_87084(void* self, void* owner);
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" char lbl_27_data_457C8[];

class Obs {
public:
    virtual void addObserver(s32 p1, s32 p2);
    s16 manageID;
    s16 unitID;
    s16 sendID;
};

class Getter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s16 get();
};

struct Self {
    void* f00;
    char pad4[4];
    void* f08;
    char padC[0x14];
    Obs obs;
    s32 f2C;
};

extern "C" Self* fn_27_1DBE08(Self* self, void* arg1) {
    fn_27_87084(self, arg1);
    char* Q = *(char**)((char*)arg1 + 0xd8);
    Q = *(char**)(Q + 0x80);
    s16 result = ((Getter*)(Q + 8))->get();
    self->obs.manageID = -1;
    self->obs.unitID = 4;
    self->obs.sendID = -1;
    *reinterpret_cast<void**>(&(self->obs)) = (void*)__vt__21soStatusEventObserver;
    self->obs.addObserver((s32)result, -1);
    self->f2C = -1;
    char* d = (char*)lbl_27_data_457C8;
    self->f00 = (void*)d;
    self->f08 = (void*)(d + 0x6c);
    *reinterpret_cast<void**>(&(self->obs)) = (void*)(d + 0x88);
    return self;
}
