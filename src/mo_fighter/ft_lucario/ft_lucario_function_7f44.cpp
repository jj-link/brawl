#pragma force_active on
#pragma optimization_level 1

struct EnergyFlag {
    unsigned char disabled : 1;
};

class Target {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void attach(void* sub, int index, short* value, short flag);
};

extern "C" {
void* fn_27_B6DBC(void* self, void* owner, void* arg, void* value);
void* fn_27_1ACD80(void* self, unsigned char flag);
void fn_27_15D8F8(void* p);
void fn_27_15CFE0(void* p);
void fn_27_15BD28(void* p);
void fn_27_15E6C8(void* p);
void fn_27_B7634(void* p);
void fn_27_B7148(void* p);
void fn_27_B7B54(void* p);

extern char lbl_118_data_24AC[];
extern char lbl_118_data_2918[];
extern char lbl_118_data_2DA4[];
extern char lbl_118_data_3244[];
extern char lbl_118_data_32E4[];
extern char lbl_118_data_3758[];
extern char lbl_118_data_3B78[];
extern char lbl_118_data_3C20[];
extern char lbl_118_data_4014[];
extern char lbl_118_data_43AC[];
extern char lbl_118_data_4450[];
extern char lbl_118_data_47BC[];
extern char lbl_118_data_4AD0[];
extern char lbl_118_data_4B70[];
extern char lbl_118_data_4E58[];
extern char lbl_118_data_50EC[];
extern char lbl_118_data_5188[];
extern char lbl_118_data_53F4[];
extern char lbl_118_data_560C[];
extern char lbl_118_data_56B0[];
extern char lbl_118_data_589C[];
extern char lbl_118_data_5A30[];
extern char lbl_118_data_5AD0[];
extern char lbl_118_data_5C3C[];
extern char lbl_118_data_5CFC[];
extern char lbl_118_data_5D9C[];
extern char lbl_118_data_60EC[];
}

extern "C" void* fn_118_7F44(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_118_data_24AC;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_118_data_5C3C;
    *(void**)(self + 0xe8) = lbl_118_data_5CFC;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_118_data_5D9C;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_589C;
    *(void**)(p + 0x60) = lbl_118_data_5A30;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_118_data_5AD0;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_53F4;
    *(void**)(p + 0x94) = lbl_118_data_560C;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_118_data_56B0;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_4E58;
    *(void**)(p + 0xec) = lbl_118_data_50EC;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_118_data_5188;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_47BC;
    *(void**)(p + 0x134) = lbl_118_data_4AD0;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_118_data_4B70;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_118_data_60EC;
    a4 = 2;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_4014;
    *(void**)(p + 0x17c) = lbl_118_data_43AC;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_118_data_4450;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_3758;
    *(void**)(p + 0x1c8) = lbl_118_data_3B78;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_118_data_3C20;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_2DA4;
    *(void**)(p + 0x204) = lbl_118_data_3244;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_118_data_32E4;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Target**)(*(char**)(accesser + 0xd8) + 0x7c))->attach(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_118_data_2918;
    return self;
}