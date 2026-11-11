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
extern char lbl_92_data_2590[];
extern char lbl_92_data_5D20[];
extern char lbl_92_data_5DE0[];
extern char lbl_92_data_5E80[];
extern char lbl_92_data_5980[];
extern char lbl_92_data_5B14[];
extern char lbl_92_data_5BB4[];
extern char lbl_92_data_54D8[];
extern char lbl_92_data_56F0[];
extern char lbl_92_data_5794[];
extern char lbl_92_data_4F3C[];
extern char lbl_92_data_51D0[];
extern char lbl_92_data_526C[];
extern char lbl_92_data_48A0[];
extern char lbl_92_data_4BB4[];
extern char lbl_92_data_4C54[];
extern char lbl_92_data_61DC[];
extern char lbl_92_data_40F8[];
extern char lbl_92_data_4490[];
extern char lbl_92_data_4534[];
extern char lbl_92_data_383C[];
extern char lbl_92_data_3C5C[];
extern char lbl_92_data_3D04[];
extern char lbl_92_data_2E88[];
extern char lbl_92_data_3328[];
extern char lbl_92_data_33C8[];
extern char lbl_92_data_29FC[];

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

extern "C" void* fn_92_80DC(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_92_data_2590;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_92_data_5D20;
    *(void**)(self + 0xe8) = lbl_92_data_5DE0;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_92_data_5E80;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_5980;
    *(void**)(p + 0x60) = lbl_92_data_5B14;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_92_data_5BB4;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_54D8;
    *(void**)(p + 0x94) = lbl_92_data_56F0;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_92_data_5794;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_4F3C;
    *(void**)(p + 0xec) = lbl_92_data_51D0;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_92_data_526C;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_48A0;
    *(void**)(p + 0x134) = lbl_92_data_4BB4;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_92_data_4C54;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_92_data_61DC;
    a4 = 2;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_40F8;
    *(void**)(p + 0x17c) = lbl_92_data_4490;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_92_data_4534;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_383C;
    *(void**)(p + 0x1c8) = lbl_92_data_3C5C;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_92_data_3D04;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_2E88;
    *(void**)(p + 0x204) = lbl_92_data_3328;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_92_data_33C8;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_92_data_29FC;
    return self;
}