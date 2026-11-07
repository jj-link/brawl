#include <so/so_value_accesser.h>
#pragma force_active on

struct Vec3 {
    float x, y, z;
    Vec3() {}
    void set(float a, float b, float c) { y = b; x = a; z = c; }
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, unsigned long);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(unsigned long);
};
struct Position {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3 get();
    virtual void set(const Vec3*);
};
struct Modules {
    char pad[0xc];
    Position* pos;
    char pad2[0x54];
    Object_vptr_0* work;
};
struct Actor {
    char pad[0xd8];
    Modules* modules;
};
struct VecData { int x, y, z; };
struct Out {
    int a, b;
    VecData pos;
    int padding[4];
};
extern "C" void fn_27_1744D4(void*, void*);
extern "C" void fn_27_174C08(void*, void*, void*);
extern "C" void fn_27_17835C(void* self, Actor* actor) {
    fn_27_1744D4(self, actor);
    Vec3 pos = actor->modules->pos->get();
    Out out;
    out.a = 0x1c;
    out.b = 0;
    out.pos = *(VecData*)&pos;
    fn_27_174C08(self, &out, actor);
    pos.set(*(float*)&out.pos.x, *(float*)&out.pos.y, pos.z);
    actor->modules->pos->set(&pos);
    actor->modules->work->slot18(0x1200003c);
    float value = soValueAccesser::getConstantFloat((soModuleAccesser*)actor, 0xd2e, 0);
    actor->modules->work->slot13(value, 0x11000012);
}
