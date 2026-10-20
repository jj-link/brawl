#pragma force_active on
struct Vec3 {
    float x, y, z;
};

class PositionModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 getPosition();
};

struct Modules {
    char unused[0x0C];
    PositionModule* position;
};

struct Context {
    char unused[0xD8];
    Modules* modules;
};

class Object {
public:
    virtual void slot0();
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void setPosition(int, const Vec3*);

    char unused[0x10];
    unsigned char high : 2;
    unsigned char enabled : 1;
    unsigned char low : 5;
};

extern "C" void fn_27_B48F4(Object* self, int arg, Context* context) {
    if (self->enabled) {
        const Vec3& value = context->modules->position->getPosition();
        self->setPosition(arg, &value);
    }
}
