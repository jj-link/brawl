#pragma force_active on
#include <types.h>

typedef unsigned char Byte;
typedef unsigned long Word;

struct LucasObjectWords {
    u32 w[9];
};

struct LucasEmbeddedPrefix {
    u32 words[2];
};

class LucasEmbeddedInterface : public LucasEmbeddedPrefix {
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

class LucasStatusVirtual {
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

class LucasModuleInterface {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual Word slot14() = 0;
    virtual Word slot18() = 0;
    virtual Word slot1C() = 0;
    virtual Word slot20() = 0;
    virtual Word slot24() = 0;
    virtual Word slot28() = 0;
    virtual Word slot2C() = 0;
    virtual void slot30(void*) = 0;
};

extern "C" {
LucasObjectWords* fn_114_9DA4(LucasObjectWords* self, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void fn_114_91A8(void*, void*);
void fn_27_C74BC(void*, Word, int);
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
void fn_27_1A3B24(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
extern Byte lbl_114_data_0[];
}

extern "C" void* fn_114_9A1C(Byte* status, void* accesser, Word resource, Word data) {
    fn_27_C74BC(status, resource, 0x112);
    Byte* work = status + 0x10;
    fn_114_9DA4(reinterpret_cast<LucasObjectWords*>(work + 0x88),
        (u32)work, 18, (u32)(work + 0x48), 14, (u32)(work + 0x80), 2);
    reinterpret_cast<LucasEmbeddedInterface*>(work + 0x88)->slot25();

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
    fn_114_91A8(array + 0x85C, array);
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
        reinterpret_cast<LucasModuleInterface*>(array)->slot30(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A3B24(status + 0x930, 0);
    *reinterpret_cast<Byte**>(status + 0xDC4) = status + 0xDC8;
    fn_27_1A29F0(status + 0xDC8, 1, lbl_114_data_0, 0);
    reinterpret_cast<LucasStatusVirtual*>(status + 0xDC8)->slot13();
    fn_27_73930(status + 0xDD8, accesser, status, status + 0x930,
        status + 0x98, status + 0x918, status + 0xDC4, data, 0x122, 1);
    return status;
}
