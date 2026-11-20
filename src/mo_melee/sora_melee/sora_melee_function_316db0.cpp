#include <types.h>
#include <new>
#pragma use_simple_stdpnew on
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_466B8[];
extern char lbl_27_data_81A0[];
extern char lbl_27_data_15218[];
extern char lbl_27_data_128[];
extern char __RTTI__11soEventUnit[];
extern int lbl_27_bss_8C4;
extern const float lbl_27_rodata_74B0;
extern const float lbl_27_rodata_74BC;
void* __dynamic_cast(void*, long, const void*, const void*, long);
}
class Class_18ED8 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual s32 s7();
};
class Class_1F90 {
public:
    virtual void f0(); virtual void f1(void*, s16*);
};
class Unit8 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual s32 s7();
};
struct Ctx {
    char pad[0x6C]; Class_1F90* f6C; char pad70[0x10]; char* f80;
};
struct Owner { char pad[0xD8]; Ctx* ctx; };
struct Self {
    acCmdInterpreter base;
    void* vt34; s16 id; s16 kind; s32 result;
    s32 f40; s32 f44; s32 f48; s32 f4C;
    void* vt50; void* vt54; u32 f58;
    acCmdInterpreterStackData data[8];
};
struct Entry : acCmdInterpreterStackData {
    Entry() : acCmdInterpreterStackData(Invalid, 0, false, 0, lbl_27_rodata_74BC) {}
};
struct StackInit {
    void* vt0; void* vt4; u32 bits; Entry entries[8];
    StackInit() : vt0(lbl_27_data_15218), vt4(lbl_27_data_15218 + 0x48), bits((u16)bits) {}
};
extern "C" Self* fn_27_316DB0(Self* self, Owner* arg1) {
    s32 r;
    u8 reset = 1;
    s32 id = ((Class_18ED8*)(arg1->ctx->f80 + 8))->s7();
    new (&self->base) acCmdInterpreter((soArrayVector<acCmdInterpreterStackData, 8>*)((char*)self + 0x50), 1, 0, &reset, lbl_27_rodata_74B0);
    s32 eventId;
    self->vt34 = lbl_27_data_466B8;
    self->id = id;
    self->kind = 5;
    r = 0;
    self->result = r;
    eventId = (s16)id;
    if (eventId > 0 && eventId > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(eventId) != 0) {
            soEventManager* mgr = soEventSystem::getInstance()->getManager(self->id);
            if (mgr->getObserverCapacity(self->kind) == 0) {
                self->result = r;
            } else {
                s16 k = self->kind;
                soEventManager* m = soEventSystem::getInstance()->getManager(self->id);
                if (m->getObserverCapacity(k) == 0) {
                    r = 0;
                } else {
                    Unit8* u = (Unit8*)__dynamic_cast(m->getEventUnit(k), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        r = 0;
                    } else {
                        r = u->s7();
                    }
                }
                self->result = r;
            }
        }
    }
    *(void**)self = lbl_27_data_81A0;
    self->vt34 = lbl_27_data_81A0 + 0x20;
    self->f40 = 4;
    self->f44 = 0; self->f48 = 0; self->f4C = 0;
    new (&self->vt50) StackInit;
    struct Key { s16 value; char padding[2]; } key;
    key.value = 4;
    struct Pair { Self* a; int* b; } pair;
    pair.a = self;
    pair.b = &lbl_27_bss_8C4;
    arg1->ctx->f6C->f1(&pair, &key.value);
    return self;
}