#include <types.h>
#pragma force_active on

class Elem {
public:
    int pad;
    int value;
};

class Obj {
public:
    virtual void a();
    virtual void b();
    virtual Elem* get(int index);
    virtual int size();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual int m();
};

class Self {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int f();
    u8 pad[12];
    Obj m_obj;
};

extern "C" int fn_27_1C54BC(Self* self) {
    if (self->m_obj.m() == 1U) {
        return 0x7FFF;
    }
    if (self->f() == 1U) {
        return 0;
    }
    int n1 = self->m_obj.size() - 1;
    if (self->m_obj.get(n1)->value < 0x7FFF) {
        int n2 = self->m_obj.size() - 1;
        return self->m_obj.get(n2)->value + 1;
    }
    int prev;
    int i = self->m_obj.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_obj.get(i)->value == 0) {
                return -1;
            }
            return self->m_obj.get(i)->value - 1;
        }
        prev = self->m_obj.get(i - 1)->value;
        if (self->m_obj.get(i)->value - 1 > prev) {
            return self->m_obj.get(i)->value - 1;
        }
        i--;
    }
    return -1;
}
