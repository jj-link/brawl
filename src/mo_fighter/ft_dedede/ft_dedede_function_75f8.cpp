namespace {
typedef unsigned char Byte;
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
class WorkInterface {
    Byte storage[8];
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
} // namespace
struct DededeGeneralWork;
extern "C" {
void fn_27_C74BC(void*, void*, int);
DededeGeneralWork* fn_117_7980(DededeGeneralWork*, int*, int, float*, int, unsigned int*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_117_6DBC(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A4650(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
Byte lbl_117_data_0[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
}

// Construct the fixed work arrays, module registry and embedded module accesser.
extern "C" Byte* fn_117_75F8(Byte* object, void* owner, void* resource, void* parameters) {
    fn_27_C74BC(object, resource, 0x112);
    Byte* work = object + 0x10;
    fn_117_7980(reinterpret_cast<DededeGeneralWork*>(work + 0xAC),
        reinterpret_cast<int*>(work), 0x12,
        reinterpret_cast<float*>(work + 0x48), 0xE,
        reinterpret_cast<unsigned int*>(work + 0x80), 0xB);
    reinterpret_cast<WorkInterface*>(work + 0xAC)->initialize();
    Byte* modules = object + 0xE0;
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
    fn_117_6DBC(modules + 0x85C, modules);
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
        reinterpret_cast<ModuleInterface*>(modules)->append(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A4650(object + 0x954, 0);
    *reinterpret_cast<Byte**>(object + 0xE48) = object + 0xE4C;
    fn_27_1A29F0(object + 0xE4C, 1, lbl_117_data_0, 0);
    reinterpret_cast<ModuleInterface*>(object + 0xE4C)->initialize();
    fn_27_73930(object + 0xE5C, owner, object, object + 0x954,
        object + 0xBC, object + 0x93C, object + 0xE48, parameters, 0x13A, 1);
    return object;
}
