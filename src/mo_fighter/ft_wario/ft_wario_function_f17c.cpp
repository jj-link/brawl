#pragma force_active on

#include <it/it_manager.h>

typedef unsigned char Byte;

class ResourceInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* getResource() = 0;
    virtual void slot14() = 0;
    virtual void* getData() = 0;
    virtual void* getExtra() = 0;
};

class RegistryInterface {
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
    virtual void configure(void*, int) = 0;
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
    virtual void slot70() = 0;
    virtual void slot74() = 0;
    virtual void registerEntries(int*, int) = 0;
};

extern "C" {
ResourceInterface* fn_110_F3F8(void*);
void fn_27_1DC5E8(void*, int, void*, void*, void*, void*, unsigned char, int,
                  void*, int, int, int, int, int, int, int);
void fn_110_10318(void*, void*, void*, void*, void*);
void* fn_110_F400(void*, short);
void fn_110_10054(void*, int);
int fn_110_1025C(void);
int fn_110_10268(void);
int fn_110_10274(void);
int fn_110_10280(void);
int fn_110_1028C(void);
int fn_110_10298(void);
int fn_110_102A4(void);
int fn_110_102B0(void);
int fn_110_102BC(void);
int fn_110_102C8(void);
int fn_110_102D4(void);
int fn_110_102E0(void);
int fn_110_102EC(void);
void* fn_110_10304(void*);
RegistryInterface* fn_110_102F8(void*);
RegistryInterface* fn_110_1030C(void*);
void fn_27_1D8FC8(void*, int);
extern Byte lbl_110_data_6988[];
extern Byte lbl_110_data_699C[];
}

extern "C" Byte* fn_110_F17C(Byte* object, void* owner, void* resource, Byte* parameters) {
    void* data;
    void* extra;
    extra = fn_110_F3F8(resource)->getExtra();
    data = fn_110_F3F8(resource)->getData();
    void* res = fn_110_F3F8(resource)->getResource();

    Byte temporary[0x40];
    fn_27_1DC5E8(temporary, 0x60, parameters, res, data, extra,
                 static_cast<unsigned char>(*reinterpret_cast<unsigned*>(parameters)),
                 -1, object + 0x2984, 0, 0, 0, 0, 0, 0, 0);

    fn_110_10318(object, lbl_110_data_6988, owner, resource, temporary);
    fn_110_F400(temporary, -1);

    *reinterpret_cast<Byte**>(object + 0x3C) = lbl_110_data_699C;
    *reinterpret_cast<Byte**>(object + 0x40) = lbl_110_data_699C + 0x64;
    *reinterpret_cast<Byte**>(object + 0x48) = lbl_110_data_699C + 0x70;
    *reinterpret_cast<Byte**>(object + 0x54) = lbl_110_data_699C + 0x84;
    *reinterpret_cast<Byte**>(object + 0x64) = lbl_110_data_699C + 0xDC;
    *reinterpret_cast<Byte**>(object + 0x70) = lbl_110_data_699C + 0xEC;
    *reinterpret_cast<Byte**>(object + 0x7C) = lbl_110_data_699C + 0x100;
    *reinterpret_cast<Byte**>(object + 0x88) = lbl_110_data_699C + 0x118;
    *reinterpret_cast<Byte**>(object + 0x90) = lbl_110_data_699C + 0x124;

    int value = *reinterpret_cast<int*>(parameters + 0x34);
    *reinterpret_cast<int*>(object + 0x2980) = value;
    fn_110_10054(object + 0x2984, value);

    int entries[19] = {
        fn_110_1025C(), fn_110_1025C(), fn_110_10268(), fn_110_10274(),
        fn_110_10280(), fn_110_1028C(), fn_110_10298(), fn_110_102A4(),
        fn_110_102B0(), fn_110_102BC(), fn_110_102C8(), fn_110_102D4(),
        0, fn_110_102E0(), fn_110_102EC()
    };

    fn_110_102F8(fn_110_10304(object))->registerEntries(entries, 19);
    fn_110_1030C(fn_110_10304(object))->configure(*reinterpret_cast<void**>(parameters + 0x38), 0);

    if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x5C, 0U, true)) {
        itManager::getInstance()->preloadItemKindArchive((itKind)0x5C, 0U, (itArchive::Type)0, true);
    }

    fn_27_1D8FC8(object, 0);
    return object;
}
