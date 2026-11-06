#include <types.h>
#pragma force_active on
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21();
    virtual void slot22();
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
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21(int, void*);
};
extern "C" void fn_27_17A4EC(void*, void*);
extern float lbl_27_rodata_26A0;
extern float lbl_27_rodata_26A4;
extern "C" void fn_27_192AF8(void* self, u8* p) {
    fn_27_17A4EC(self, p);
    Object_vptr_0* obj = *(Object_vptr_0**)(*(u8**)(p + 0xd8) + 8);
    int id = obj->slot21();
    float frame = obj->slot12();
    Param param;
    param.id = 0x46;
    param.a = lbl_27_rodata_26A0;
    param.b = lbl_27_rodata_26A4;
    param.c = 0;
    param.d = 0;
    param.e = 0;
    param.f = 0;
    obj->slot30(&param);
    if ((u32)(id - 0x19) <= 1) {
        obj->slot33(id, 0, frame, lbl_27_rodata_26A4);
        obj->slot24(lbl_27_rodata_26A4);
        (*(Status**)(*(u8**)(p + 0xd8) + 0x7c))->slot21(0x4f, p);
    } else {
        (*(Status**)(*(u8**)(p + 0xd8) + 0x7c))->slot21(0x13, p);
    }
}