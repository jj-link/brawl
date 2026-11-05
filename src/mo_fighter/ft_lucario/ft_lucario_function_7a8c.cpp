#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;
class Class_63D0 {
public:
    virtual void fn_118_D9F0();
    virtual void fn_118_D72C();
    virtual void fn_118_D92C();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_D790();
    virtual void fn_118_D9DC();
    virtual void fn_118_D94C();
    virtual void fn_118_D9D8(void*);
};
class Class_644C {
public:
    virtual void fn_118_DA34();
    virtual void fn_118_D720();
    virtual void fn_118_D728();
    virtual void fn_118_D724();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_DA30();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_64E0 {
public:
    virtual void fn_118_10178();
    virtual void fn_118_EFE0();
    virtual void fn_118_F114();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_DA30();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_6560 {
public:
    virtual void fn_118_101B8();
    virtual void fn_118_EE58();
    virtual void fn_118_EFD8();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_EF08();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_65E0 {
public:
    virtual void fn_118_101F8();
    virtual void fn_118_DE38();
    virtual void fn_118_E8A0();
    virtual void fn_118_E498();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_E934();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_665C {
public:
    virtual void fn_118_10238();
    virtual void fn_118_DAFC();
    virtual void fn_118_DA74();
    virtual void fn_118_DCB8();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_DA30();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_6718 {
public:
    virtual void fn_118_109A8();
    virtual void fn_118_10534();
    virtual void fn_118_DA74();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_DA30();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_6798 {
public:
    virtual void fn_118_109E8();
    virtual void fn_118_104F0();
    virtual void fn_118_DA74();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_DA30();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};
class Class_6818 {
public:
    virtual void fn_118_10A28();
    virtual void fn_118_10354();
    virtual void fn_118_DA74();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_DA30();
    virtual void fn_118_D9DC();
    virtual void fn_118_D9BC();
    virtual void fn_118_D9D8(void*);
};

struct WorkPrefix { Word storage[2]; };
class WorkInterface : public WorkPrefix {
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
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
};
class StatusVirtual {
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
};
extern "C" {
void fn_27_C74BC(void*, void*, int);
void fn_118_7E14(void*, void*, unsigned int, void*, unsigned int, void*, unsigned int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_118_72EC(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3E30(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_118_data_0[];
}

extern "C" void* fn_118_7A8C(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_118_7E14(work + 0x88, work, 18, work + 0x48, 14, work + 0x80, 2);
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
    fn_118_72EC(modules + 0x85C, modules);
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
        reinterpret_cast<Class_63D0*>(modules)->fn_118_D9D8(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A3E30(object + 0x930, 0);
    *reinterpret_cast<Byte**>(object + 0xDD0) = object + 0xDD4;
    fn_27_1A29F0(object + 0xDD4, 1, lbl_118_data_0, 0);
    reinterpret_cast<StatusVirtual*>(object + 0xDD4)->slot13();
    fn_27_73930(object + 0xDE4, owner, object, object + 0x930,
        object + 0x98, object + 0x918, object + 0xDD0, parameters, 0x125, 1);
    return object;
}
