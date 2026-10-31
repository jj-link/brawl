#pragma force_active on

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
ResourceInterface* fn_115_13700(void*);
void fn_27_1DC5E8(void*, int, void*, void*, void*, void*, unsigned char, int,
                   void*, int, int, int, int, int, int, int);
void fn_115_138FC(void*, void*, void*, void*, void*);
void fn_115_13708(void*, short);
void fn_115_13748(void*, int);
void* fn_115_138D0(void);
void* fn_115_138DC(void);
void* fn_115_138E8(void*);
void* fn_115_138F0(void);
void fn_27_1D8FC8(void*, int);
extern Byte lbl_115_data_7C98[];
extern Byte lbl_115_data_7CAC[];
}

extern "C" Byte* fn_115_13524(Byte* object, void* owner, void* resource,
                               Byte* parameters) {
    void* data;
    void* extra;
    extra = fn_115_13700(resource)->getExtra();
    data = fn_115_13700(resource)->getData();
    void* res = fn_115_13700(resource)->getResource();

    Byte temporary[0x40];
    fn_27_1DC5E8(
        temporary, 0x37, parameters, res, data, extra,
        static_cast<unsigned char>(*reinterpret_cast<unsigned*>(parameters)),
        -1, object + 0x258C, 0, 0, 0, 0, 0, 0, 0);

    fn_115_138FC(object, lbl_115_data_7C98, owner, resource, temporary);
    fn_115_13708(temporary, -1);

    *reinterpret_cast<Byte**>(object + 0x3C) = lbl_115_data_7CAC;
    *reinterpret_cast<Byte**>(object + 0x40) = lbl_115_data_7CAC + 0x64;
    *reinterpret_cast<Byte**>(object + 0x48) = lbl_115_data_7CAC + 0x70;
    *reinterpret_cast<Byte**>(object + 0x54) = lbl_115_data_7CAC + 0x84;
    *reinterpret_cast<Byte**>(object + 0x64) = lbl_115_data_7CAC + 0xDC;
    *reinterpret_cast<Byte**>(object + 0x70) = lbl_115_data_7CAC + 0xEC;
    *reinterpret_cast<Byte**>(object + 0x7C) = lbl_115_data_7CAC + 0x100;
    *reinterpret_cast<Byte**>(object + 0x88) = lbl_115_data_7CAC + 0x118;
    *reinterpret_cast<Byte**>(object + 0x90) = lbl_115_data_7CAC + 0x124;

    *reinterpret_cast<Byte**>(object + 0x2584) = parameters;
    int value = *reinterpret_cast<int*>(parameters + 0x34);
    *reinterpret_cast<int*>(object + 0x2588) = value;
    fn_115_13748(object + 0x258C, value);

    void* entries[3];
    entries[0] = fn_115_138D0();
    entries[1] = fn_115_138D0();
    entries[2] = fn_115_138D0();

    fn_115_138E8(object);
    RegistryInterface* reg =
        static_cast<RegistryInterface*>(fn_115_138DC());
    reg->registerEntries(reinterpret_cast<int*>(entries), 3);

    fn_115_138E8(object);
    RegistryInterface* reg2 =
        static_cast<RegistryInterface*>(fn_115_138F0());
    reg2->configure(
        reinterpret_cast<Byte*>(*reinterpret_cast<void**>(object + 0x2584)) +
            0x38,
        0);

    fn_27_1D8FC8(object, 0);
    return object;
}
