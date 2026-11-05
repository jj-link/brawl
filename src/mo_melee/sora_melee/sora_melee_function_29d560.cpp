#pragma force_active on

struct Id {
    int value;
};

inline Id makeId(int value) {
    Id id;
    id.value = value;
    return id;
}

class Work {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int query(int, void*);
};

class Modules {
public:
    char pad[0x64];
    Work* work;
};

class Object {
public:
    char pad[0xD8];
    Modules* modules;
};

class Context {
public:
    char pad[0x60];
    Object* object;
};

extern "C" bool fn_27_29D560(int, Context* context) {
    Object* object = context->object;
    return object->modules->work->query(makeId(0x1000000B).value, object) == 0;
}
