#pragma force_active on

typedef unsigned char Byte;
typedef unsigned long Word;

#define at(p, o) (reinterpret_cast<Byte*>(p) + (o))
#define word(p, o) (*reinterpret_cast<Word*>(reinterpret_cast<Byte*>(p) + (o)))
#define LISTENER(a) (*reinterpret_cast<ListenerRegistry**>(*reinterpret_cast<Byte**>(*reinterpret_cast<Byte**>((a) + 0x60) + 0xD8) + 0x7C))

class ResourceInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual Word getResource() = 0;
    virtual void slot14() = 0;
    virtual Word getData() = 0;
    virtual Word getExtra() = 0;
};

class ListenerRegistry {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void add(void*, int, short*, int) = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
};

struct FloatTable {
    float v[15];
};
struct FlagByte { unsigned char flag : 1; unsigned char rest : 7; };

extern "C" {
void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_36EE7C(void*, void*, void*);
void fn_27_370610(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
extern Byte lbl_27_data_929A0[];
extern Byte lbl_27_data_92C24[];
extern Byte lbl_27_data_929B8[];
extern Byte lbl_27_data_92E90[];
extern Byte lbl_27_data_13730[];
extern float lbl_27_rodata_7B90;
extern float lbl_27_rodata_7B94;
}

extern "C" void* fn_27_36E2F8(Byte* article, int owner, void* resource, const Word* parameters) {
    Word resourceB;
    Word resourceC;
    ResourceInterface* ri = *reinterpret_cast<ResourceInterface**>(at(resource, 4));
    resourceC = ri->getExtra();
    resourceB = ri->getData();
    Word resourceA = ri->getResource();
    Word param0 = *parameters;

    Byte descriptor[0x48];
    fn_27_1DC5E8(descriptor, 0x4A, (void*)parameters, resourceA, resourceB, resourceC,
                 static_cast<unsigned char>(param0), -1,
                 article + 0x1678, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(article, lbl_27_data_929A0, word(descriptor, 4), word(descriptor, 8),
                 owner, resource, article + 0x4F4, 1);

    Byte* base = lbl_27_data_92C24;
    Byte* modules = article + 0xCC;
    word(article, 0x3C) = reinterpret_cast<Word>(base);
    word(article, 0x40) = reinterpret_cast<Word>(base + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(base + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(base + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(base + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(base + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(base + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(base + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(base + 0x124);

    fn_27_36EE7C(modules, article, descriptor);
    fn_27_370610(modules + 0x11FC, modules + 0x428, descriptor);
    fn_27_1DBA64(article + 0x15F8);

    FloatTable table;
    float minusOne = lbl_27_rodata_7B90;
    table.v[9] = lbl_27_rodata_7B94;
    table.v[12] = minusOne;
    table.v[13] = minusOne;
    table.v[14] = minusOne;
    table.v[10] = lbl_27_rodata_7B94;
    table.v[11] = lbl_27_rodata_7B94;
    table.v[6] = minusOne;
    table.v[7] = minusOne;
    table.v[8] = minusOne;
    table.v[3] = lbl_27_rodata_7B94;
    table.v[4] = lbl_27_rodata_7B94;
    table.v[5] = lbl_27_rodata_7B94;
    table.v[0] = lbl_27_rodata_7B94;
    table.v[1] = lbl_27_rodata_7B94;
    table.v[2] = lbl_27_rodata_7B94;
    article[0x1634] = 0;
    reinterpret_cast<FlagByte*>(article + 0x1635)->flag = 1;
    article[0x1636] = 0;
    word(article, 0x1630) = reinterpret_cast<Word>(lbl_27_data_13730);
    *reinterpret_cast<FloatTable*>(at(article, 0x1638)) = table;
    fn_27_1D90FC(article);

    struct ShortSlot { short n; short pad; };
    ShortSlot listenerId1;
    ShortSlot listenerId0;
    listenerId0.n = 1;
    LISTENER(article)->add(article + 0x15F8, 0, &listenerId0.n, -1);
    listenerId1.n = 1;
    LISTENER(article)->add(article + 0x1630, 1, &listenerId1.n, -1);

    Byte* base2 = lbl_27_data_929B8;
    word(article, 0x3C) = reinterpret_cast<Word>(base2);
    word(article, 0x40) = reinterpret_cast<Word>(base2 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(base2 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(base2 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(base2 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(base2 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(base2 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(base2 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(base2 + 0x124);

    word(article, 0x1674) = parameters[13];
    article[0x167C] = 0;
    word(article, 0x1684) = 0x4A;
    word(article, 0x1688) = 0xF9F;
    word(article, 0x168C) = 0x5DBF;
    word(article, 0x1690) = 0;
    word(article, 0x1680) = reinterpret_cast<Word>(lbl_27_data_92E90);
    word(article, 0x1678) = reinterpret_cast<Word>(lbl_27_data_92E90 + 8);
    word(article, 0x1694) = parameters[13] + 4;
    word(article, 0x169C) = parameters[13];

    fn_27_1D8FC8(article, 0);
    return article;
}
