#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern const float lbl_95_rodata_98;
extern const float lbl_95_rodata_9C;

extern "C" void fn_95_FF04(void* self);
extern "C" void fn_95_100C4(void* self);
extern "C" void fn_95_10704(void* self);
extern "C" void fn_95_1080C(void* self);
extern "C" void fn_95_108CC(void* self);
extern "C" float fn_95_A8B4(float v);
extern "C" int fn_95_FDD8(void* self);
extern "C" int fn_95_FE54(void* self);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(int);
    virtual void slot13(float, int);
};

struct Modules {
    char pad[0x64];
    Object_vptr_0* obj;
};

struct Fighter {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_95_11198(void* unused, Fighter* self) {
    int pad0 = 0;
    int pad1 = 0;
    int pad2 = 0;
    Object_vptr_0* w = self->modules->obj;
    char* common = (char*)g_ftCommonDataAccesser.getData((ftKind)4);
    char* data = *(char**)(common + 0x7C);

    float f30 = w->slot12(0x21000006);
    float f31 = w->slot12(0x21000005);
    w->slot13(lbl_95_rodata_98, 0x21000008);
    fn_95_FF04(self);
    fn_95_100C4(self);
    fn_95_1080C(self);
    fn_95_108CC(self);
    float sum = f31 + lbl_95_rodata_9C * (*(float*)(data + 0x90) * fn_95_A8B4(f30));
    w->slot13(sum, 0x21000005);
    fn_95_10704(self);
    if (fn_95_FDD8(self) != 0) {
        w->slot5(0x11A, 0x20000008);
    }
    if (fn_95_FE54(self) != 0) {
        w->slot13(lbl_95_rodata_98, 0x21000008);
        w->slot5(0x11A, 0x20000008);
    }
}
