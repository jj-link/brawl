#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>

#pragma force_active on

struct Vec3 {
    float x, y, z;

    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

extern "C" {
extern const char lbl_100_data_2098[], lbl_100_data_20C4[];
extern const float lbl_100_rodata_8;

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_100_12F2C(void*, int, int, void*, Vec3*, float, int, float);
}

class ResBase {
public:
    int pad[2];
};

class ResObj : public ResBase {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void* s4();
};

class Node {
public:
    virtual void n0();
    virtual void n1();
    virtual void n2();
    virtual void n3();
    virtual Vec3 n4();
    virtual void n5();
    virtual void n6();
    virtual void n7();
    virtual void n8();
    virtual float n9();
};

class OwnerNode {
public:
    virtual void o0();
    virtual void o1();
    virtual OwnerNode* o2();
};

class StateObj {
public:
    virtual void fn_100_6C60();
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};

struct Sub {
    int pad[10];
    int taskId;
};

struct Modules {
    ResObj* resource;
    int pad[2];
    Node* node;
    int pad1[2];
    OwnerNode* owner;
    int pad2[18];
    soWorkManageModule* effect;
    int pad3[2];
    StateObj* state;
};

struct Accesser {
    char pad0[0x8];
    Sub* sub;
    char pad1[0xCC];
    Modules* modules;
};

struct Owner2 {
    char pad0[0x28];
    int val;
    int getVal() { return val; }
};

extern "C" int fn_100_8E68(Owner2* self, Accesser* accesser) {
    Node* node = accesser->modules->node;
    StateObj* state = accesser->modules->state;
    void* ptr = accesser->modules->resource->s4();
    void* dyn = __dynamic_cast(
        ptr, 0, lbl_100_data_2098, lbl_100_data_20C4, 1);

    int flag;
    Vec3 pos;
    pos = node->n4();

    float c = soValueAccesser::getConstantFloat(
        reinterpret_cast<soModuleAccesser*>(accesser), 0xBE2, 0);
    float f30 = node->n9();
    flag = 0;

    int st = state->slot16();
    switch (st) {
    case 0x11F:
    case 0x120:
        f30 = lbl_100_rodata_8;
        pos.x = f30;
        pos.y = f30;
        pos.z = f30;
        flag = 1;
        break;
    }

    int taskId = accesser->sub->taskId;
    node = reinterpret_cast<Node*>(accesser->modules->owner->o2()->o2());
    int res = fn_27_14DB04(dyn);
    fn_100_12F2C(self, taskId, res, node, &pos, f30, flag, c);

    int value = self->getVal();
    accesser->modules->effect->setInt(value, 0x20000001);
    return 1;
}
