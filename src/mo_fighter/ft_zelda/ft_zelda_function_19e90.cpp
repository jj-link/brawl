#pragma force_active on
typedef unsigned char Byte;

class Class_71E8 {
public:
    virtual void fn_104_E064();
    virtual void fn_104_DFB4();
    virtual void fn_104_E060();
    virtual void fn_104_E05C();
    virtual void fn_104_E058();
    virtual void fn_104_E054();
    virtual void fn_104_E050();
    virtual void fn_104_E04C();
    virtual void fn_104_E048();
    virtual void fn_104_E040();
    virtual void fn_104_E03C(void*);
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
};
class WorkInterface {
    Byte storage[8];
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
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void initialize();
};
extern "C" {
void fn_27_C74BC(void*, void*, int);
void fn_104_8ADC(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_104_7F18(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3818(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_104_data_8980[];
}

extern "C" Byte* fn_104_19E90(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_104_8ADC(work + 0xC8, work, 0x22, work + 0x88, 0xE, work + 0xC0, 2);
    reinterpret_cast<WorkInterface*>(work + 0xC8)->initialize();
    Byte* modules = object + 0xFC;
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
    fn_104_7F18(modules + 0x85C, modules);
    for (int i = 0; i < 20; ++i) {
        unsigned long entry[5];
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
        reinterpret_cast<Class_71E8*>(modules)->fn_104_E03C(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A3818(object + 0x970, 0);
    *reinterpret_cast<Byte**>(object + 0xDF8) = object + 0xDFC;
    fn_27_1A29F0(object + 0xDFC, 1, lbl_104_data_8980, 0);
    reinterpret_cast<Class_71E8*>(object + 0xDFC)->slot3C();
    fn_27_73930(object + 0xE0C, owner, object, object + 0x970,
        object + 0xD8, object + 0x958, object + 0xDF8, parameters, 0x11F, 1);
    return object;
}