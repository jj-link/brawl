#include <string.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/collision/so_collision_attack_module_impl.h>
#pragma force_active on
struct Modules {
    char pad[0x1c];
    soCollisionAttackModule* first;
    char pad2[0x44];
    soWorkManageModule* second;
};
struct Accesser {
    char pad[8];
    void* object;
    char pad2[0xcc];
    Modules* modules;
};
extern "C" {
extern const char lbl_96_data_608[], lbl_96_data_68D8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_B3F8(void*);
void* fn_96_B488(void*);
void fn_96_15740(void*);
void* fn_96_14454();
int fn_27_5013C(void*);
}
extern "C" void fn_96_14374(void*, Accesser* a) {
    fn_96_B3F8(__dynamic_cast(a->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1));
    memset(fn_96_B488(__dynamic_cast(a->object, 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1)), 0, 0x9c);
    fn_96_15740(a);
    int id = fn_27_5013C(fn_96_14454());
    a->modules->second->setInt(id, 0x20000005);
    if (id != -1) {
        a->modules->first->refLogGroup(0, id);
    }
}