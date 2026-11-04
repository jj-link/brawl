#include <so/so_value_accesser.h>
#pragma force_active on

struct Bounds { float left, right, top, bottom; };

namespace enemy {
class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
    virtual void fn_41_135B0();
    virtual void fn_41_135A4();
    virtual void fn_41_135A0();
};
class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual const Bounds* slot9();
    virtual void slot10(const Bounds&);
    virtual void slot11();
    virtual void slot12();
};
}
class Class_6E20 {
public:
    virtual void fn_41_3516C();
    virtual void fn_41_34F30();
    virtual void fn_41_350A4();
    virtual void fn_41_350AC(void*);
    virtual void fn_41_350B4();
    virtual void fn_41_350BC();
    virtual void fn_41_350DC();
    virtual void fn_41_350C4();
    virtual void fn_41_35120();
    virtual void fn_41_350CC();
    virtual void fn_41_350D4();
    virtual void fn_41_350E4();
    virtual void fn_41_350EC();
};
struct EnemyModules {
    char pad[0x90];
    void* area;
    enemy::soNullable* territory;
    enemy::soNullable* target;
};
extern "C" {
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_41_3678(void*);
void fn_41_2343C(void*);
void fn_41_23508(void*);
void fn_41_28E00(void*);
}
extern const float lbl_41_rodata_18;

extern "C" void fn_41_3428(char* self) {
    enemy::soNullable* territory;
    enemy::soNullable* target;
    Class_6E20* camera;
    void* area;
    EnemyModules* mods = *(EnemyModules**)(self + 0x1b4);
    area = __dynamic_cast(mods->area, 0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);
    mods = *(EnemyModules**)(self + 0x1b4);
    territory = mods->territory;
    target = mods->target;
    char* enumeration = *(char**)(*(char**)(self + 0x60) + 0xd8);
    camera = *(Class_6E20**)(enumeration + 0x60);
    (*(enemy::soAnimCmdEventObserver**)(enumeration + 0xc))->fn_41_135A0();
    float scale = fn_41_3678(self);
    float x = soValueAccesser::getValueFloat((soModuleAccesser*)(self + 0xdc), 0xbf6, 0);
    float y = soValueAccesser::getValueFloat((soModuleAccesser*)(self + 0xdc), 0xbf7, 0);
    Bounds bounds = *territory->slot9();
    if (lbl_41_rodata_18 != -x) {
        float delta = -x * scale;
        bounds.left += delta;
    }
    if (lbl_41_rodata_18 != x) {
        float delta = x * scale;
        bounds.right += delta;
    }
    if (lbl_41_rodata_18 != y) {
        float delta = y * scale;
        bounds.top += delta;
    }
    if (lbl_41_rodata_18 != -y) {
        float delta = -y * scale;
        bounds.bottom += delta;
    }
    territory->slot10(bounds);
    territory->slot2();
    target->slot2();
    fn_41_2343C(area);
    fn_41_23508(area);
    fn_41_28E00(self + 0x1108);
    void* data = soValueAccesser::getConstantIndefinite((soModuleAccesser*)(self + 0xdc), 0xa811, 0);
    if (data && soValueAccesser::getValueInt((soModuleAccesser*)(self + 0xdc), 0x59fb, 0) == 1) {
        camera->fn_41_350AC(data);
    }
}
