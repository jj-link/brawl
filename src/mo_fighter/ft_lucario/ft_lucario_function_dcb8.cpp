#pragma force_active on
struct Module {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual int getKind();
    virtual void slot18();
    virtual void slot1C();
    virtual void* getEnergy(int);
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual int isFlag(unsigned long);
};

struct Modules {
    char pad00[0x14];
    Module* situation;
    char pad18[0x4c];
    Module* work;
    char pad68[0x14];
    Module* kinetic;
};

struct soModuleAccesser {
    char pad00[0xd8];
    Modules* modules;

    Module& getWorkModule() const { return *modules->work; }
    Module& getKineticModule() const { return *modules->kinetic; }
};

struct Energy {
    char pad00[0x10];
    float value;
};

struct Vec2f {
    float x, y;
};

extern "C" {
extern const char lbl_118_data_6708[];
extern const char lbl_118_data_17B0[];
extern const char lbl_118_data_620C[];
extern const float lbl_118_rodata_30;

void* __dynamic_cast(void*, long, const void*, const void*, short);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
void fn_118_C3EC(void*, const Vec2f*);
}

extern "C" void fn_118_DCB8(void*, soModuleAccesser* accesser) {
    Module* situation = accesser->modules->situation;
    if (situation->getKind() == 2) {
        Module& work = accesser->getWorkModule();
        Module& kinetic = accesser->getKineticModule();

        if (work.isFlag(0x22000011)) {
            Energy* energy = static_cast<Energy*>(__dynamic_cast(
                kinetic.getEnergy(1), 0,
                lbl_118_data_6708, lbl_118_data_17B0, 1));
            energy->value =
                -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0xfba, 0);
        } else {
            Energy* energy = static_cast<Energy*>(__dynamic_cast(
                kinetic.getEnergy(1), 0,
                lbl_118_data_6708, lbl_118_data_17B0, 1));
            energy->value = lbl_118_rodata_30;
        }

        void* energy = __dynamic_cast(
            kinetic.getEnergy(3), 0,
            lbl_118_data_620C, lbl_118_data_17B0, 1);

        Vec2f speed;
        speed.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0xfb9, 0);
        speed.y = lbl_118_rodata_30;
        fn_118_C3EC(static_cast<char*>(energy) + 0x20, &speed);
    }
}
