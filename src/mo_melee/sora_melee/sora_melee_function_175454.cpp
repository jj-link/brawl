#pragma force_active on
typedef unsigned int u32;

class WorkModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual u32 get(u32);
};

struct Modules {
    char padding[0x64];
    WorkModule* work;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

extern "C" u32 fn_27_175454(void*, Object* object) {
    return object->modules->work->get(0x20000000);
}
