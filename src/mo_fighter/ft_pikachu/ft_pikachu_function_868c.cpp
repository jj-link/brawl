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
extern char lbl_98_data_31E4[];
extern char lbl_98_data_6980[];
extern char lbl_98_data_6A40[];
extern char lbl_98_data_6AE0[];
extern char lbl_98_data_65E0[];
extern char lbl_98_data_6774[];
extern char lbl_98_data_6814[];
extern char lbl_98_data_6138[];
extern char lbl_98_data_6350[];
extern char lbl_98_data_63F4[];
extern char lbl_98_data_5B9C[];
extern char lbl_98_data_5E30[];
extern char lbl_98_data_5ECC[];
extern char lbl_98_data_5500[];
extern char lbl_98_data_5814[];
extern char lbl_98_data_58B4[];
extern char lbl_98_data_711C[];
extern char lbl_98_data_4D58[];
extern char lbl_98_data_50F0[];
extern char lbl_98_data_5194[];
extern char lbl_98_data_449C[];
extern char lbl_98_data_48BC[];
extern char lbl_98_data_4964[];
extern char lbl_98_data_3AE8[];
extern char lbl_98_data_3F88[];
extern char lbl_98_data_4028[];
extern char lbl_98_data_365C[];

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

extern "C" void* fn_98_868C(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_98_data_31E4;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_98_data_6980;
    *(void**)(self + 0xe8) = lbl_98_data_6A40;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_98_data_6AE0;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_65E0;
    *(void**)(p + 0x60) = lbl_98_data_6774;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_98_data_6814;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_6138;
    *(void**)(p + 0x94) = lbl_98_data_6350;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_98_data_63F4;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_5B9C;
    *(void**)(p + 0xec) = lbl_98_data_5E30;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_98_data_5ECC;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_5500;
    *(void**)(p + 0x134) = lbl_98_data_5814;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_98_data_58B4;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_98_data_711C;
    a4 = 2;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_4D58;
    *(void**)(p + 0x17c) = lbl_98_data_50F0;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_98_data_5194;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_449C;
    *(void**)(p + 0x1c8) = lbl_98_data_48BC;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_98_data_4964;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_3AE8;
    *(void**)(p + 0x204) = lbl_98_data_3F88;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_98_data_4028;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_98_data_365C;
    return self;
}
