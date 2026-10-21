#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3(const Vec3& other)
        : x(other.x), y(other.y), z(other.z) {}
};

struct ModuleBase {
    char unused[8];
};

struct Module : ModuleBase {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual Vec3 get(int);
    virtual void unused70();
    virtual void unused74();
    virtual void unused78();
    virtual void set(int, const Vec3&);
};

struct Work {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual float get(unsigned int);
};

struct Modules {
    char unused[4];
    Module* module;
    char unused08[0x5c];
    Work* work;
};

struct Object {
    char unused[0xd8];
    Modules* modules;
};

extern "C" void fn_27_39A430(void*, Object* object) {
    Vec3 value = object->modules->module->get(1);
    value.x = object->modules->work->get(0x21000002);
    object->modules->module->set(1, value);
}
