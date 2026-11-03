#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, u32);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, u32);
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};

struct Modules {
    char pad0[0x64];
    soNullable* work;
    char pad1[8];
    soNullable* status;
};
struct Accesser {
    char pad0[8];
    void* object;
    char pad1[0xd8 - 0xc];
    Modules* modules;
};
struct Params {
    char pad[0x34];
    int* value;
};

extern const char lbl_27_data_7ED88[];
extern const char lbl_27_data_248[];
extern float lbl_27_rodata_64C8;
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" Params* fn_27_2F2104(void*);

extern "C" void fn_27_2F2388(void*, Accesser* accesser) {
    int status = accesser->modules->status->slot16();
    soNullable* work = accesser->modules->work;
    switch (status) {
    case 0:
        work->slot5(*fn_27_2F2104(__dynamic_cast(accesser->object, 0x3c,
            lbl_27_data_7ED88, lbl_27_data_248, 1))->value, 0x10000005);
        work->slot13(lbl_27_rodata_64C8, 0x11000001);
        break;
    case 1:
        break;
    }
}
