#pragma force_active on
typedef unsigned char Byte;

class ResourceInterface {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void* getResource() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
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
};

extern "C" {
ResourceInterface* fn_123_145B8(void*);
void fn_27_1DC5E8(void*, int, void*, void*, int, void*, unsigned char, int,
                   void*, void*, int, int, int, int, int, int);
void fn_123_15038(void*, void*, void*, void*, void*);
void* fn_123_12420(void*, short);
void fn_123_14EF4(void*, int);
void* fn_123_15030(void*);
RegistryInterface* fn_123_15024(void*);
void fn_27_1D8FC8(void*, int);
extern Byte lbl_123_data_7280[];
extern Byte lbl_123_data_7354[];
}

extern "C" Byte* fn_123_14430(Byte* object, void* owner, void* resource,
                             Byte* parameters) {
    void* data = fn_123_145B8(resource)->getData();
    void* first = fn_123_145B8(resource)->getResource();
    Byte temporary[0x40];

    fn_27_1DC5E8(
        temporary, 0x7C, parameters, first, 0x1F, data,
        static_cast<unsigned char>(*reinterpret_cast<unsigned*>(parameters)),
        -1, object + 0x2CD8, parameters + 0x40, 0, 0, 0, 0,
        *reinterpret_cast<int*>(parameters + 0x48),
        *reinterpret_cast<int*>(parameters + 0x4C));

    fn_123_15038(object, lbl_123_data_7280, owner, resource, temporary);
    fn_123_12420(temporary, -1);

    *reinterpret_cast<Byte**>(object + 0x3C) = lbl_123_data_7354;
    *reinterpret_cast<Byte**>(object + 0x40) = lbl_123_data_7354 + 0x64;
    *reinterpret_cast<Byte**>(object + 0x48) = lbl_123_data_7354 + 0x70;
    *reinterpret_cast<Byte**>(object + 0x54) = lbl_123_data_7354 + 0x84;
    *reinterpret_cast<Byte**>(object + 0x64) = lbl_123_data_7354 + 0xDC;
    *reinterpret_cast<Byte**>(object + 0x70) = lbl_123_data_7354 + 0xEC;
    *reinterpret_cast<Byte**>(object + 0x7C) = lbl_123_data_7354 + 0x100;
    *reinterpret_cast<Byte**>(object + 0x88) = lbl_123_data_7354 + 0x118;
    *reinterpret_cast<Byte**>(object + 0x90) = lbl_123_data_7354 + 0x124;

    int value = *reinterpret_cast<int*>(parameters + 0x34);
    *reinterpret_cast<int*>(object + 0x2CD4) = value;
    fn_123_14EF4(object + 0x2CD8, value);

    fn_123_15024(fn_123_15030(object))->configure(parameters + 0x38, 0);
    fn_27_1D8FC8(object, 0);
    return object;
}
