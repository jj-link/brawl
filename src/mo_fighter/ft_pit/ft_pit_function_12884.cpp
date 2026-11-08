#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

struct PitTmp { unsigned char flag; Vec3f v; };

extern "C" Vec3f* fn_112_9F54(Vec3f*, float, float, float);
extern "C" void fn_112_12974(void* dst, const void* src);
extern "C" const float lbl_112_rodata_50;
extern "C" const float lbl_112_rodata_54;

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
    virtual float slot12(unsigned int arg);
};

class Object_vptr_void {
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
};

extern "C" void fn_112_12884(void*, void* self, soModuleAccesser* accesser) {
    char* s = (char*)self;
    Object_vptr_void* first = (Object_vptr_void*)*(void**)(*(char**)((char*)accesser + 0xd8) + 0x7c);
    first->slot12();

    Object_vptr_0* obj = (Object_vptr_0*)*(void**)(*(char**)((char*)accesser + 0xd8) + 0x64);
    int c = soValueAccesser::getConstantInt(accesser, 0x5dc1, 0);
    float f31 = (float)c;
    float f1 = obj->slot12(0x21000000);
    float f2 = (lbl_112_rodata_54 * f1) / f31;

    PitTmp tmp;
    tmp.flag = 0;
    fn_112_9F54(&tmp.v, lbl_112_rodata_50, f2, lbl_112_rodata_50);
    fn_112_12974(s + 0x6c, &tmp.v);
    s[0x69] = (unsigned char)(s[0x69] | 0x80);
}
