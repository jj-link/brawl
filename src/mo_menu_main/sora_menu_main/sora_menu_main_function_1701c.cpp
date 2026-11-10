#include <types.h>
#pragma force_active on

class Class728_base { public: char pad[0x3c]; };
class Class728 : public Class728_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23(int, int, int);
    virtual void slot24();
    virtual void fn_2_36914();
    virtual void fn_2_36908();
    virtual void fn_2_361C4(int, int);
};

class ArgObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void*, void*);
    char pad[0xe4 - 4];
    void* e4;
};

class SlotObj {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(void*, float);
};

struct MuAnimHolder {
    char pad[0x10];
    SlotObj* obj;
};

struct Mu {
    char pad[0x10];
    void* p10;
    MuAnimHolder* p14;
};

struct Holder {
    char pad[0xa4];
    Mu* mu;
};

struct Self {
    char p0[0x42];
    u16 v42;
    char p1[0x64c - 0x44];
    Holder* m64c;
    char p2[0x654 - 0x650];
    ArgObj* arg654;
    Class728* o658;
    char p4[0x664 - 0x65c];
    u32 s664;
};

extern "C" {
extern void* g_GameGlobal;
extern char lbl_2_data_2040[];
extern const float lbl_2_rodata_5F8;
u8* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void fn_800B330C(void*, char*, int);
void changeTexPatAnim__8MuObjectFPCc(void*, const char*);
void setFrameTex__8MuObjectFf(void*, float);
}

extern "C" void fn_2_1701C(Self* self, ArgObj* arg) {
    self->arg654 = arg;
    self->s664 = 0;
    u8* rec = getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    self->v42 = rec[0x19];
    arg->slot11(arg->e4, self->m64c->mu->p10);
    fn_800B330C(self->m64c->mu, lbl_2_data_2040, 1);
    changeTexPatAnim__8MuObjectFPCc(self->m64c->mu, 0);
    setFrameTex__8MuObjectFf(self->m64c->mu, (f32)(u32)self->v42);
    self->m64c->mu->p14->obj->slot8(self->m64c, lbl_2_rodata_5F8);
    self->o658->fn_2_361C4(0x15, 0x3f - self->v42);
}
