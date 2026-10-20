#pragma force_active on
class WorkModule {
public:
    virtual void entry08();
    virtual void entry0C();
    virtual void entry10();
    virtual void entry14();
    virtual int getInt(int);
};

class TargetModule {
public:
    virtual void entry08();
    virtual void entry0C();
    virtual void entry10();
    virtual void apply(int, void*);
};

struct Modules {
    unsigned char pad[0x64];
    WorkModule* work;
    unsigned char pad68[8];
    TargetModule* target;
};

struct Object {
    unsigned char pad[0xD8];
    Modules* modules;

    WorkModule& getWork() const {
        return *modules->work;
    }

    TargetModule& getTarget() const {
        return *modules->target;
    }
};

extern "C" void fn_95_134A4(void*, Object* object) {
    WorkModule* work = &object->getWork();
    TargetModule* target = &object->getTarget();
    int value = work->getInt(0x20000008);
    if (value != -1) {
        target->apply(value, object);
    }
}
