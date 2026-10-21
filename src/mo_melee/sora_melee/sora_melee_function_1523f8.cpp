#pragma force_active on
typedef unsigned int u32;

struct WorkModule {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual u32 getInt(u32);
};

struct ModuleAccesser {
    unsigned char padding[0x64];
    WorkModule* work;
};

struct Object {
    unsigned char padding[0xD8];
    ModuleAccesser* modules;
};

extern "C" int fn_27_632AC(void*, Object*, float, float);

extern "C" int fn_27_1523F8(void* self, Object* object, float a, float b) {
    if (object->modules->work->getInt(0x12000018) == 1)
        return 3;
    return fn_27_632AC(self, object, a, b);
}
