#pragma force_active on
struct Param {
    int a;
    bool b;
    int c;
    int d;
    bool e;
    Param() : a(0x33), b(false), c(0), d(0), e(false) {}
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int);
    virtual bool slot9(int);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15(int, Param*);
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int);
};
struct Modules {
    char pad[0x54];
    soNullable* a;
    char pad2[0xc];
    soNullable* b;
};
struct Info {
    char pad[0x28];
    int value;
};
struct Object {
    char pad[8];
    Info* info;
    char pad2[0xcc];
    Modules* modules;
};
extern "C" void fn_27_191644(void*, Object* object, int kind) {
    if (kind != 0x101) {
        if (object->modules->a->slot9(4)) {
            if (kind != 0 && kind != 0xe) {
                Param param;
                param.c = object->info->value;
                param.e = true;
                object->modules->a->slot15(4, &param);
            }
            object->modules->a->slot8(4);
        }
        if (object->modules->a->slot9(5)) {
            object->modules->a->slot8(5);
        }
        object->modules->b->slot19(0x12000001);
    }
}