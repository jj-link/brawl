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
    virtual void slot19(unsigned long);
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
    int value;
    int zero;
    int padding[3];
};
extern "C" void fn_27_1744D4(void*, void*);
extern "C" void fn_27_174C08(void*, void*, void*);
extern "C" void fn_27_174F14(void* self, Actor* actor) {
    fn_27_1744D4(self, actor);
    *(int*)((char*)self + 0x14) = -1;
    switch (actor->modules->work->slot4(0x10000017)) {
    case 31:
        actor->modules->work->slot5(0, 0x20000000);
        actor->modules->work->slot18(0x22000010);
        break;
    case 32:
        actor->modules->work->slot5(0, 0x20000000);
        actor->modules->work->slot19(0x22000010);
        break;
    case 33:
        actor->modules->work->slot5(1, 0x20000000);
        actor->modules->work->slot18(0x22000010);
        break;
    case 34:
        actor->modules->work->slot5(1, 0x20000000);
        actor->modules->work->slot19(0x22000010);
        break;
    }
    Vec3 pos = actor->modules->pos->get();
    Out out;
    out.a = 2;
    out.b = 0;
    out.pos = *(VecData*)&pos;
    out.zero = 0;
    fn_27_174C08(self, &out, actor);
    actor->modules->work->slot5(out.value, 0x20000002);
    pos.set(*(float*)&out.pos.x, *(float*)&out.pos.y, pos.z);
    actor->modules->pos->set(&pos);
    actor->modules->work->slot18(0x1200003c);
    float value = soValueAccesser::getConstantFloat((soModuleAccesser*)actor, 0xd2d, 0);
    actor->modules->work->slot13(value, 0x11000012);
}