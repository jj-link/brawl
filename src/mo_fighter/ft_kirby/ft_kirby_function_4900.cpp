#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;

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
    virtual void slot10(void*);
};
class StatusVirtual {
public:
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C();
};
struct WorkHead { Word data[2]; };
class WorkInterface : public WorkHead {
public:
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C();
};
extern "C" {
void fn_27_C74BC(void*, void*, int);
void fn_96_4D6C(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_96_3294(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A4858(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_96_data_0[];
}
extern "C" void* fn_96_4900(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_96_4D6C(work + 0x118, work, 0x23, work + 0x8c, 0x12, work + 0xd4, 0x11);
    reinterpret_cast<WorkInterface*>(work + 0x118)->slot6C();
    Byte* modules = object + 0x14c;
    fn_27_19E930(modules, 0);
    Byte* entries = modules + 0x19c;
    fn_27_1A154C(entries, 0);
    fn_27_1A1E04(entries + 0x1c, 0);
    fn_27_1A1B1C(entries + 0x88, 0);
    fn_27_D2898(entries + 0xb4, 0);
    fn_27_1A1B1C(entries + 0xf0, 0);
    fn_27_1A154C(entries + 0x11c, 0);
    fn_27_1A154C(entries + 0x138, 0);
    fn_27_D2898(entries + 0x154, 0);
    fn_27_1A1E04(entries + 0x190, 0);
    fn_27_1A154C(entries + 0x1fc, 0);
    fn_27_1A1B1C(entries + 0x218, 0);
    fn_27_1A1F78(entries + 0x244, 0);
    fn_27_1A1B1C(entries + 0x2d0, 0);
    fn_27_1A154C(entries + 0x2fc, 0);
    fn_27_D2898(entries + 0x318, 0);
    fn_27_1A1834(entries + 0x354, 0);
    fn_27_1A154C(entries + 0x470, 0);
    fn_27_1A1B1C(entries + 0x48c, 0);
    fn_27_1A1E04(entries + 0x4b8, 0);
    fn_27_1A1C90(entries + 0x524, 0);
    fn_96_3294(modules + 0x85c, modules);
    for (int i = 0; i < 20; ++i) {
        Word entry[5];
        fn_27_AB15C(entry,
            i == 0 ? modules + 0x6c0 :
            i == 1 ? modules + 0x654 :
            i == 2 ? modules + 0x628 :
            i == 3 ? modules + 0x60c :
            i == 4 ? modules + 0x4f0 :
            i == 5 ? modules + 0x4b4 :
            i == 6 ? modules + 0x498 :
            i == 7 ? modules + 0x46c :
            i == 8 ? modules + 0x3e0 :
            i == 9 ? modules + 0x3b4 :
            i == 10 ? modules + 0x398 :
            i == 11 ? modules + 0x32c :
            i == 12 ? modules + 0x2f0 :
            i == 13 ? modules + 0x2d4 :
            i == 14 ? modules + 0x2b8 :
            i == 15 ? modules + 0x28c :
            i == 16 ? modules + 0x250 :
            i == 17 ? modules + 0x224 :
            i == 18 ? modules + 0x1b8 :
            i == 19 ? modules + 0x19c : 0);
        reinterpret_cast<Object_vptr_0*>(modules)->slot10(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A4858(object + 0x9c0, 0);
    *reinterpret_cast<Byte**>(object + 0x10cc) = object + 0x10d0;
    fn_27_1A29F0(object + 0x10d0, 1, lbl_96_data_0, 0);
    reinterpret_cast<StatusVirtual*>(object + 0x10d0)->slot3C();
    fn_27_73930(object + 0x10e0, owner, object, object + 0x9c0,
        object + 0x128, object + 0x9a8, object + 0x10cc, parameters, 0x1c0, 1);
    return object;
}