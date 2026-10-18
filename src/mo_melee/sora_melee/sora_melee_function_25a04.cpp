#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual ~Obj();
    virtual int vf1(int index);
    virtual void vf2();
    virtual int vf3();
};

class Owner {
public:
    u8 pad[0x28];
    Obj* m_obj;
};

extern "C" void fn_27_2E8F8(int value);

extern "C" void fn_27_25A04(Owner* self) {
    int count = self->m_obj->vf3();
    for (int i = 0; i < count; i++) {
        fn_27_2E8F8(self->m_obj->vf1(i));
    }
}
