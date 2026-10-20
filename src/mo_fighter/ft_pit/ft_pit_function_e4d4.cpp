#pragma force_active on
typedef unsigned char Byte;

class Resource {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* getResource() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void* getData() = 0;
};

class IdInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual int getId() = 0;
};

class Registry {
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
Resource* fn_112_E6E0(void*);
void fn_27_1DC5E8(void*, int, void*, void*, int, void*, unsigned char, int,
                   void*, int, int, int, int, int, int, int);
void fn_112_F134(void*, void*, void*, void*, void*);
void* fn_112_E6E8(void*, short);
void* fn_112_EF54(void*);
Byte* fn_112_EF48(void*);
void* fn_112_EEE4(void*, short, signed char);
void fn_112_EFB8(void*, void*);
int fn_112_F0F8();
int fn_112_F104();
int fn_112_F110();
Registry* fn_112_F11C(void*);
Registry* fn_112_F128(void*);
void fn_27_1D8FC8(void*, int);
extern Byte lbl_112_data_6AC8[];
extern Byte lbl_112_data_6ADC[];
}

extern "C" Byte* fn_112_E4D4(Byte* object, void* owner, void* resource,
                            Byte* parameters) {
    void* first = fn_112_E6E0(resource)->getData();
    void* data = fn_112_E6E0(resource)->getResource();

    Byte temporary[0x40];
    fn_27_1DC5E8(temporary, 0x7d, parameters, data, 0x1f, first,
        (unsigned char)*reinterpret_cast<unsigned*>(parameters), -1,
        object + 0x22d8, 0, 0, 0, 0, 0, 0, 0);
    fn_112_F134(object, lbl_112_data_6AC8, owner, resource, temporary);
    fn_112_E6E8(temporary, -1);

    int id = reinterpret_cast<IdInterface*>(
        fn_112_EF48(fn_112_EF54(object)) + 8)->getId();
    fn_112_EEE4(object + 0x22c8, (short)id, -1);

    *reinterpret_cast<Byte**>(object + 0x3c) = lbl_112_data_6ADC;
    *reinterpret_cast<Byte**>(object + 0x40) = lbl_112_data_6ADC + 0x64;
    *reinterpret_cast<Byte**>(object + 0x48) = lbl_112_data_6ADC + 0x70;
    *reinterpret_cast<Byte**>(object + 0x54) = lbl_112_data_6ADC + 0x84;
    *reinterpret_cast<Byte**>(object + 0x64) = lbl_112_data_6ADC + 0xdc;
    *reinterpret_cast<Byte**>(object + 0x70) = lbl_112_data_6ADC + 0xec;
    *reinterpret_cast<Byte**>(object + 0x7c) = lbl_112_data_6ADC + 0x100;
    *reinterpret_cast<Byte**>(object + 0x88) = lbl_112_data_6ADC + 0x118;
    *reinterpret_cast<Byte**>(object + 0x90) = lbl_112_data_6ADC + 0x124;
    *reinterpret_cast<Byte**>(object + 0x22c8) = lbl_112_data_6ADC + 0x26c;

    void* field = *reinterpret_cast<void**>(parameters + 0x34);
    *reinterpret_cast<void**>(object + 0x22d4) = field;
    fn_112_EFB8(object + 0x22d8, field);

    int entries[5] = {0};
    entries[0] = fn_112_F0F8();
    entries[1] = fn_112_F104();
    entries[3] = fn_112_F110();
    fn_112_F11C(fn_112_EF54(object))->registerEntries(entries, 5);
    fn_112_F128(fn_112_EF54(object))->configure(parameters + 0x38, 0);
    fn_27_1D8FC8(object, 0);
    return object;
}
