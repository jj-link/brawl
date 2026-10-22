#include <types.h>
#pragma force_active on

extern "C" void* fn_801CFC08();
extern "C" void fn_801E187C(void* p);

class Obj {
public:
    virtual ~Obj();
    virtual void f0();

    u8 pad[0x8];
    u8 flag;
};

class Owner {
public:
    u8 pad[0x24];
    Obj* m_obj;
};

extern "C" void* fn_801CFE70(Owner* self) {
    Obj* obj = (Obj*)fn_801CFC08();
    if (obj == 0) {
        return 0;
    }
    self->m_obj = obj;
    obj->flag = 0;
    obj->f0();
    self->m_obj = 0;
    fn_801E187C((u8*)self + 0x34);
    return obj;
}
