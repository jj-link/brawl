#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#include <types.h>
#include <new>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_466B8[];
extern char lbl_27_data_128[];
extern char lbl_27_data_81A0[];
extern char __RTTI__11soEventUnit[];
}

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(long);
    virtual void slot5();
    virtual int slot6(long);
    virtual int slot7();
    virtual void* slot8(long);
};

struct Obj {
    void* vt;
    char pad[0x30];
    void* p34;
    short id;
    short sub;
    int cache;
    int a40;
    int a44;
    int a48;
    int a4c;
};


extern "C" Obj* fn_27_2816DC(
    Obj* self, int id, soArrayVector<acCmdInterpreterStackData, 8>* vec,
    int a3, long mode, const unsigned char* reset, float step) {
    new ((void*)self) acCmdInterpreter(vec, mode, 0, reset, step);

    int result = 0;
    self->p34 = lbl_27_data_466B8;
    self->id = id;
    self->sub = 5;
    self->cache = result;

    if (id > 0 && id > -1) {
        if (((Object_vptr_0*)soEventSystem::getInstance())->slot6(id) != 0) {
            if (((Object_vptr_0*)soEventSystem::getInstance()->getManager(self->id))->slot4(self->sub) == 0) {
                self->cache = 0;
            } else {
                Object_vptr_0* m;
                short kind;
                kind = self->sub;
                m = (Object_vptr_0*)soEventSystem::getInstance()->getManager(self->id);
                if (m->slot4(kind) == 0) {
                    result = 0;
                } else {
                    void* p = m->slot8(kind);
                    Object_vptr_0* u = (Object_vptr_0*)__dynamic_cast(p, 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (u == 0) {
                        result = 0;
                    } else {
                        result = u->slot7();
                    }
                }
                self->cache = result;
            }
        }
    }

    self->a40 = a3;
    self->vt = lbl_27_data_81A0;
    self->p34 = lbl_27_data_81A0 + 0x20;
    self->a44 = 0;
    self->a48 = 0;
    self->a4c = 0;
    return self;
}
