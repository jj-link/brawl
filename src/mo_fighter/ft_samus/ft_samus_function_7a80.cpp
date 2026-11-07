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
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
};

struct WorkPrefix {
    Word header[2];
};

class StatusWork : public WorkPrefix {
public:
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6C();
};

extern "C" {
void fn_27_C74BC(void*, Word, int);
void* fn_94_7E08(void*, void*, int, void*, int, void*, int);
void fn_27_19E930(void*, int);
void fn_27_1A154C(void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_D2898(void*, int);
void fn_27_1A1F78(void*, int);
void fn_27_1A1834(void*, int);
void fn_27_1A1C90(void*, int);
void fn_94_72E0(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A413C(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
extern Byte lbl_94_data_0[];
}

extern "C" void* fn_94_7A80(Byte* status, void* accesser, Word resource, Word data) {
    fn_27_C74BC(status, resource, 0x112);
    Byte* work = status + 0x10;
    fn_94_7E08(work + 0x88, work, 18, work + 0x48, 14, work + 0x80, 2);
    reinterpret_cast<StatusWork*>(work + 0x88)->s6C();

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
    fn_94_72E0(array + 0x85C, array);
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
    fn_27_1A413C(status + 0x930, 0);
    *reinterpret_cast<Byte**>(status + 0xDF0) = status + 0xDF4;
    fn_27_1A29F0(status + 0xDF4, 1, lbl_94_data_0, 0);
    reinterpret_cast<StatusVirtual*>(status + 0xDF4)->s3C();
    fn_27_73930(status + 0xE04, accesser, status, status + 0x930,
        status + 0x98, status + 0x918, status + 0xDF0, data, 0x12D, 1);
    return status;
}
