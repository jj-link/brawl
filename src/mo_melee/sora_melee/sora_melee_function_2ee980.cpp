#include <types.h>
#pragma force_active on

typedef unsigned char Byte;
typedef unsigned long Word;

#define word(p, off) \
    (*reinterpret_cast<Word*>(reinterpret_cast<Byte*>(p) + (off)))

struct FlagByte {
    unsigned char flag : 1;
    unsigned char rest : 7;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Word slot2();
    virtual void slot3(void*, int, short*, int);
    virtual Word slot4();
    virtual Word slot5();
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
    virtual void slot26();
    virtual void slot27();
    virtual void slot28(void*, int);
};

extern "C" {
void fn_27_1DC5E8(void*, int, const void*, Word, Word, Word, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void* fn_27_2EECE8(void*, void*, void*);
void fn_27_2E7828(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);

extern Byte g_soParamAccesserNull[];
extern Byte lbl_27_data_7E390[];
extern Byte lbl_27_data_7E6B8[];
extern Byte lbl_27_data_7E3A4[];
extern Byte lbl_27_data_13730[];
extern Byte lbl_27_bss_7524[];
extern f32 lbl_27_rodata_6488;
extern f32 lbl_27_rodata_648C;
}

struct Descriptor {
    Byte data[64];

    Descriptor(const int* param, Word a, Word b, Word c, unsigned char id) {
        fn_27_1DC5E8(
            this, 0x59, param, a, b, c, id, -1,
            g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    }
};

inline void set_base(Byte* article, Byte* base2, const int* param) {
    *reinterpret_cast<Byte**>(article + 0x3C) = base2;
    *reinterpret_cast<Byte**>(article + 0x40) = base2 + 0x64;
    *reinterpret_cast<Byte**>(article + 0x48) = base2 + 0x70;
    *reinterpret_cast<Byte**>(article + 0x54) = base2 + 0x84;
    *reinterpret_cast<Byte**>(article + 0x64) = base2 + 0xDC;
    *reinterpret_cast<Byte**>(article + 0x70) = base2 + 0xEC;
    *reinterpret_cast<Byte**>(article + 0x7C) = base2 + 0x100;
    *reinterpret_cast<Byte**>(article + 0x88) = base2 + 0x118;
    *reinterpret_cast<Byte**>(article + 0x90) = base2 + 0x124;
    word(article, 0x1920) = param[13];

    void* process[2];
    process[0] = lbl_27_bss_7524;
    process[1] = lbl_27_bss_7524;
    Object_vptr_0* st = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<Byte**>(
            *reinterpret_cast<Byte**>(article + 0x60) + 0xD8) + 0x70);
    st->slot28(process, 2);
}

extern "C" void* fn_27_2EE980(
    Byte* article, int owner, Byte* resource, const int* param) {
    Word b;
    Word c;
    Object_vptr_0* source =
        *reinterpret_cast<Object_vptr_0**>(resource + 4);
    c = source->slot5();
    b = source->slot4();
    Word a = source->slot2();

    Byte* base = lbl_27_data_7E6B8;
    Descriptor desc(param, a, b, c, param[0]);
    fn_27_1D7EF0(
        article, lbl_27_data_7E390, word(&desc, 4), word(&desc, 8),
        owner, resource, article + 0x544, 1);

    word(article, 0x3C) = reinterpret_cast<Word>(base);
    word(article, 0x40) = reinterpret_cast<Word>(base + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(base + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(base + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(base + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(base + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(base + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(base + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(base + 0x124);

    Byte* modules = article + 0xCC;
    fn_27_2EECE8(modules, article, &desc);
    fn_27_2E7828(modules + 0x1480, modules + 0x478, &desc);
    fn_27_1DBA64(article + 0x18A4);

    f32 table[15];
    table[12] = lbl_27_rodata_6488;
    table[9] = lbl_27_rodata_648C;
    table[13] = lbl_27_rodata_6488;
    table[14] = lbl_27_rodata_6488;
    table[10] = lbl_27_rodata_648C;
    table[11] = lbl_27_rodata_648C;
    table[6] = lbl_27_rodata_6488;
    table[7] = lbl_27_rodata_6488;
    table[8] = lbl_27_rodata_6488;
    table[3] = lbl_27_rodata_648C;
    table[4] = lbl_27_rodata_648C;
    table[5] = lbl_27_rodata_648C;
    table[0] = lbl_27_rodata_648C;
    table[1] = lbl_27_rodata_648C;
    table[2] = lbl_27_rodata_648C;

    article[0x18E0] = 0;
    ((FlagByte*)(article + 0x18E1))->flag = 1;
    article[0x18E2] = 0;
    word(article, 0x18DC) = reinterpret_cast<Word>(lbl_27_data_13730);
    Word* words = reinterpret_cast<Word*>(table);
    word(article, 0x18E4) = words[0];
    word(article, 0x18E8) = words[1];
    word(article, 0x18EC) = words[2];
    word(article, 0x18F0) = words[3];
    word(article, 0x18F4) = words[4];
    word(article, 0x18F8) = words[5];
    word(article, 0x18FC) = words[6];
    word(article, 0x1900) = words[7];
    word(article, 0x1904) = words[8];
    word(article, 0x1908) = words[9];
    word(article, 0x190C) = words[10];
    word(article, 0x1910) = words[11];
    word(article, 0x1914) = words[12];
    word(article, 0x1918) = words[13];
    word(article, 0x191C) = words[14];
    fn_27_1D90FC(article);

    struct ShortSlot {
        short n;
        short pad;
    };
    ShortSlot sp2c;
    ShortSlot sp28;
    sp28.n = 1;
    Object_vptr_0* l0 = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<Byte**>(
            *reinterpret_cast<Byte**>(article + 0x60) + 0xD8) + 0x7C);
    l0->slot3(article + 0x18A4, 0, &sp28.n, -1);

    sp2c.n = 1;
    Object_vptr_0* l1 = *reinterpret_cast<Object_vptr_0**>(
        *reinterpret_cast<Byte**>(
            *reinterpret_cast<Byte**>(article + 0x60) + 0xD8) + 0x7C);
    l1->slot3(article + 0x18DC, 1, &sp2c.n, -1);

    Byte* base2 = lbl_27_data_7E3A4;
    set_base(article, base2, param);

    fn_27_1D8FC8(article, 0);
    return article;
}
