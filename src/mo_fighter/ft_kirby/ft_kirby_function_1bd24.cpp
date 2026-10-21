#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3() {}

    Vec3& operator=(const Vec3& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

struct ModelModule {
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
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual Vec3 getPosition(int, bool, bool);
};

struct ModuleTable {
    char padding[0x54];
    ModelModule* model;
};

struct soModuleAccesser {
    char padding[0xD8];
    ModuleTable* modules;
};

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" Vec3 fn_96_1BD24(soModuleAccesser* accessor) {
    Vec3 position = accessor->modules->model->getPosition(6, false, false);
    position.x += getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accessor, 0xFC2, 0);
    position.y += getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
        accessor, 0xFC3, 0);
    return position;
}
