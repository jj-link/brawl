#include <ft/ft_common_data_accesser.h>
#pragma force_active on

extern "C" const float lbl_27_rodata_1048;
extern "C" const float lbl_27_rodata_104C;

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
    virtual unsigned int fn_27_14D08(int);
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
    virtual void fn_27_16CC0(int, int, int, int, int, float, float);
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
    virtual void fn_27_17688();
    virtual void fn_27_17970();
    virtual void fn_27_17AD0();
    virtual void fn_27_17B18();
    virtual void fn_27_17B94();
    virtual void fn_27_17C10();
    virtual void fn_27_17C90();
    virtual void fn_27_17D0C();
    virtual void fn_27_17D88();
    virtual void fn_27_17E00();
    virtual void fn_27_17E78();
    virtual void fn_27_18170();
    virtual void fn_27_1838C();
    virtual void fn_27_18C40();
    virtual void fn_27_1858C();
    virtual void fn_27_18628();
    virtual void fn_27_18834();
    virtual void fn_27_18C58();
    virtual void fn_27_18A34();
    virtual void fn_27_18AD0();
    virtual void fn_27_1CB24();
    virtual void fn_27_1CB18();
    virtual void fn_27_1CB10();
    virtual void fn_27_1CB00(int);
};

class Class_20E8 {
public:
    virtual void fn_27_1F1B8();
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
    virtual void fn_27_170A8(int, int);
};

struct Ctx {
    char pad[0x60];
    void* moduleAccesser;
    char pad2[0x110 - 0x64];
    int kind;
};

struct Acc {
    char pad[0xd8];
    void* modules;
};

struct Modules {
    char pad[0x8];
    Class_1250* obj1;
    char pad2[0xa8 - 0xc];
    Class_20E8* obj2;
};

extern "C" void fn_27_13C530(Ctx* self, int a, int c) {
    ftData* data = g_ftCommonDataAccesser.getData((ftKind)self->kind);
    int v;
    int val;
    switch (a) {
    case 0:
        v = 7;
        break;
    case 1:
        v = 6;
        break;
    case 2:
        v = 8;
        break;
    case 3:
        v = 9;
        break;
    }
    val = (*(int**)((char*)data + 0x4C))[a];
    if (val != 0) {
        if (((Modules*)((Acc*)self->moduleAccesser)->modules)->obj1->fn_27_14D08(v) == 1) {
            ((Modules*)((Acc*)self->moduleAccesser)->modules)->obj1->fn_27_16CC0(0, v, val, 0, 0, lbl_27_rodata_1048, lbl_27_rodata_104C);
            if (a == 2) {
                ((Modules*)((Acc*)self->moduleAccesser)->modules)->obj1->fn_27_1CB00(1);
            }
            ((Modules*)((Acc*)self->moduleAccesser)->modules)->obj2->fn_27_170A8(1, c);
        }
    }
}
