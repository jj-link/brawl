#pragma force_active on

class Work {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
};

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void remove(int, int, int);
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad68[0x20];
    Target* target;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_3A2818(void*, Object* object) {
    if (object->modules->work->getInt(0x10000041) >= 0) {
        int index = object->modules->work->getInt(0x10000041);
        object->modules->target->remove(index, 1, 1);
        object->modules->work->setInt(-1, 0x10000041);
    }
}
