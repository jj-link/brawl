#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_101_data_853C[], lbl_101_data_4330[];
}

class CameraThing {
public:
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual Vec3f getPair();
    virtual void setPair(Vec3f*);
};

class Controller {
public:
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void setTarget(int, int, int);
};

struct Holder {
    char pad[0xc];
    CameraThing* camera;
    char pad2[0x10];
    Controller* other;
};

struct Arg {
    char pad[8];
    void* object;
    char pad2[0xcc];
    Holder* holder;
};

struct ObjData {
    char pad[8];
    float unk8;
};

extern "C" void fn_101_16654(void*, Arg* arg) {
    ObjData* data = *(ObjData**)((char*)__dynamic_cast(arg->object, 0x3c, lbl_101_data_853C, lbl_101_data_4330, 1) + 0x23ac);
    Vec3f v = arg->holder->camera->getPair();
    v.m_y += data->unk8;
    arg->holder->camera->setPair(&v);
    arg->holder->other->setTarget(1, 0, 0);
    arg->holder->other->setTarget(0, 3, 0);
}
