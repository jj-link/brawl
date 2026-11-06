#include <it/it_manager.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual float fn_27_14A28();
    virtual void fn_27_14A30(float);
};

class Class_1F90 {
public:
    virtual void fn_27_1EFD0();
    virtual void fn_27_E240();
    virtual void fn_27_E190();
    virtual void fn_27_E1A0();
    virtual int fn_27_1D2D0(unsigned int);
    virtual void fn_27_1D200();
    virtual void fn_27_1D240();
    virtual void fn_27_1EF00();
};

struct Modules {
    char pad0[8];
    Class_1250* motion;
    char pad1[0x64 - 0xc];
    Class_1F90* work;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern float lbl_27_rodata_25F8;
extern float lbl_27_rodata_25FC;

extern "C" void fn_27_18E804(void*, Object* obj) {
    if (lbl_27_rodata_25F8 == obj->modules->motion->fn_27_14A28()) {
        int id = obj->modules->work->fn_27_1D2D0(0x10000030);
        if (id != 0) {
            if (itManager::getInstance()->getItemFromInstanceId(id) == 0) {
                obj->modules->motion->fn_27_14A30(lbl_27_rodata_25FC);
            }
        } else {
            obj->modules->motion->fn_27_14A30(lbl_27_rodata_25FC);
        }
    }
}
