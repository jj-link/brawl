#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_114_data_7D2C[], lbl_114_data_3C7C[];
}

class Class_8CD0 {
public:
    virtual void fn_114_8BC0();
    virtual void fn_114_150C0();
    virtual void fn_114_159B0();
    virtual void fn_114_159AC();
    virtual void fn_114_159A8();
    virtual void fn_114_159A4();
    virtual void fn_114_1599C();
    virtual void fn_114_159E4();
    virtual void fn_114_159DC();
    virtual void fn_114_159D4();
    virtual void fn_114_159CC();
    virtual void fn_114_159C4();
    virtual void fn_114_1595C();
    virtual void fn_114_15990();
    virtual void fn_114_15984();
    virtual void fn_114_1597C(int, int, int);
};
class Class_9054 {
public:
    virtual void fn_114_8BC0();
    virtual void fn_114_15064();
    virtual void fn_114_15CB4();
    virtual void fn_114_15CAC();
    virtual void fn_114_15CA4();
    virtual void fn_114_15C9C();
    virtual void fn_114_15C94();
    virtual void fn_114_15C8C();
    virtual void fn_114_15C84();
    virtual void fn_114_15C7C();
    virtual void fn_114_15C74();
    virtual void fn_114_15C6C();
    virtual void fn_114_15C64();
    virtual void fn_114_15C5C();
    virtual void fn_114_15C0C();
    virtual void fn_114_15C54();
};
class Camera {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3f get();
    virtual void set(Vec3f*);
};
struct Holder {
    char pad[0xc];
    Camera* camera;
    char pad2[0x10];
    Class_8CD0* other;
};
struct Arg {
    char pad[8];
    void* object;
    char pad2[0xcc];
    Holder* holder;
};
extern "C" void fn_114_161A4(void*, Arg* arg) {
    char* p = (char*)__dynamic_cast(arg->object, 0x3c, lbl_114_data_7D2C, lbl_114_data_3C7C, 1);
    char* data = *(char**)(p + 0x23ac);
    Vec3f v = arg->holder->camera->get();
    v.m_y += *(float*)(data + 8);
    arg->holder->camera->set(&v);
    arg->holder->other->fn_114_1597C(1, 0, 0);
    arg->holder->other->fn_114_1597C(0, 3, 0);
}