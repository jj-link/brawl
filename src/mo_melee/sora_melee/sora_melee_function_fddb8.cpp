#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual int* get(int index);
    virtual int size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual u32 s16();
};

class Owner {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual u32 s7();
    char pad[12];
    Obj m_obj;
};

extern "C" int fn_27_FDDB8(Owner* self) {
    int prev;
    if (self->m_obj.s16() == 1) {
        return 0x7FFF;
    }
    if (self->s7() == 1) {
        return 0;
    }
    int idx = self->m_obj.size() - 1;
    if (self->m_obj.get(idx)[1] < 0x7FFF) {
        idx = self->m_obj.size() - 1;
        return self->m_obj.get(idx)[1] + 1;
    }
    int i = self->m_obj.size() - 1;
    for (; i >= 0; i--) {
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
    }
    return -1;
}
