#include <types.h>
#pragma force_active on

typedef unsigned char Byte;
typedef unsigned long Word;

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* slot2();
    virtual void slot3(void*, int, short*, short);
    virtual void* slot4();
    virtual void* slot5();
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

struct Vec3f { float x, y, z; };
struct NessFollowingVectors { Vec3f values[5]; };

#pragma always_inline on
static inline Word& word(void* p, int offset) {
    return *reinterpret_cast<Word*>(static_cast<Byte*>(p) + offset);
}
static inline Byte* pointer(void* p, int offset) {
    return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset);
}
static inline float& scalar(void* p, int offset) {
    return *reinterpret_cast<float*>(static_cast<Byte*>(p) + offset);
}
#pragma always_inline reset

extern "C" {
void fn_27_1DC5E8(void*, int, const void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_32AC78(void*, void*, void*);
void fn_27_32BD84(void*, void*, void*);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);

extern Byte lbl_27_data_88160[];
extern Byte lbl_27_data_88170[];
extern Byte lbl_27_data_883DC[];
extern Byte lbl_27_data_88648[];
extern Byte lbl_27_data_458C0[];
extern Byte lbl_27_data_13730[];
extern Byte lbl_27_bss_7D54[];
extern Byte lbl_27_bss_7D64[];
extern const float lbl_27_rodata_7600;
extern const float lbl_27_rodata_7604;
}

struct BuildLocals { Word process[4]; Byte descriptor[64]; };
#define descriptor buildLocals.descriptor
#define process buildLocals.process
extern "C" void* fn_27_32A2BC(Byte* article, int owner, void* resource, const int* parameters) {
    BuildLocals buildLocals;
    Byte* parameterData;
    void* resourceGroup;
    void* resourceKind;
    Object_vptr_0* resourceIds = reinterpret_cast<Object_vptr_0*>(pointer(resource, 4));
    resourceKind = resourceIds->slot5();
    resourceGroup = resourceIds->slot4();
    void* resourceIndex = resourceIds->slot2();
    Byte* accessor = article + 0x1FE8;
    unsigned char id = *parameters & 0xff;
    fn_27_1DC5E8(descriptor, 102, parameters, resourceIndex, resourceGroup, resourceKind,
        id & 0xff, -1, accessor, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(article, lbl_27_data_88160, word(descriptor, 4), word(descriptor, 8),
        owner, resource, article + 0x8C4, 1);

    word(article, 0x3C) = reinterpret_cast<Word>(lbl_27_data_883DC);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_27_data_883DC + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_27_data_883DC + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_27_data_883DC + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_27_data_883DC + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_27_data_883DC + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_27_data_883DC + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_27_data_883DC + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_27_data_883DC + 0x124);

    Byte* modules = article + 0xCC;
    fn_27_32AC78(modules, article, descriptor);
    fn_27_32BD84(modules + 0x18EC, modules + 0x7F8, descriptor);
    fn_27_1DBA64(article + 0x1F68);

    NessFollowingVectors vectors;
    vectors.values[4].x = lbl_27_rodata_7600;
    vectors.values[4].y = lbl_27_rodata_7600;
    vectors.values[4].z = lbl_27_rodata_7600;
    vectors.values[3].x = lbl_27_rodata_7604;
    vectors.values[3].y = lbl_27_rodata_7604;
    vectors.values[3].z = lbl_27_rodata_7604;
    vectors.values[2].x = lbl_27_rodata_7600;
    vectors.values[2].y = lbl_27_rodata_7600;
    vectors.values[2].z = lbl_27_rodata_7600;
    vectors.values[1].x = lbl_27_rodata_7604;
    vectors.values[1].y = lbl_27_rodata_7604;
    vectors.values[1].z = lbl_27_rodata_7604;
    vectors.values[0].x = lbl_27_rodata_7604;
    vectors.values[0].y = lbl_27_rodata_7604;
    vectors.values[0].z = lbl_27_rodata_7604;
    article[0x1FA4] = 0;
    struct FlagByte { unsigned char enabled : 1; unsigned char rest : 7; };
    reinterpret_cast<FlagByte*>(article + 0x1FA5)->enabled = 1;
    article[0x1FA6] = 0;
    word(article, 0x1FA0) = reinterpret_cast<Word>(lbl_27_data_13730);
    *reinterpret_cast<NessFollowingVectors*>(article + 0x1FA8) = vectors;
    fn_27_1D90FC(article);

    int listenerId2, listenerId1, listenerId0;
    *reinterpret_cast<short*>(&listenerId0) = 1;
    Byte* listeners0 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<Object_vptr_0*>(listeners0)->slot3(article + 0x1F68, 0, reinterpret_cast<short*>(&listenerId0), -1);
    *reinterpret_cast<short*>(&listenerId1) = 1;
    Byte* listeners1 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<Object_vptr_0*>(listeners1)->slot3(article + 0x1FA0, 1, reinterpret_cast<short*>(&listenerId1), -1);

#define parameterData (reinterpret_cast<Byte*>(parameters[13]))
    word(article, 0x3C) = reinterpret_cast<Word>(lbl_27_data_88170);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_27_data_88170 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_27_data_88170 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_27_data_88170 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_27_data_88170 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_27_data_88170 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_27_data_88170 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_27_data_88170 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_27_data_88170 + 0x124);
    word(article, 0x1FE4) = reinterpret_cast<Word>(parameterData);
    Byte* parameterAccesser = article + 0x1FE8;
    parameterAccesser[4] = 0;
    word(parameterAccesser, 12) = 102;
    word(parameterAccesser, 16) = 3999;
    word(parameterAccesser, 20) = 23999;
    word(parameterAccesser, 24) = 0;
    word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_27_data_88648);
    word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_27_data_88648 + 8);
    word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
    word(parameterAccesser, 32) = reinterpret_cast<Word>(parameterData + 4);
    word(parameterAccesser, 36) = reinterpret_cast<Word>(parameterData + 8);
    word(parameterAccesser, 40) = reinterpret_cast<Word>(parameterData + 12);
    word(parameterAccesser, 44) = reinterpret_cast<Word>(parameterData + 16);
    word(parameterAccesser, 48) = reinterpret_cast<Word>(parameterData + 20);
    word(parameterAccesser, 52) = reinterpret_cast<Word>(parameterData + 24);
    word(parameterAccesser, 56) = reinterpret_cast<Word>(parameterData + 28);
    word(parameterAccesser, 60) = reinterpret_cast<Word>(parameterData + 32);
    word(parameterAccesser, 64) = reinterpret_cast<Word>(parameterData + 36);
    word(parameterAccesser, 68) = reinterpret_cast<Word>(parameterData + 40);
    word(parameterAccesser, 72) = reinterpret_cast<Word>(parameterData + 44);

    article[0x2044] = 0;
    reinterpret_cast<FlagByte*>(article + 0x2045)->enabled = 1;
    article[0x2046] = 0;
    word(article, 0x2040) = reinterpret_cast<Word>(lbl_27_data_458C0);
    scalar(article, 0x2048) = lbl_27_rodata_7604;
    scalar(article, 0x204C) = lbl_27_rodata_7604;
    scalar(article, 0x2050) = lbl_27_rodata_7600;

    process[1] = 0;
    process[3] = 0;
    process[0] = reinterpret_cast<Word>(lbl_27_bss_7D54);
    process[2] = reinterpret_cast<Word>(lbl_27_bss_7D64);
    Byte* statusModule = pointer(pointer(pointer(article, 0x60), 0xD8), 0x70);
    reinterpret_cast<Object_vptr_0*>(statusModule)->slot28(process, 4);

    *reinterpret_cast<short*>(&listenerId2) = 1;
    Byte* listeners2 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<Object_vptr_0*>(listeners2)->slot3(article + 0x2040, 2, reinterpret_cast<short*>(&listenerId2), -1);

    fn_27_1D8FC8(article, 0);
    return article;
}
