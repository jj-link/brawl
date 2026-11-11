#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <math.h>
#pragma force_active on
#pragma opt_propagation off
struct Pair { float x, y; };
class Work {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int get(unsigned int);
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual float getFloat(unsigned int);
    virtual void f13();
    virtual void f14();
    virtual void f15();
};
class Kinetic {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual Pair getSum(const unsigned short&);
};
class TeamValue {
public:
    virtual void f0();
    virtual void f1();
    virtual int get();
};
class Team {
public:
    virtual void f0();
    virtual void f1();
    virtual TeamValue* get();
};
class Object_vptr_0 {
public:
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
    virtual void slot13();
    virtual void slot14();
    virtual int slot15();
};
class Resource {
public:
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Object_vptr_0* get();
};
class Model {
public:
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual int node(const char*);
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual Vec3f position(int, int);
};
class Posture {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual float lr();
};
class Ground {
public:
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual float get();
};

struct Modules {
    Resource* resource;
    Model* model;
    void* motion;
    Posture* posture;
    Ground* ground;
    char pad[4];
    Team* team;
    char pad2[0x48];
    Work* work;
    char pad3[0x14];
    Kinetic* kinetic;
};
struct Stage { char pad[0x28]; int task; };
struct Accesser {
    char pad[8]; Stage* stage; char pad2[0xcc]; Modules* modules;
};
extern "C" {
extern const float lbl_115_rodata_C;
extern const float lbl_115_rodata_10;
extern const char lbl_115_data_8[];
Vec3f* fn_115_8EF8(Vec3f*, float, float, float);
void fn_115_8F08(Vec3f*, const Vec3f*);
void fn_115_168A8(void*, int, int, int, float, const Vec3f*, const Pair*, float, int);
}
extern "C" int fn_115_8BC0(void* object, Accesser* a) {
    float spread = lbl_115_rodata_C;
    Pair speed;
    speed.x = spread;
    speed.y = spread;
    Vec3f pos;
    fn_115_8EF8(&pos, spread, spread, spread);
    float facing = a->modules->posture->lr();
    const char* name = lbl_115_data_8;
    Model* model = a->modules->model;
    Vec3f source = model->position(model->node(name), 0);
    fn_115_8F08(&pos, &source);
    pos.m_z = a->modules->ground->get();
    Resource* resource;
    int task;
    int mode = a->modules->work->get(0x20000002);
    int flag;
    if (mode == 0) {
        flag = 0;
        float radians = lbl_115_rodata_10 * a->modules->work->getFloat(0x21000005);
        spread = (float)cos(radians);
        speed.x = facing * (spread * soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xfaf, 0));
        spread = (float)sin(radians);
        speed.y = spread * soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xfaf, 0);
        spread = (float)a->modules->work->get(0x20000000);
    } else if (mode == 1) {
        unsigned short one = 1;
        Pair v;
        Pair sum = a->modules->kinetic->getSum(one);
        __memcpy(&v, &sum, sizeof(v));
        speed.x = v.x * soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xfb4, 0);
        speed.y = v.y * soValueAccesser::getConstantFloat((soModuleAccesser*)a, 0xfb4, 0);
        spread = (float)a->modules->work->get(0x20000000);
        flag = 0;
    } else {
        flag = 1;
    }
    resource = a->modules->resource;
    task = a->stage->task;
    fn_115_168A8(object, task, resource->get()->slot15(),
                 a->modules->team->get()->get(), facing, &pos, &speed, spread, flag);
    return 0;
}
