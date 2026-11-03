#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;

// Classes this function calls through, from the game's vtables. Keep every method in this order so
// the vtable offsets come out the same; declare parameters and return types as the code needs.

// vtable at 0x7038: 14 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_7038 {
public:
    virtual void fn_120_E048();  // offset 0x8
    virtual void fn_120_CFBC();  // offset 0xc
    virtual void fn_120_DF5C();  // offset 0x10
    virtual void fn_120_D4E0();  // offset 0x14
    virtual void fn_120_DE84();  // offset 0x18
    virtual void fn_120_E044();  // offset 0x1c
    virtual void fn_120_E040();  // offset 0x20
    virtual void fn_120_E03C();  // offset 0x24
    virtual void fn_120_E038();  // offset 0x28
    virtual void fn_120_E030();  // offset 0x2c
    virtual void fn_120_E02C();  // offset 0x30
};

// vtable at 0x70d0: 14 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_70D0 {
public:
    virtual void fn_120_EE1C();  // offset 0x8
    virtual void fn_120_E0E8();  // offset 0xc
    virtual void fn_120_E4C4();  // offset 0x10
    virtual void fn_120_E368();  // offset 0x14
    virtual void fn_120_E4C0();  // offset 0x18
    virtual void fn_120_E044();  // offset 0x1c
    virtual void fn_120_E040();  // offset 0x20
    virtual void fn_120_E3B4();  // offset 0x24
    virtual void fn_120_E038();  // offset 0x28
    virtual void fn_120_E030();  // offset 0x2c
    virtual void fn_120_E02C();  // offset 0x30
};

// vtable at 0x7150: 14 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_7150 {
public:
    virtual void fn_120_F174();  // offset 0x8
    virtual void fn_120_EEB4();  // offset 0xc
    virtual void fn_120_F10C();  // offset 0x10
    virtual void fn_120_EFB8();  // offset 0x14
    virtual void fn_120_E088();  // offset 0x18
    virtual void fn_120_E044();  // offset 0x1c
    virtual void fn_120_E040();  // offset 0x20
    virtual void fn_120_EFFC();  // offset 0x24
    virtual void fn_120_E038();  // offset 0x28
    virtual void fn_120_E030();  // offset 0x2c
    virtual void fn_120_E02C();  // offset 0x30
};

// vtable at 0x71d0: 14 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_71D0 {
public:
    virtual void fn_120_FA10();  // offset 0x8
    virtual void fn_120_F20C();  // offset 0xc
    virtual void fn_120_FA0C();  // offset 0x10
    virtual void fn_120_F7F8();  // offset 0x14
    virtual void fn_120_E088();  // offset 0x18
    virtual void fn_120_E044();  // offset 0x1c
    virtual void fn_120_E040();  // offset 0x20
    virtual void fn_120_F93C();  // offset 0x24
    virtual void fn_120_E038();  // offset 0x28
    virtual void fn_120_E030();  // offset 0x2c
    virtual void fn_120_E02C();  // offset 0x30
};

// vtable at 0x7250: 14 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_7250 {
public:
    virtual void fn_120_1038C();  // offset 0x8
    virtual void fn_120_FAA8();  // offset 0xc
    virtual void fn_120_101F8();  // offset 0x10
    virtual void fn_120_FDAC();  // offset 0x14
    virtual void fn_120_E088();  // offset 0x18
    virtual void fn_120_E044();  // offset 0x1c
    virtual void fn_120_E040();  // offset 0x20
    virtual void fn_120_FE90();  // offset 0x24
    virtual void fn_120_E038();  // offset 0x28
    virtual void fn_120_E030();  // offset 0x2c
    virtual void fn_120_E02C();  // offset 0x30
};

// vtable at 0x72c8: 14 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_72C8 {
public:
    virtual void fn_120_10570();  // offset 0x8
    virtual void fn_120_10444();  // offset 0xc
    virtual void fn_120_104D0();  // offset 0x10
    virtual void fn_120_104CC();  // offset 0x14
    virtual void fn_120_E088();  // offset 0x18
    virtual void fn_120_E044();  // offset 0x1c
    virtual void fn_120_E040();  // offset 0x20
    virtual void fn_120_E03C();  // offset 0x24
    virtual void fn_120_E038();  // offset 0x28
    virtual void fn_120_E030();  // offset 0x2c
    virtual void fn_120_E02C();  // offset 0x30
};

// vtable at 0x782c: 18 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_782C {
public:
    virtual void fn_120_5CB0();  // offset 0x8
    virtual void fn_120_120CC();  // offset 0xc
    virtual void fn_120_13B3C();  // offset 0x10
    virtual void fn_120_13B38();  // offset 0x14
    virtual void fn_120_13B34();  // offset 0x18
    virtual void fn_120_13B30();  // offset 0x1c
    virtual void fn_120_13B28();  // offset 0x20
    virtual void fn_120_13B70();  // offset 0x24
    virtual void fn_120_13B68();  // offset 0x28
    virtual void fn_120_13B60();  // offset 0x2c
    virtual void fn_120_13B58();  // offset 0x30
};

// vtable at 0x7a04: 21 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 10
class Class_7A04 {
public:
    virtual void fn_120_5CB0();  // offset 0x8
    virtual void fn_120_12188();  // offset 0xc
    virtual void fn_120_13D28();  // offset 0x10
    virtual void fn_120_13D20();  // offset 0x14
    virtual void fn_120_13D18();  // offset 0x18
    virtual void fn_120_13D10();  // offset 0x1c
    virtual void fn_120_13D08();  // offset 0x20
    virtual void fn_120_13D00();  // offset 0x24
    virtual void fn_120_13CF8();  // offset 0x28
    virtual void fn_120_13CF0();  // offset 0x2c
    virtual void fn_120_13CE8();  // offset 0x30
};

class ModuleInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void append(void*) = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void initialize() = 0;
};

struct RobotWorkPrefix {
    Word header[2];
};

class RobotWorkInterface : public RobotWorkPrefix {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void initialize() = 0;
};

extern "C" {
void fn_27_C74BC(void*, void*, int);
void* fn_120_6DC0(void*, void*, int, void*, int, void*, int);
void fn_120_6298(void*, void*);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3714(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_120_data_0[];
}

extern "C" Byte* fn_120_6A38(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_120_6DC0(work + 0xA0, work, 0x12, work + 0x48, 0xE, work + 0x80, 8);
    reinterpret_cast<RobotWorkInterface*>(work + 0xA0)->initialize();

    Byte* modules = object + 0xD4;
    fn_27_19E930(modules, 0);
    Byte* entries = modules + 0x19C;
    fn_27_1A154C(entries, 0);
    fn_27_1A1E04(entries + 0x1C, 0);
    fn_27_1A1B1C(entries + 0x88, 0);
    fn_27_D2898(entries + 0xB4, 0);
    fn_27_1A1B1C(entries + 0xF0, 0);
    fn_27_1A154C(entries + 0x11C, 0);
    fn_27_1A154C(entries + 0x138, 0);
    fn_27_D2898(entries + 0x154, 0);
    fn_27_1A1E04(entries + 0x190, 0);
    fn_27_1A154C(entries + 0x1FC, 0);
    fn_27_1A1B1C(entries + 0x218, 0);
    fn_27_1A1F78(entries + 0x244, 0);
    fn_27_1A1B1C(entries + 0x2D0, 0);
    fn_27_1A154C(entries + 0x2FC, 0);
    fn_27_D2898(entries + 0x318, 0);
    fn_27_1A1834(entries + 0x354, 0);
    fn_27_1A154C(entries + 0x470, 0);
    fn_27_1A1B1C(entries + 0x48C, 0);
    fn_27_1A1E04(entries + 0x4B8, 0);
    fn_27_1A1C90(entries + 0x524, 0);
    fn_120_6298(modules + 0x85C, modules);
    for (int i = 0; i < 20; ++i) {
        Word entry[5];
        fn_27_AB15C(entry,
            i == 0 ? modules + 0x6C0 :
            i == 1 ? modules + 0x654 :
            i == 2 ? modules + 0x628 :
            i == 3 ? modules + 0x60C :
            i == 4 ? modules + 0x4F0 :
            i == 5 ? modules + 0x4B4 :
            i == 6 ? modules + 0x498 :
            i == 7 ? modules + 0x46C :
            i == 8 ? modules + 0x3E0 :
            i == 9 ? modules + 0x3B4 :
            i == 10 ? modules + 0x398 :
            i == 11 ? modules + 0x32C :
            i == 12 ? modules + 0x2F0 :
            i == 13 ? modules + 0x2D4 :
            i == 14 ? modules + 0x2B8 :
            i == 15 ? modules + 0x28C :
            i == 16 ? modules + 0x250 :
            i == 17 ? modules + 0x224 :
            i == 18 ? modules + 0x1B8 :
            i == 19 ? modules + 0x19C : 0);
        reinterpret_cast<ModuleInterface*>(modules)->append(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A3714(object + 0x948, 0);
    *reinterpret_cast<Byte**>(object + 0xDCC) = object + 0xDD0;
    fn_27_1A29F0(object + 0xDD0, 1, lbl_120_data_0, 0);
    reinterpret_cast<ModuleInterface*>(object + 0xDD0)->initialize();
    fn_27_73930(object + 0xDE0, owner, object, object + 0x948,
        object + 0xB0, object + 0x930, object + 0xDCC, parameters, 0x11E, 1);
    return object;
}
