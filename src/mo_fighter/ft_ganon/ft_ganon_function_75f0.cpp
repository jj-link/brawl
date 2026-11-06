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
struct WorkPrefix { Word header[2]; };
class Work : public WorkPrefix {
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
void fn_109_7978(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_109_6E50(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A3B24(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
extern Byte lbl_109_data_0[];
}
extern "C" void* fn_109_75F0(Byte* status, void* accesser, void* resource, void* data) {
    fn_27_C74BC(status, resource, 0x112);
    Byte* work = status + 0x10;
    fn_109_7978(work + 0x88, work, 18, work + 0x48, 14, work + 0x80, 2);
    reinterpret_cast<Work*>(work + 0x88)->slot6C();
    Byte* array = status + 0xBC;
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
    fn_109_6E50(array + 0x85C, array);
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
        reinterpret_cast<Object_vptr_0*>(array)->slot10(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A3B24(status + 0x930, 0);
    *reinterpret_cast<Byte**>(status + 0xDC4) = status + 0xDC8;
    fn_27_1A29F0(status + 0xDC8, 1, lbl_109_data_0, 0);
    reinterpret_cast<StatusVirtual*>(status + 0xDC8)->slot3C();
    fn_27_73930(status + 0xDD8, accesser, status, status + 0x930,
        status + 0x98, status + 0x918, status + 0xDC4, data, 0x122, 1);
    return status;
}