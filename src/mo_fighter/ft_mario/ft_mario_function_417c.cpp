#pragma force_active on
typedef unsigned char Byte;
typedef unsigned int Word;

namespace {
struct MarioWorkPrefix {
    Word header[2];
};

class MarioWork : public MarioWorkPrefix {
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
    virtual void slot6C() = 0;
};

class MarioArray {
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
};

class MarioAccesser {
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
    virtual void initialize() = 0;
};
} // namespace

extern "C" {
void fn_27_C74BC(void*, void*, int);
void* fn_91_45E8(void*, void*, int, void*, int, void*, int);
void fn_91_2C24(void*, void*);
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
void fn_27_1A3304(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_91_data_0[];
}

extern "C" Byte* fn_91_417C(Byte* object, void* accesser, void* resource, void* data) {
    fn_27_C74BC(object, resource, 0x112);

    Byte* work = object + 0x10;
    fn_91_45E8(work + 0x88, work, 0x12, work + 0x48, 0xE, work + 0x80, 2);
    reinterpret_cast<MarioWork*>(work + 0x88)->slot6C();

    Byte* array = object + 0xBC;
    fn_27_19E930(array, 0);
    Byte* entries = array + 0x19C;
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

    fn_91_2C24(array + 0x85C, array);

    for (int i = 0; i < 20; ++i) {
        Word entry[5];
        fn_27_AB15C(entry,
            i == 0 ? array + 0x6C0 :
            i == 1 ? array + 0x654 :
            i == 2 ? array + 0x628 :
            i == 3 ? array + 0x60C :
            i == 4 ? array + 0x4F0 :
            i == 5 ? array + 0x4B4 :
            i == 6 ? array + 0x498 :
            i == 7 ? array + 0x46C :
            i == 8 ? array + 0x3E0 :
            i == 9 ? array + 0x3B4 :
            i == 10 ? array + 0x398 :
            i == 11 ? array + 0x32C :
            i == 12 ? array + 0x2F0 :
            i == 13 ? array + 0x2D4 :
            i == 14 ? array + 0x2B8 :
            i == 15 ? array + 0x28C :
            i == 16 ? array + 0x250 :
            i == 17 ? array + 0x224 :
            i == 18 ? array + 0x1B8 :
            i == 19 ? array + 0x19C : 0);
        reinterpret_cast<MarioArray*>(array)->append(entry);
        fn_27_AB18C(entry, -1);
    }

    fn_27_1A3304(object + 0x930, 0);
    *reinterpret_cast<void**>(object + 0xDA0) = object + 0xDA4;
    fn_27_1A29F0(object + 0xDA4, 1, lbl_91_data_0, 0);
    reinterpret_cast<MarioAccesser*>(object + 0xDA4)->initialize();
    fn_27_73930(object + 0xDB4, accesser, object, object + 0x930,
        object + 0x98, object + 0x918, object + 0xDA0, data, 0x119, 1);
    return object;
}
