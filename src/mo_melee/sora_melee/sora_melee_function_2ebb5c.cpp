#pragma force_active on

struct Modules {
    char pad0[0x58];
    void* field_58;
    char pad1[8];
    void* field_64;
    char pad2[8];
    void* field_70;
    char pad3[8];
    void* field_7c;
};

struct Accesser {
    char pad0[8];
    void* object;
    char pad1[0xD8 - 0xC];
    Modules* modules;
};

class soNullable {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned long);
    virtual void* slot6(int);
    virtual void slot7(int);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" unsigned long fn_27_2E95E8(void*);
extern const char lbl_27_data_7D468[];
extern const char lbl_27_data_248[];
extern const char lbl_27_data_457C0[];
extern const char lbl_27_data_CDF8[];
extern const char lbl_27_data_45940[];

extern "C" void fn_27_2EBB5C(void*, Accesser* accesser) {
    switch (reinterpret_cast<soNullable*>(accesser->modules->field_70)->slot16()) {
    case 0:
        reinterpret_cast<soNullable*>(accesser->modules->field_64)->slot5(
            **((int**)(reinterpret_cast<char*>(fn_27_2E95E8(
                __dynamic_cast(accesser->object, 0x3c, lbl_27_data_7D468, lbl_27_data_248, 1))) + 0x34)),
            0x10000005UL);
        break;
    case 1:
        *(signed char*)(reinterpret_cast<char*>(__dynamic_cast(
            reinterpret_cast<soNullable*>(accesser->modules->field_7c)->slot6(0),
            0, lbl_27_data_457C0, lbl_27_data_CDF8, 1)) + 5) &= 0xFFFFFF7F;
        *(signed char*)(reinterpret_cast<char*>(__dynamic_cast(
            reinterpret_cast<soNullable*>(accesser->modules->field_7c)->slot6(2),
            0, lbl_27_data_45940, lbl_27_data_CDF8, 1)) + 5) &= 0xFFFFFF7F;
        reinterpret_cast<soNullable*>(accesser->modules->field_58)->slot7(0);
        reinterpret_cast<soNullable*>(accesser->modules->field_64)->slot5(1, 0x10000006UL);
        break;
    }
}
