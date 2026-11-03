#include <ft/ft_common_data_accesser.h>
#pragma force_active on



class Class_80C0 {
public:
    virtual void fn_93_F2AC();
    virtual void fn_93_F26C();
    virtual void fn_93_F2A8();
    virtual void fn_93_F270();
    virtual void fn_93_F2A4();
    virtual void fn_93_F2A0();
    virtual void fn_93_F29C();
    virtual void fn_93_F298();
    virtual void fn_93_F294();
    virtual void fn_93_F28C();
    virtual void fn_93_F288();
    virtual void fn_93_F280();
    virtual void fn_93_F27C();
    virtual int fn_93_F274();
};
struct Fighter {
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Class_80C0* f4();
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
extern float lbl_93_rodata_C0;
Vec3f* fn_93_AC0C(Vec3f*, float, float, float);
void fn_27_1E1B14(void*, void*, int, void*, bool, bool, Vec3f*, unsigned int,
                 unsigned int, bool, bool, bool, int, bool, bool, int, bool, bool);
int fn_93_17A08(void* self, Input* input) {
    Vec3f* p;
    Fighter* fighter = input->modules->fighter;
    void* resource = input->sub->resource;
    Vec3f position;
    p = fn_93_AC0C(&position, lbl_93_rodata_C0, lbl_93_rodata_C0, lbl_93_rodata_C0);
    ftData* data = g_ftCommonDataAccesser.getData((ftKind)2);
    int value = fighter->f4()->fn_93_F274();
    fn_27_1E1B14(self, resource, value, *(void**)((char*)data + 0xc4), 1, 0, p, 65535,
                 65535, 0, 1, 0, -1, 0, 0, 2, 0, 0);
    return 1;
}
}