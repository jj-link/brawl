#pragma force_active on
#include <ft/ft_common_data_accesser.h>

class Class_6DA4 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10ECC();
    virtual void fn_109_116D8();
    virtual void fn_109_116D4();
    virtual void fn_109_116D0();
    virtual void fn_109_116CC();
    virtual void fn_109_116C4();
    virtual void fn_109_1170C();
    virtual void fn_109_11704();
    virtual void fn_109_116FC();
    virtual void fn_109_116F4();
    virtual void fn_109_116EC();
    virtual void fn_109_11684();
    virtual void fn_109_116B8();
    virtual void fn_109_116AC();
    virtual int fn_109_116A4();
};

struct Fighter {
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Class_6DA4* f4();
};
struct Modules { Fighter* fighter; };
struct Sub { char pad[0x28]; void* resource; };
struct Input {
    char pad[8];
    Sub* sub;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" {
extern float lbl_109_rodata_8;
Vec3f* fn_109_8B54(Vec3f*, float, float, float);
void fn_27_1E1B14(void*, void*, int, void*, bool, bool, Vec3f*, unsigned int,
                 unsigned int, bool, bool, bool, int, bool, bool, int, bool, bool);

int fn_109_8A64(void* self, Input* input) {
    Vec3f position;
    Vec3f* p;
    Fighter* fighter = input->modules->fighter;
    void* resource = input->sub->resource;
    p = fn_109_8B54(&position, lbl_109_rodata_8, lbl_109_rodata_8, lbl_109_rodata_8);
    ftData* data = g_ftCommonDataAccesser.getData((ftKind)0x14);
    int value = fighter->f4()->fn_109_116A4();
    fn_27_1E1B14(self, resource, value, *(void**)((char*)data + 0x90), 1, 0, p, 65535,
                 65535, 0, 1, 0, -1, 0, 0, 2, 0, 0);
    return 1;
}
}
