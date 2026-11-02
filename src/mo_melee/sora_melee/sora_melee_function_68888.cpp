#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/so_array.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_27_687F8(void* self, void* owner, void* table, u32 flag);
extern "C" u8 lbl_27_bss_8E4[];
extern "C" u8 lbl_27_data_7940[];
extern "C" u8 __vt__22soAnimCmdEventObserver[];

struct Elem {
    s32 pad0;
    s32 value;
    s32 pad8;
};

class Getter {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual s16 get();
};

struct Module {
    char pad[0x80];
    void* object;
};

struct Owner {
    char pad[0xD8];
    Module* module;
};

struct Self {
    void* vtable;
    char pad4[4];
    soAnimCmdEventObserver observer;
    soArrayFixed<Elem>* arr;
    s32 value;
};

extern "C" Self* fn_27_68888(Self* self, Owner* owner, soArrayFixed<Elem>* arr, s32 value) {
    fn_27_687F8(self, owner, lbl_27_bss_8E4, 0);
    s16 id = ((Getter*)((char*)owner->module->object + 8))->get();

    self->observer.m_manageID = -1;
    self->observer.m_unitID = 5;
    self->observer.m_sendID = -1;
    *(void**)&self->observer = __vt__22soAnimCmdEventObserver;
    self->observer.addObserver(id, -1);

    self->arr = arr;
    self->vtable = lbl_27_data_7940;
    *(void**)&self->observer = lbl_27_data_7940 + 0x2c;
    self->value = -1;

    if (value != 0) {
        s32 count = arr->size();
        for (s32 i = 0; i < count; i++) {
            self->arr->at(i).value = value;
            value += 0xc;
        }
    }
    return self;
}
