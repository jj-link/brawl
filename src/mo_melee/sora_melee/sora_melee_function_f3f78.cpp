#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual int* get(int index);
    virtual int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual u32 v14();
};

class Owner {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual u32 o5();
    u8 pad[0x10 - 4];
    Obj m_obj;
};

extern "C" int fn_27_F3F78(Owner* self) {
    int prev;
    int i;
    int idx;
    if (self->m_obj.v14() == 1) {
        return 0x7FFF;
    }
    if (self->o5() == 1) {
        return 0;
    }
    idx = self->m_obj.size() - 1;
    if (self->m_obj.get(idx)[1] < 0x7FFF) {
        idx = self->m_obj.size() - 1;
        return self->m_obj.get(idx)[1] + 1;
    }
    i = self->m_obj.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_obj.get(i)[1] == 0) {
                return -1;
            }
            return self->m_obj.get(i)[1] - 1;
        }
        prev = self->m_obj.get(i - 1)[1];
        if (self->m_obj.get(i)[1] - 1 > prev) {
            return self->m_obj.get(i)[1] - 1;
        }
        i--;
    }
    return -1;
}
