#pragma force_active on

extern float lbl_27_rodata_27DC;

struct Vec3 {
    float x, y, z;
};

struct Pair {
    unsigned long a, b;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Object_vptr_0** slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, Pair*, Vec3*, void*);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual unsigned long long slot13(short*);

    unsigned char byte4, flags;
};

struct Modules {
    char pad[0x7c];
    Object_vptr_0* field;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x14];
    Object_vptr_0* array;
};

extern "C" void fn_27_1DBF30(Object* obj, int arg, Access* access) {
    Object_vptr_0* array = obj->array;
    Object_vptr_0* first = *array->slot1(0);
    Object_vptr_0* second = *array->slot1(1);

    if (arg == 0) {
        short id = 1;
        Pair p;
        unsigned long long value = access->modules->field->slot13(&id);
        p = *(Pair*)&value;
        Vec3 v = { lbl_27_rodata_27DC, lbl_27_rodata_27DC, lbl_27_rodata_27DC };
        first->slot5(0, &p, &v, access);

        Vec3 v2 = { lbl_27_rodata_27DC, lbl_27_rodata_27DC, lbl_27_rodata_27DC };
        struct FloatPair {
            float a, b;
        } p2 = { lbl_27_rodata_27DC, lbl_27_rodata_27DC };
        second->slot5(-1, (Pair*)&p2, &v2, access);
    }

    first->flags |= 0x80;
    second->flags |= 0x80;
}
