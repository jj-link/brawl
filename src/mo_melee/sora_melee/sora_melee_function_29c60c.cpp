#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern const float lbl_27_rodata_46C8;
extern const float lbl_27_rodata_46DC;

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
    virtual void fn_27_15604();
    virtual void fn_27_16CA8();
    virtual void fn_27_16CB0();
    virtual void fn_27_1CB80();
    virtual void fn_27_16CB8();
    virtual void fn_27_16CC0();
    virtual void fn_27_16E88();
    virtual void fn_27_16FB4();
    virtual void fn_27_170A8();
    virtual void fn_27_171D0();
    virtual void fn_27_1CB6C();
    virtual void fn_27_1CB38();
    virtual void fn_27_17334();
    virtual void fn_27_17374();
    virtual void fn_27_173A8();
    virtual void fn_27_17444();
    virtual void fn_27_17518();
    virtual void fn_27_1754C();
    virtual void fn_27_17584();
    virtual void fn_27_175FC();
    virtual void fn_27_17674();
    virtual void fn_27_17A9C();
    virtual void fn_27_17688(int, int, int, float, float);
    virtual void fn_27_17970();
    virtual void fn_27_17AD0();
    virtual void fn_27_17B18(int, float);
    virtual void fn_27_17B94();
    virtual void fn_27_17C10(int, float);
};

struct Vec3 { float x, y, z; };

class soControllerModuleImpl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int, Vec3*, Vec3*, int, float);
};

extern "C" void fn_27_29C60C(void*, u8* arg1) {
    u8* p = *(u8**)(arg1 + 0x60);
    u8* modules = *(u8**)(p + 0xd8);
    Class_1250* obj = *(Class_1250**)(modules + 8);
    obj->fn_27_17688(0, 1, 0, lbl_27_rodata_46DC, lbl_27_rodata_46C8);
    obj->fn_27_17B18(0, lbl_27_rodata_46DC);
    obj->fn_27_17C10(0, lbl_27_rodata_46DC);
    obj->fn_27_17688(1, 2, 0, lbl_27_rodata_46DC, lbl_27_rodata_46C8);
    obj->fn_27_17B18(1, lbl_27_rodata_46DC);
    if ((u32)((*(u8*)((u8*)g_GameGlobal->getGlobalRecordMenuDatap() + 0x28) >> 7) & 1) == 1)
        obj->fn_27_17C10(1, lbl_27_rodata_46C8);
    else
        obj->fn_27_17C10(1, lbl_27_rodata_46DC);
    Vec3 a, b;
    b.x = lbl_27_rodata_46DC;
    b.y = lbl_27_rodata_46DC;
    b.z = lbl_27_rodata_46DC;
    a.x = lbl_27_rodata_46DC;
    a.y = lbl_27_rodata_46DC;
    a.z = lbl_27_rodata_46DC;
    p = *(u8**)(arg1 + 0x60);
    modules = *(u8**)(p + 0xd8);
    soControllerModuleImpl* effect = *(soControllerModuleImpl**)(modules + 0x88);
    effect->slot7(0x70, &a, &b, 4, lbl_27_rodata_46C8);
}
