#pragma force_active on
#pragma optimization_level 1
class Class_12F4 {
public:
    virtual void fn_109_5AF4();
    virtual void fn_109_9044();
    virtual void fn_109_8FF0();
    virtual void fn_109_8FE0(void*, int, short*, short);
};
class Class_1340 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_1D98();
    virtual void fn_109_90B0();
    virtual void fn_109_90A8();
};
class Class_13C0 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_19B8();
    virtual void fn_109_90E8();
    virtual void fn_109_90E0();
};
class Class_1B08 {
public:
    virtual void fn_109_9384();
    virtual void fn_109_9440();
    virtual void fn_109_95C0();
    virtual void fn_109_938C();
};
class Class_6170 {
public:
    virtual void fn_109_C3BC();
    virtual void fn_109_C3B8();
    virtual void fn_109_C30C();
    virtual void fn_109_C3B4();
};
class Class_6208 {
public:
    virtual void fn_109_C578();
    virtual void fn_109_C46C();
    virtual void fn_109_C30C();
    virtual void fn_109_C3B4();
};
class Class_6290 {
public:
    virtual void fn_109_D13C();
    virtual void fn_109_CDD8();
    virtual void fn_109_CEC0();
    virtual void fn_109_C3B4();
};
class Class_630C {
public:
    virtual void fn_109_D17C();
    virtual void fn_109_CD44();
    virtual void fn_109_CDAC();
    virtual void fn_109_CDA4();
};
class Class_6388 {
public:
    virtual void fn_109_D1BC();
    virtual void fn_109_CC54();
    virtual void fn_109_CCF8();
    virtual void fn_109_CCF0();
};
class Class_6408 {
public:
    virtual void fn_109_D1FC();
    virtual void fn_109_C828();
    virtual void fn_109_CC1C();
    virtual void fn_109_C8F8();
};
class Class_6484 {
public:
    virtual void fn_109_D23C();
    virtual void fn_109_C610();
    virtual void fn_109_C6C8();
    virtual void fn_109_C614();
};
class Class_6590 {
public:
    virtual void fn_109_D95C();
    virtual void fn_109_D38C();
    virtual void fn_109_D698();
    virtual void fn_109_D5EC();
};
class Class_660C {
public:
    virtual void fn_109_D99C();
    virtual void fn_109_D384();
    virtual void fn_109_C410();
    virtual void fn_109_D388();
};
class Class_6688 {
public:
    virtual void fn_109_E090();
    virtual void fn_109_DDB0();
    virtual void fn_109_C410();
    virtual void fn_109_C3B4();
};
class Class_6700 {
public:
    virtual void fn_109_E0D0();
    virtual void fn_109_DC48();
    virtual void fn_109_C410();
    virtual void fn_109_DCB4();
};
class Class_6778 {
public:
    virtual void fn_109_E110();
    virtual void fn_109_DA60();
    virtual void fn_109_DC44();
    virtual void fn_109_DB6C();
};
class Class_6DA4 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10ECC();
    virtual void fn_109_116D8();
    virtual void fn_109_116D4();
};
class Class_7184 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10D90();
    virtual void fn_109_11914();
    virtual void fn_109_1190C();
};
class Class_71D8 {
public:
    virtual void fn_109_6868();
    virtual void fn_109_10E70();
    virtual void fn_109_119D4();
    virtual void fn_109_119CC();
};
class Class_7338 {
public:
    virtual void fn_109_11E68();
    virtual void fn_109_C3B8();
    virtual void fn_109_C410();
    virtual void fn_109_11DA0();
};
class Class_73B0 {
public:
    virtual void fn_109_11EA8();
    virtual void fn_109_11CE8();
    virtual void fn_109_C410();
    virtual void fn_109_11D9C();
};
struct EnergyFlag {
    unsigned char disabled : 1;
};
extern "C" {
extern char lbl_109_data_23A4[];
extern char lbl_109_data_5B3C[];
extern char lbl_109_data_5BFC[];
extern char lbl_109_data_5C9C[];
extern char lbl_109_data_579C[];
extern char lbl_109_data_5930[];
extern char lbl_109_data_59D0[];
extern char lbl_109_data_52F4[];
extern char lbl_109_data_550C[];
extern char lbl_109_data_55B0[];
extern char lbl_109_data_4D58[];
extern char lbl_109_data_4FEC[];
extern char lbl_109_data_5088[];
extern char lbl_109_data_46BC[];
extern char lbl_109_data_49D0[];
extern char lbl_109_data_4A70[];
extern char lbl_109_data_5FE8[];
extern char lbl_109_data_3F14[];
extern char lbl_109_data_42AC[];
extern char lbl_109_data_4350[];
extern char lbl_109_data_3658[];
extern char lbl_109_data_3A78[];
extern char lbl_109_data_3B20[];
extern char lbl_109_data_2CA4[];
extern char lbl_109_data_3144[];
extern char lbl_109_data_31E4[];
extern char lbl_109_data_2818[];
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
extern "C" void* fn_109_7AA8(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_109_data_23A4;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_109_data_5B3C;
    *(void**)(self + 0xe8) = lbl_109_data_5BFC;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_109_data_5C9C;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_579C;
    *(void**)(p + 0x60) = lbl_109_data_5930;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_109_data_59D0;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_52F4;
    *(void**)(p + 0x94) = lbl_109_data_550C;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_109_data_55B0;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_4D58;
    *(void**)(p + 0xec) = lbl_109_data_4FEC;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_109_data_5088;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_46BC;
    *(void**)(p + 0x134) = lbl_109_data_49D0;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_109_data_4A70;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_109_data_5FE8;
    a4 = 2;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_3F14;
    *(void**)(p + 0x17c) = lbl_109_data_42AC;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_109_data_4350;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_3658;
    *(void**)(p + 0x1c8) = lbl_109_data_3A78;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_109_data_3B20;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_2CA4;
    *(void**)(p + 0x204) = lbl_109_data_3144;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_109_data_31E4;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Class_12F4**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_109_8FE0(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;
    *(void**)p = lbl_109_data_2818;
    return self;
}