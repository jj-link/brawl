#pragma force_active on
typedef unsigned char Byte;
class Class_6EB8 {
public:
    virtual void fn_116_DEEC();
    virtual void fn_116_DD40();
    virtual void fn_116_DD48();
    virtual void fn_116_DD44();
    virtual void fn_116_DEE8();
    virtual void fn_116_DEE4();
    virtual void fn_116_DEE0();
    virtual void fn_116_DEDC();
    virtual void fn_116_DED8();
    virtual void fn_116_DED0();
    virtual void fn_116_DECC();
};
class Class_744C {
public:
    virtual void fn_116_7384();
    virtual void fn_116_10218();
    virtual void fn_116_11388();
    virtual void fn_116_11384();
    virtual void fn_116_11380();
    virtual void fn_116_1137C();
    virtual void fn_116_11374();
    virtual void fn_116_113BC();
    virtual void fn_116_113B4();
    virtual void fn_116_113AC();
    virtual void fn_116_113A4();
};
class Class_7624 {
public:
    virtual void fn_116_7384();
    virtual void fn_116_101BC();
    virtual void fn_116_11518();
    virtual void fn_116_11510();
    virtual void fn_116_11508();
    virtual void fn_116_11500();
    virtual void fn_116_114F8();
    virtual void fn_116_114F0();
    virtual void fn_116_114E8();
    virtual void fn_116_114E0();
    virtual void fn_116_114D8();
};
class Class_7CB8 {
public:
    virtual void fn_116_13D34();
    virtual void fn_116_13BA8();
    virtual void fn_116_DF2C();
    virtual void fn_116_13C10();
    virtual void fn_116_DEE8();
    virtual void fn_116_DEE4();
    virtual void fn_116_DEE0();
    virtual void fn_116_DEDC();
    virtual void fn_116_DED8();
    virtual void fn_116_DED0();
    virtual void fn_116_DECC();
};
class Class_9944 {
public:
    virtual void fn_116_1B5A4();
    virtual void fn_116_1AFE0();
    virtual void fn_116_1B3F4();
    virtual void fn_116_1B198();
    virtual void fn_116_DEE8();
    virtual void fn_116_DEE4();
    virtual void fn_116_DEE0();
    virtual void fn_116_DEDC();
    virtual void fn_116_DED8();
    virtual void fn_116_1B45C();
    virtual void fn_116_DECC();
};
class Class_C008 {
public:
    virtual void fn_116_23EB4();
    virtual void fn_116_23BA4();
    virtual void fn_116_DF2C();
    virtual void fn_116_23BA8();
    virtual void fn_116_DEE8();
    virtual void fn_116_DEE4();
    virtual void fn_116_DEE0();
    virtual void fn_116_DEDC();
    virtual void fn_116_DED8();
    virtual void fn_116_DED0();
    virtual void fn_116_DECC();
};
class ModuleInterface {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10(void*) = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
};
class WorkInterface {
    Byte storage[8];
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
};
extern "C" {
void fn_27_C74BC(void*, void*, int);
void fn_116_8494(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_116_796C(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3304(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_116_data_0[];
}
extern "C" Byte* fn_116_810C(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_116_8494(work + 0x88, work, 0x12, work + 0x48, 0xE, work + 0x80, 2);
    reinterpret_cast<WorkInterface*>(work + 0x88)->slot25();
    Byte* modules = object + 0xBC;
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
    fn_116_796C(modules + 0x85C, modules);
    for (int i = 0; i < 20; ++i) {
        Byte entry[20];
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
        reinterpret_cast<ModuleInterface*>(modules)->slot10(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A3304(object + 0x930, 0);
    *reinterpret_cast<Byte**>(object + 0xDA0) = object + 0xDA4;
    fn_27_1A29F0(object + 0xDA4, 1, lbl_116_data_0, 0);
    reinterpret_cast<ModuleInterface*>(object + 0xDA4)->slot13();
    fn_27_73930(object + 0xDB4, owner, object, object + 0x930,
        object + 0x98, object + 0x918, object + 0xDA0, parameters, 0x119, 1);
    return object;
}