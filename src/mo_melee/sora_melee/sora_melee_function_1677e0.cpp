#pragma force_active on

typedef unsigned int u32;

class Sub64 {
public:
    virtual int slot0(u32 a);
    virtual int slot1(u32 a);
    virtual int slot2(u32 a);
    virtual int slot3(u32 a);
    virtual int slot4(u32 a);
    virtual int slot5(u32 a);
    virtual int slot6(u32 a);
    virtual int slot7(u32 a);
    virtual int slot8(u32 a);
    virtual int slot9(u32 a);
    virtual int slot10(u32 a);
    virtual int slot11(u32 a);
    virtual int slot12(u32 a);
    virtual int slot13(u32 a);
    virtual int slot14(u32 a);
    virtual int slot15(u32 a);
    virtual int slot16(u32 a);
    virtual int slot17(u32 a);
    virtual int slot18(u32 a);
    virtual int slot19(u32 a);
    virtual int slot20(u32 a);
    virtual int slot21(u32 a);
    virtual int slot22(u32 a);
    virtual int slot23(u32 a);
};

class Sub70 {
public:
    virtual int slot0(u32 a);
    virtual int slot1(u32 a);
    virtual int slot2(u32 a);
    virtual int slot3(u32 a);
    virtual int slot4(u32 a);
    virtual int slot5(u32 a);
    virtual int slot6(u32 a);
    virtual int slot7(u32 a);
    virtual int slot8(u32 a);
    virtual int slot9(u32 a);
    virtual int slot10(u32 a);
    virtual int slot11(u32 a);
    virtual int slot12(u32 a);
    virtual int slot13(u32 a);
    virtual int slot14(u32 a);
    virtual int slot15(u32 a);
    virtual int slot16(u32 a);
    virtual int slot17(u32 a);
    virtual int slot18(u32 a);
    virtual int slot19(u32 a);
    virtual int slot20(u32 a);
    virtual int slot21(u32 a);
    virtual int slot22(u32 a);
    virtual int slot23(u32 a);
    virtual int slot24(u32 a);
    virtual int slot25(u32 a);
};

struct Mid {
    char pad0[0x64];
    Sub64* s64;
    char pad1[0x70 - 0x68];
    Sub70* s70;
};

struct Obj {
    char pad0[0xd8];
    Mid* mid;
};

extern "C" void fn_27_1677E0(void* unused, Obj* obj, u32 flag) {
    if (flag == 1U) {
        if (obj->mid->s64->slot17(0x22000010) == 0) {
            if (obj->mid->s64->slot17(0x12000018) == 0) {
                if (obj->mid->s64->slot4(0x20000000) <= 0) {
                    obj->mid->s70->slot22(0xB);
                    obj->mid->s70->slot22(0xC);
                    obj->mid->s70->slot22(0xF);
                    obj->mid->s70->slot22(0x11);
                    obj->mid->s70->slot22(0x12);
                    obj->mid->s70->slot22(0xE);
                    obj->mid->s64->slot18(0x22000010);
                }
            }
        }
    } else {
        if (obj->mid->s64->slot17(0x22000010) == 1U) {
            obj->mid->s70->slot23(0xB);
            obj->mid->s70->slot23(0xC);
            obj->mid->s70->slot23(0xF);
            obj->mid->s70->slot23(0x11);
            obj->mid->s70->slot23(0x12);
            obj->mid->s70->slot23(0xE);
            obj->mid->s64->slot19(0x22000010);
        }
    }
}
