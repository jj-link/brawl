#include <types.h>
#pragma force_active on

extern "C" void fn_27_1186D4(int value);

class Obj {
public:
    virtual void v0();
    virtual int* get(int index);
    virtual void v2();
    virtual int size();
};

class Owner {
public:
    u8 pad[8];
    Obj m_obj;
};

extern "C" void fn_27_11A440(Owner* self) {
    int count = self->m_obj.size();
    for (int i = 0; i < count; i++) {
        fn_27_1186D4(*self->m_obj.get(i));
    }
}
