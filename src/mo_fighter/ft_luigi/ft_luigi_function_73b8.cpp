#pragma force_active on
#pragma optimization_level 1

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*, int, short*, short);
};

struct EnergyFlag {
    unsigned char disabled : 1;
};

extern "C" {
extern char lbl_99_data_2470[];
extern char lbl_99_data_5C08[];
extern char lbl_99_data_5CC8[];
extern char lbl_99_data_5D68[];
extern char lbl_99_data_5868[];
extern char lbl_99_data_59FC[];
extern char lbl_99_data_5A9C[];
extern char lbl_99_data_53C0[];
extern char lbl_99_data_55D8[];
extern char lbl_99_data_567C[];
extern char lbl_99_data_4E24[];
extern char lbl_99_data_50B8[];
extern char lbl_99_data_5154[];
extern char lbl_99_data_4788[];
extern char lbl_99_data_4A9C[];
extern char lbl_99_data_4B3C[];
extern char lbl_99_data_6168[];
extern char lbl_99_data_3FE0[];
extern char lbl_99_data_4378[];
extern char lbl_99_data_441C[];
extern char lbl_99_data_3724[];
extern char lbl_99_data_3B44[];
extern char lbl_99_data_3BEC[];
extern char lbl_99_data_2D70[];
extern char lbl_99_data_3210[];
extern char lbl_99_data_32B0[];
extern char lbl_99_data_28E4[];

void* fn_27_B6DBC(void*, void*, void*, void*);
void* fn_27_1ACD80(void*, unsigned char);
void fn_27_15D8F8(void*);
void fn_27_15CFE0(void*);
void fn_27_15BD28(void*);
void fn_27_15E6C8(void*);
void fn_27_B7634(void*);
void fn_27_B7148(void*);
void fn_27_B7B54(void*);
}

extern "C" void* fn_99_73B8(char* input, char* context) {
    short a7, a6, a5, a4, a3, a2, a1, a0;
    int minusOne;
    int one;
    char* p;
    char* accesser;
    char* self;

    self = input;
    accesser = context;
    fn_27_B6DBC(input, context, input + 0x30, input + 0xe0);
    fn_27_1ACD80(self + 0x30, 0);
    *(void**)(self + 0xe0) = lbl_99_data_2470;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_99_data_5C08;
    *(void**)(self + 0xe8) = lbl_99_data_5CC8;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_99_data_5D68;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_5868;
    *(void**)(p + 0x60) = lbl_99_data_59FC;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_99_data_5A9C;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_53C0;
    *(void**)(p + 0x94) = lbl_99_data_55D8;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_99_data_567C;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_4E24;
    *(void**)(p + 0xec) = lbl_99_data_50B8;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_99_data_5154;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_4788;
    *(void**)(p + 0x134) = lbl_99_data_4A9C;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_99_data_4B3C;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_99_data_6168;
    a4 = 2;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_3FE0;
    *(void**)(p + 0x17c) = lbl_99_data_4378;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_99_data_441C;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_3724;
    *(void**)(p + 0x1c8) = lbl_99_data_3B44;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_99_data_3BEC;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_2D70;
    *(void**)(p + 0x204) = lbl_99_data_3210;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_99_data_32B0;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_99_data_28E4;
    return self;
}
