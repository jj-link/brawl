#pragma force_active on
#include <ft/ft_common_data_accesser.h>

class Object_vptr_0 {
public:
    virtual void fn_94_6CF8();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(int, int, int);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17(int, float*, float*);
};

struct Mid {
    char pad[0x90];
    Object_vptr_0* obj;
};

struct Owner {
    char pad[0xd8];
    Mid* mid;
};

struct Sub {
    char pad[0x14];
    float a;
    float b;
    float c;
    float d;
};

struct Holder {
    char pad[0x84];
    Sub* sub;
};

extern "C" void fn_94_F174(float*, float, float);

extern "C" void fn_94_19D68(void* unused, Owner* self) {
    Object_vptr_0* obj = self->mid->obj;
    obj->slot12(9, 1, -1);
    Holder* h = (Holder*)g_ftCommonDataAccesser.getData((ftKind)0x18);
    Sub* s = h->sub;
    float t1[2];
    float t2[2];
    fn_94_F174(t1, s->a, s->b);
    fn_94_F174(t2, s->c, s->d);
    obj->slot17(9, t1, t2);
}
