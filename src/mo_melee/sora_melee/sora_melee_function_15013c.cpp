#pragma force_active on

struct Result {
    int* data;
    unsigned char flag;
};

class Iterator {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int* slot2(int);
    char pad[12];
    Result get(int i) {
        Result r;
        r.data = slot2(i);
        r.flag = 0;
        return r;
    }
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual signed char slot1();
    virtual signed char slot2();
    virtual int slot3();
    virtual void slot4();
    virtual Iterator slot5();
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
    virtual void slot16();
    virtual int slot17(signed char);
};

class Owner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(int);
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
    virtual void slot16();
    virtual int slot17(signed char);
};

extern "C" int fn_27_15013C(Owner* self, Object_vptr_0* arg) {
    if (self->slot17(arg->slot1()) == 0)
        return 0;

    if (arg->slot2() <= -1 || arg->slot2() >= 2)
        return 0;

    switch (arg->slot2()) {
    case 0: {
        if (arg->slot3() < 1)
            return 1;

        Iterator it = arg->slot5();
        Result b = it.get(0);

        int value;
        if (b.flag == 1)
            value = 0;
        else
            value = b.data[1];

        self->slot2(value);
        return 1;
    }
    case 1:
        self->slot4();
        return 1;
    default:
        return 0;
    }
}
