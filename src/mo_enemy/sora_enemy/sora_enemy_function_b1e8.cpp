#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned int);
    virtual void slot5(int, unsigned int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned int);
    virtual void slot13(float, unsigned int);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(unsigned int);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(int, unsigned int);
};

class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC();
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
    virtual void fn_41_350F0();
    virtual void fn_41_350F4();
    virtual void fn_41_350F8();
    virtual void fn_41_350FC();
    virtual void fn_41_35108();
    virtual void fn_41_3510C();
    virtual void fn_41_13638();
    virtual void fn_41_34F38();
};

struct Modules {
    char pad[0x64];
    soNullable* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_41_B1E8(void*, Object* from, Object* to,
                            unsigned int* ids, int count) {
    if (count < 0 || !ids)
        return;

    soNullable* src = from->accesser->modules->work;
    soNullable* dst = to->accesser->modules->work;

    for (int i = 0; i < count; ++i) {
        unsigned int id = ids[i];
        int type = id >> 28;

        if ((type > 0 && type < 3) ? true : false) {
            switch ((id >> 24) & 15) {
            case 0:
                dst->slot5(src->slot4(id), id);
                break;
            case 1:
                dst->slot13(src->slot12(id), id);
                break;
            case 2:
                dst->slot20(src->slot17(id), id);
                break;
            }
        }
    }
}
