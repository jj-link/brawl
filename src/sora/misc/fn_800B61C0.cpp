#pragma force_active on

extern double lbl_805A2208;

struct Param {
    char pad0[0x1C];
    unsigned short threshold;
    char pad1[2];
    int state;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual float slot6();

    char pad0[0x28];
    Param* param;
};

struct Link {
    char pad0[0xC];
    Object_vptr_0* next;
};

struct Root {
    char pad0[0x14];
    Link* link;
};

extern "C" int fn_800B61C0(Root* self) {
    Link* link = self->link;
    if (link == 0) {
        return 1;
    }

    Object_vptr_0* object = link->next;
    if (object == 0) {
        return 1;
    }

    Param* param = object->param;
    if (param->state != 1) {
        unsigned short threshold = param->threshold;
        float result = object->slot6();

        if (result >= (float)(threshold - 1)) {
            return 1;
        }
    }

    return 0;
}
