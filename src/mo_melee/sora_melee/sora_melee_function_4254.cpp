#include <so/so_module_accesser.h>
#include <gf/gf_task.h>
#pragma force_active on

namespace Matching {
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
    virtual void slot19(soModuleAccesser*);
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0(int);
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
};
class Class_20E8 {
public:
    virtual void fn_27_1F1B8();
    virtual void fn_27_14068();
    virtual void fn_27_140C0(soModuleAccesser*);
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
};
struct Class_90D8_base { char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38();
    virtual void fn_27_7ADE8();
    virtual void fn_27_7AF98();
};
struct Modules {
    void* p00;
    Class_90D8* p04;
    soNullable* p08;
    void* p0c;
    Class_90D8* p10;
    soNullable* p14;
    soNullable* p18;
    soNullable* p1c;
    soNullable* p20;
    soNullable* p24;
    soNullable* p28;
    soNullable* p2c;
    soNullable* p30;
    soNullable* p34;
    void* p38;
    soNullable* p3c;
    soNullable* p40;
    char pad44[0xc];
    soNullable* p50;
    soNullable* p54;
    void* p58;
    soNullable* p5c;
    soNullable* p60;
    char pad64[8];
    soNullable* p6c;
    Class_20E8* p70;
    char pad74[0x10];
    Class_1250* p84;
    soNullable* p88;
    void* p8c;
    soNullable* p90;
    char pad94[8];
    Class_90D8* p9c;
    void* pa0;
    soNullable* pa4;
    soNullable* pa8;
    soNullable* pac;
    char padb0[8];
    Class_90D8* pb8;
};
}
#define MODULES (reinterpret_cast<const Matching::Modules*>(accesser->m_enumerationStart))

extern "C" void fn_27_4254(gfTask* self, int arg1) {
    soModuleAccesser* accesser = *reinterpret_cast<soModuleAccesser**>(reinterpret_cast<char*>(self) + 0x60);
    MODULES->p6c->slot19(accesser);
    MODULES->p70->fn_27_140C0(accesser);
    MODULES->p40->slot2();
    MODULES->p3c->slot2();
    MODULES->pa8->slot3();
    MODULES->p84->fn_27_140C0(arg1);
    MODULES->p54->slot3();
    MODULES->p9c->fn_27_7AD2C();
    MODULES->p08->slot2();
    MODULES->pac->slot3();
    MODULES->p04->fn_27_7AF98();
    MODULES->p88->slot3();
    MODULES->p50->slot2();
    MODULES->p10->fn_27_7B22C();
    MODULES->p60->slot7();
    MODULES->p90->slot3();
    MODULES->p18->slot12();
    MODULES->p5c->slot2();
    MODULES->pa4->slot2();
    MODULES->p14->slot2();
    MODULES->p1c->slot2();
    MODULES->p20->slot5();
    MODULES->p24->slot3();
    MODULES->p28->slot3();
    MODULES->p2c->slot3();
    MODULES->p30->slot2();
    MODULES->p34->slot2();
    MODULES->pb8->fn_27_7AB10();
    accesser->deactivate();
    self->m_alive = false;
    if (self->unk2C_b0 == true)
        self->unlink();
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(self) + 0x44) = 0;
}
