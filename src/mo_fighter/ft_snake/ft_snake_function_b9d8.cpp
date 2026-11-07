#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;

class ModuleInterface {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void append(void*);
};

class WorkInterface {
    Byte storage[8];
public:
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void initialize();
};

class StatusVirtual {
public:
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C();
};

extern "C" {
void fn_27_C74BC(void*, void*, int);
void* fn_122_BD60(void*, void*, int, void*, int, void*, int);
void fn_122_B19C(void*, void*);
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
void fn_27_1A4448(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_122_data_0[];

void* fn_122_B9D8(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_122_BD60(work + 0x88, work, 0x12, work + 0x48, 0xE, work + 0x80, 2);
    reinterpret_cast<WorkInterface*>(work + 0x88)->initialize();
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
    fn_122_B19C(modules + 0x85C, modules);
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
    fn_27_1A4448(object + 0x930, 0);
    *reinterpret_cast<Byte**>(object + 0xE10) = object + 0xE14;
    fn_27_1A29F0(object + 0xE14, 1, lbl_122_data_0, 0);
    reinterpret_cast<StatusVirtual*>(object + 0xE14)->s3C();
    fn_27_73930(object + 0xE24, owner, object, object + 0x930,
        object + 0x98, object + 0x918, object + 0xE10, parameters, 0x135, 1);
    return object;
}
}