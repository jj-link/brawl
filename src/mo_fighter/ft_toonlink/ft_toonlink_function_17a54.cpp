#include <ft/ft_common_data_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int slot13();
};

struct Fighter {
    char pad[8];
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Object_vptr_0* f4();
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
extern float lbl_121_rodata_C0;
Vec3f* fn_121_AC08(Vec3f*, float, float, float);
void fn_27_1E1B14(void*, void*, int, void*, bool, bool, Vec3f*, unsigned int,
                 unsigned int, bool, bool, bool, int, bool, bool, int, bool, bool);

int fn_121_17A54(void* self, Input* input) {
    Vec3f position;
    Vec3f* p;
    Fighter* fighter = input->modules->fighter;
    void* resource = input->sub->resource;
    p = fn_121_AC08(&position, lbl_121_rodata_C0, lbl_121_rodata_C0, lbl_121_rodata_C0);
    ftData* data = g_ftCommonDataAccesser.getData((ftKind)0x29);
    int value = fighter->f4()->slot13();
    fn_27_1E1B14(self, resource, value, *(void**)((char*)data + 0xc4), 1, 0, p, 65535,
                 65535, 0, 1, 0, -1, 0, 0, 2, 0, 0);
    return 1;
}
}