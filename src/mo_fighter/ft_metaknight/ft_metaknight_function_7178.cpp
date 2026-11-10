#include <types.h>
#pragma force_active on
#pragma optimization_level 1

class Class_6588 {
public:
    virtual void fn_111_5F38();
    virtual void fn_111_10560();
    virtual void fn_111_10DB8();
    virtual void fn_111_10DB4(void*, int, short*, short);
};

struct EnergyFlag {
    unsigned char disabled : 1;
};

extern "C" {
extern char lbl_111_data_1FA0[];
extern char lbl_111_data_5744[];
extern char lbl_111_data_5804[];
extern char lbl_111_data_58A4[];
extern char lbl_111_data_53A4[];
extern char lbl_111_data_5538[];
extern char lbl_111_data_55D8[];
extern char lbl_111_data_4EFC[];
extern char lbl_111_data_5114[];
extern char lbl_111_data_51B8[];
extern char lbl_111_data_4960[];
extern char lbl_111_data_4BF4[];
extern char lbl_111_data_4C90[];
extern char lbl_111_data_42C4[];
extern char lbl_111_data_45D8[];
extern char lbl_111_data_4678[];
extern char lbl_111_data_5A8C[];
extern char lbl_111_data_3B1C[];
extern char lbl_111_data_3EB4[];
extern char lbl_111_data_3F58[];
extern char lbl_111_data_3260[];
extern char lbl_111_data_3680[];
extern char lbl_111_data_3728[];
extern char lbl_111_data_28AC[];
extern char lbl_111_data_2D4C[];
extern char lbl_111_data_2DEC[];
extern char lbl_111_data_2420[];

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

extern "C" void* fn_111_7178(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_111_data_1FA0;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_111_data_5744;
    *(void**)(self + 0xe8) = lbl_111_data_5804;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_111_data_58A4;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_53A4;
    *(void**)(p + 0x60) = lbl_111_data_5538;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_111_data_55D8;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_4EFC;
    *(void**)(p + 0x94) = lbl_111_data_5114;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_111_data_51B8;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_4960;
    *(void**)(p + 0xec) = lbl_111_data_4BF4;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_111_data_4C90;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_42C4;
    *(void**)(p + 0x134) = lbl_111_data_45D8;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_111_data_4678;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_111_data_5A8C;
    a4 = 2;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_3B1C;
    *(void**)(p + 0x17c) = lbl_111_data_3EB4;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_111_data_3F58;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_3260;
    *(void**)(p + 0x1c8) = lbl_111_data_3680;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_111_data_3728;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_28AC;
    *(void**)(p + 0x204) = lbl_111_data_2D4C;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_111_data_2DEC;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Class_6588**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_111_10DB4(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_111_data_2420;
    return self;
}