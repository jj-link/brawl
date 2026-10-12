// Keep the follower name in its original four-byte-aligned REL data range.
#pragma section data_type ".data$dedede1C984Name" ".data$dedede1C984Name"

namespace {
typedef unsigned char Byte;
class ResourceInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* getResource() = 0;
    virtual void slot14() = 0;
    virtual void* getData() = 0;
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
    virtual void configure(void*, int) = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void attach(int, void*) = 0;
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
}
extern "C" {
ResourceInterface* fn_117_1CD04(void*);
void fn_27_1DC5E8(void*, int, void*, void*, void*, void*, unsigned char, int,
                   void*, int, int, int, int, int, int, int);
void fn_117_1CD50(void*, void*, void*, void*, void*);
void fn_117_13960(void*, short);
void fn_117_1799C(void*, void*, void*);
void fn_27_C7724(void*);
void* fn_117_1F228();
void fn_117_8790(void*, void*, void*, void*);
int fn_117_1CD0C();
int fn_117_1CD18();
void* fn_117_1CD30(void*);
RegistryInterface* fn_117_1CD24(void*);
RegistryInterface* fn_117_1CD38(void*);
RegistryInterface* fn_117_1CD44(void*);
void fn_27_1D8FC8(void*, int);
Byte lbl_117_data_A158[15] = "DededeFollower";
Byte gap_04_0000A167_data[1] = { 0 };
extern void* lbl_117_data_A170[];
}

// Construct Dedede's resource-backed module group and its three embedded entries.
extern "C" Byte* fn_117_1C984(Byte* object, void* owner, void* resource, Byte* parameters) {
    void* entry;
    void* second;
    void* first = fn_117_1CD04(resource)->getData();
    second = fn_117_1CD04(resource)->getData();
    void* data = fn_117_1CD04(resource)->getResource();
    Byte temporary[0x40];
    fn_27_1DC5E8(temporary, 0x33, parameters, data, second, first,
        static_cast<unsigned char>(*reinterpret_cast<unsigned*>(parameters)), -1,
        object + 0x2650, 0, 0, 0, 0, 0, 0, 0);
    fn_117_1CD50(object, lbl_117_data_A158, owner, resource, temporary);
    fn_117_13960(temporary, -1);
    *reinterpret_cast<Byte**>(object + 0x3C) = reinterpret_cast<Byte*>(lbl_117_data_A170);
    *reinterpret_cast<Byte**>(object + 0x40) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0x64;
    *reinterpret_cast<Byte**>(object + 0x48) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0x70;
    *reinterpret_cast<Byte**>(object + 0x54) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0x84;
    *reinterpret_cast<Byte**>(object + 0x64) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0xDC;
    *reinterpret_cast<Byte**>(object + 0x70) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0xEC;
    *reinterpret_cast<Byte**>(object + 0x7C) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0x100;
    *reinterpret_cast<Byte**>(object + 0x88) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0x118;
    *reinterpret_cast<Byte**>(object + 0x90) = reinterpret_cast<Byte*>(lbl_117_data_A170) + 0x124;
    *reinterpret_cast<Byte**>(object + 0x2644) = parameters;
    void* field58 = *reinterpret_cast<void**>(parameters + 0x58);
    *reinterpret_cast<void**>(object + 0x2648) = field58;
    void* field5C = *reinterpret_cast<void**>(parameters + 0x5C);
    *reinterpret_cast<void**>(object + 0x264C) = field5C;
    fn_117_1799C(object + 0x2650, field5C, field58);
    fn_27_C7724(object + 0x2734);
    entry = fn_117_1F228();
    fn_117_8790(object + 0x2744, object + 0x2734, fn_117_1F228(), entry);
    fn_27_C7724(object + 0x2760);
    entry = fn_117_1F228();
    fn_117_8790(object + 0x2770, object + 0x2760, fn_117_1F228(), entry);
    fn_27_C7724(object + 0x278C);
    entry = fn_117_1F228();
    fn_117_8790(object + 0x279C, object + 0x278C, fn_117_1F228(), entry);
    int entries[26] = {
        fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(),
        fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(),
        fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(),
        fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(), fn_117_1CD0C(),
        fn_117_1CD0C(), fn_117_1CD0C(),
        fn_117_1CD18(), fn_117_1CD18(), fn_117_1CD18(), fn_117_1CD18(),
        fn_117_1CD18(), fn_117_1CD18(), fn_117_1CD18(), fn_117_1CD18()
    };
    fn_117_1CD24(fn_117_1CD30(object))->registerEntries(entries, 26);
    parameters = *reinterpret_cast<Byte**>(object + 0x2644);
    fn_117_1CD38(fn_117_1CD30(object))->configure(*reinterpret_cast<void**>(parameters + 0x60), 0);
    fn_117_1CD44(fn_117_1CD30(object))->attach(1, object + 0x2744);
    fn_117_1CD44(fn_117_1CD30(object))->attach(2, object + 0x2770);
    fn_117_1CD44(fn_117_1CD30(object))->attach(3, object + 0x279C);
    fn_27_1D8FC8(object, 0);
    return object;
}
