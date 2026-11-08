#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class Mode {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual unsigned int slot6();
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
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual float slot26(void* data, Mode* mode, float value);
};

class soCollisionAttackModuleImpl {
public:
    virtual ~soCollisionAttackModuleImpl();
    virtual void fn_27_39AA4();
    virtual void fn_27_39C34();
    virtual void fn_27_39C90();
    virtual void fn_27_39D10();
    virtual void fn_27_39D80();
    virtual void fn_27_39E30();
    virtual void fn_27_39EF4();
    virtual void fn_27_3A0C4();
    virtual void fn_27_3A270();
    virtual void fn_27_3AF7C();
    virtual void fn_27_3B070();
    virtual void fn_27_3B120();
    virtual void fn_27_3A3C8();
    virtual void fn_27_3A430();
    virtual void fn_27_3A4BC();
    virtual void fn_27_3A504();
    virtual void fn_27_3A600();
    virtual void fn_27_3A664();
    virtual void fn_27_3A6A4();
    virtual void fn_27_3A6D8();
    virtual void fn_27_3A718();
    virtual void fn_27_3AD40();
    virtual void fn_27_3ADDC();
    virtual void fn_27_3AF34();
    virtual void fn_27_3A75C();
    virtual float getPower(u8 index, u8 unk);
    virtual void fn_27_3A960();
    virtual void fn_27_3A994();
    virtual void fn_27_3A9EC();
    virtual void fn_27_3AA50();
    virtual void fn_27_3AAA8();
    virtual void fn_27_3AB0C();
    virtual void fn_27_3AB64();
    virtual void fn_27_3ABC8();
    virtual void fn_27_3A54C();
    virtual void fn_27_3A5A4();
    virtual float getPosX();
    virtual void fn_27_3AC30();
    virtual void fn_27_41464();
    virtual void fn_27_41454();
    virtual void fn_27_41434();
    virtual void* getData(u8 index, u8 unk);
    virtual void fn_27_4142C();
    virtual void fn_27_41424();
    virtual void fn_27_4141C();
    virtual void fn_27_41414();
    virtual void fn_27_4140C();
    virtual void fn_27_4077C();
    virtual void fn_27_41404();
    virtual void fn_27_413FC();
    virtual void fn_27_413F4();
    virtual void fn_27_413EC();
    virtual void fn_27_413E4();
    virtual void fn_27_413D0();
    virtual void fn_27_3B1A8();
    virtual void fn_27_3B3DC();
    virtual void fn_27_3B7FC();
    virtual void fn_27_3BA40();
    virtual void fn_27_3BA48();
    virtual void fn_27_413C8();
    virtual void fn_27_413C0();
    virtual void fn_27_3BA64();
    virtual void fn_27_413B8();
    virtual void fn_27_3BA50();
    virtual void fn_27_413B0();
    virtual void fn_27_3BA84();
    virtual void invalidLog(void* log, u32 groupIndex);
};

struct Modules {
    char pad[0xC8];
    Mode* mode;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Entry {
    char pad[0x24];
    unsigned char arg24;
    char pad25[2];
    unsigned char arg27;
};

extern "C" {
extern float lbl_27_rodata_498;
extern float lbl_27_rodata_4B0;
void* fn_27_8CD44(void*);
void* fn_27_8CDD4(void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* accesser, u32 id, u32 index);

int fn_27_3BAFC(soCollisionAttackModuleImpl* self, Access* accesser, void* task,
                Entry* entry, float* out1, float* out2, float value)
{
    soCollisionAttackModuleImpl* attack = (soCollisionAttackModuleImpl*)fn_27_8CD44(task);
    float power = attack->getPower(entry->arg24, entry->arg27);
    Mode* mode = (Mode*)fn_27_8CDD4(task);
    if (mode->slot6() == 1) {
        if (((Mode*)accesser->modules->mode)->slot6() == 1) {
            power = ((Mode*)accesser->modules->mode)->slot26(
                attack->getData(entry->arg24, entry->arg27), mode, power);
        }
    }
    float limit = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x7f5, 0);
    if (value - limit < power) {
        if (power > value) {
            value = power;
        }
        if (value > *out1) {
            *out1 = value;
            float attackPos = attack->getPosX();
            float selfPos = self->getPosX();
            *out2 = (selfPos < attackPos) ? lbl_27_rodata_498 : lbl_27_rodata_4B0;
        }
    } else {
        self->invalidLog(entry, 0);
        return 0;
    }
    return 1;
}
}