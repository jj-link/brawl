#pragma force_active on
struct Vec2 {
    Vec2(const Vec2& o) : x(o.x), y(o.y) {}
    Vec2() {}
    float x;
    float y;
};

struct WorkA {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec2 slot6();
};

struct WorkB {
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
    virtual void setValue(unsigned int, float);
};

struct Modules {
    char padding[0xC];
    WorkA* a;
    char padding2[0x64 - 0x10];
    WorkB* b;
};

struct Object {
    char padding[0xD8];
    Modules* modules;
};

extern "C" void fn_27_177BB0(void*, Object* object) {
    Vec2 v = object->modules->a->slot6();
    object->modules->b->setValue(0x21000006, v.x);
    object->modules->b->setValue(0x21000007, v.y);
    object->modules->b->setValue(0x21000008, v.x);
    object->modules->b->setValue(0x21000009, v.y);
}
