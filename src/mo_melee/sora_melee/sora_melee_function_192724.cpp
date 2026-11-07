#include <types.h>
#include <so/so_value_accesser.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

#define V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)
struct ObjectBase { char pad[0x3c]; };
struct Obj : ObjectBase {
    V32(a) V32(b) V32(c) V32(d) V32(e) V8(f0) V8(f1) V8(f2)
    virtual void h184();
    virtual int get();
};
struct Param { int id; float a, b; u8 c, d, e, f; };
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
    virtual float slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float slot16();
    virtual void slot17();
    virtual float slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21();
    virtual bool slot22();
    virtual void slot23();
    virtual void slot24(float);
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(Param*);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33(int, int, float, float);
};
class Status {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(int, void*);
};
extern "C" {
void fn_27_169900(void*, void*);
void fn_27_1D6434(int, int, int, int, void*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_69C0[], lbl_27_data_248[];
extern float lbl_27_rodata_2698, lbl_27_rodata_269C;
}
extern "C" void fn_27_192724(void* self, u8* p) {
    fn_27_169900(self, p);
    Object_vptr_0* obj = *(Object_vptr_0**)(*(u8**)(p + 0xd8) + 8);
    Object_vptr_0* controller = *(Object_vptr_0**)(*(u8**)(p + 0xd8) + 0x5c);
    int id = obj->slot21();
    float frame = obj->slot12();
    float x = controller->slot16();
    float y = controller->slot18();
    float lr = (*(Object_vptr_0**)(*(u8**)(p + 0xd8) + 0xc))->slot9();
    int motion, effect;
    if (nw4r::ut::Abs(x) < soValueAccesser::getConstantFloat((soModuleAccesser*)p, 0xc5c, 0) &&
        nw4r::ut::Abs(y) < soValueAccesser::getConstantFloat((soModuleAccesser*)p, 0xc5d, 0)) {
        motion = 0x62; effect = 0xe;
    } else if (controller->slot22()) {
        if (x * lr >= lbl_27_rodata_2698) { motion = 0x63; effect = 0xf; }
        else { motion = 0x64; effect = 0x10; }
    } else {
        if (y >= lbl_27_rodata_2698) { motion = 0x65; effect = 0x11; }
        else { motion = 0x66; effect = 0x12; }
    }
    Param param;
    param.id = motion;
    param.a = lbl_27_rodata_2698;
    param.b = lbl_27_rodata_269C;
    param.c = 0; param.d = 0; param.e = 0; param.f = 0;
    obj->slot30(&param);
    if ((u32)(id - 0x19) <= 1) {
        obj->slot33(id, 0, frame, lbl_27_rodata_269C);
        obj->slot24(lbl_27_rodata_269C);
        (*(Status**)(*(u8**)(p + 0xd8) + 0x7c))->slot21(0x4f, p);
    } else {
        (*(Status**)(*(u8**)(p + 0xd8) + 0x7c))->slot21(0x13, p);
    }
    Obj* cast = (Obj*)__dynamic_cast(*(void**)(p + 8), 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    int value = cast->get();
    fn_27_1D6434(2, effect, 0, value, p);
}