#pragma force_active on
#pragma optimization_level 1
class Class_4100 {
public:
    virtual void fn_94_5F00();
    virtual void fn_94_AB28();
    virtual void fn_94_AAD4();
    virtual void fn_94_AAC4(void*, int, short*, short);
};
class Class_4240 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1D9C();
    virtual void fn_94_ADFC();
    virtual void fn_94_ADF4();
};
class Class_42C0 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_19BC();
    virtual void fn_94_AE34();
    virtual void fn_94_AE2C();
};
class Class_4A08 {
public:
    virtual void fn_94_B0D0();
    virtual void fn_94_B18C();
    virtual void fn_94_B30C();
    virtual void fn_94_B0D8();
};
class Class_9944 {
public:
    virtual void fn_94_F4D0();
    virtual void fn_94_EE1C();
    virtual void fn_94_F418();
    virtual void fn_94_F180();
};
class Class_99D8 {
public:
    virtual void fn_94_10774();
    virtual void fn_94_1032C();
    virtual void fn_94_F514();
    virtual void fn_94_F510();
};
class Class_9A54 {
public:
    virtual void fn_94_107B4();
    virtual void fn_94_FAD0();
    virtual void fn_94_F514();
    virtual void fn_94_FDEC();
};
class Class_9AD0 {
public:
    virtual void fn_94_110D8();
    virtual void fn_94_10954();
    virtual void fn_94_F514();
    virtual void fn_94_F510();
};
class Class_9B48 {
public:
    virtual void fn_94_11BE0();
    virtual void fn_94_11170();
    virtual void fn_94_1189C();
    virtual void fn_94_11558();
};
class Class_C5E0 {
public:
    virtual void fn_94_19FEC();
    virtual void fn_94_19D68();
    virtual void fn_94_19F5C();
    virtual void fn_94_F510();
};
class Class_C660 {
public:
    virtual void fn_94_1A390();
    virtual void fn_94_1A084();
    virtual void fn_94_1A230();
    virtual void fn_94_F510();
};
class Class_C6E0 {
public:
    virtual void fn_94_1A5DC();
    virtual void fn_94_1A428();
    virtual void fn_94_1A564();
    virtual void fn_94_1A560();
};
class Class_C760 {
public:
    virtual void fn_94_1A8C8();
    virtual void fn_94_1A674();
    virtual void fn_94_1A838();
    virtual void fn_94_1A678();
};
class Class_C7E0 {
public:
    virtual void fn_94_1AAB4();
    virtual void fn_94_F518();
    virtual void fn_94_1AA18();
    virtual void fn_94_F510();
};
class Class_CE08 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CB4C();
    virtual void fn_94_1D91C();
    virtual void fn_94_1D918();
};
class Class_CF34 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CA28();
    virtual void fn_94_1DA20();
    virtual void fn_94_1DA18();
};
class Class_CF88 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CAF0();
    virtual void fn_94_1DAE0();
    virtual void fn_94_1DAD8();
};
struct EnergyFlag {
    unsigned char disabled : 1;
};
extern "C" {
extern char lbl_94_data_526C[];
extern char lbl_94_data_89FC[];
extern char lbl_94_data_8ABC[];
extern char lbl_94_data_8B5C[];
extern char lbl_94_data_865C[];
extern char lbl_94_data_87F0[];
extern char lbl_94_data_8890[];
extern char lbl_94_data_81B4[];
extern char lbl_94_data_83CC[];
extern char lbl_94_data_8470[];
extern char lbl_94_data_7C18[];
extern char lbl_94_data_7EAC[];
extern char lbl_94_data_7F48[];
extern char lbl_94_data_757C[];
extern char lbl_94_data_7890[];
extern char lbl_94_data_7930[];
extern char lbl_94_data_9728[];
extern char lbl_94_data_6DD4[];
extern char lbl_94_data_716C[];
extern char lbl_94_data_7210[];
extern char lbl_94_data_6518[];
extern char lbl_94_data_6938[];
extern char lbl_94_data_69E0[];
extern char lbl_94_data_5B64[];
extern char lbl_94_data_6004[];
extern char lbl_94_data_60A4[];
extern char lbl_94_data_56D8[];
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
extern "C" void* fn_94_7F38(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_94_data_526C;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_94_data_89FC;
    *(void**)(self + 0xe8) = lbl_94_data_8ABC;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_94_data_8B5C;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_865C;
    *(void**)(p + 0x60) = lbl_94_data_87F0;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_94_data_8890;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_81B4;
    *(void**)(p + 0x94) = lbl_94_data_83CC;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_94_data_8470;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_7C18;
    *(void**)(p + 0xec) = lbl_94_data_7EAC;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_94_data_7F48;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_757C;
    *(void**)(p + 0x134) = lbl_94_data_7890;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_94_data_7930;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_94_data_9728;
    a4 = 2;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_6DD4;
    *(void**)(p + 0x17c) = lbl_94_data_716C;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_94_data_7210;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_6518;
    *(void**)(p + 0x1c8) = lbl_94_data_6938;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_94_data_69E0;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_5B64;
    *(void**)(p + 0x204) = lbl_94_data_6004;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_94_data_60A4;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Class_4100**)(*(char**)(accesser + 0xd8) + 0x7c))->fn_94_AAC4(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;
    *(void**)p = lbl_94_data_56D8;
    return self;
}
