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
extern char lbl_121_data_3F4C[];
extern char lbl_121_data_76EC[];
extern char lbl_121_data_77AC[];
extern char lbl_121_data_784C[];
extern char lbl_121_data_734C[];
extern char lbl_121_data_74E0[];
extern char lbl_121_data_7580[];
extern char lbl_121_data_6EA4[];
extern char lbl_121_data_70BC[];
extern char lbl_121_data_7160[];
extern char lbl_121_data_6908[];
extern char lbl_121_data_6B9C[];
extern char lbl_121_data_6C38[];
extern char lbl_121_data_626C[];
extern char lbl_121_data_6580[];
extern char lbl_121_data_6620[];
extern char lbl_121_data_7FE4[];
extern char lbl_121_data_5AC4[];
extern char lbl_121_data_5E5C[];
extern char lbl_121_data_5F00[];
extern char lbl_121_data_5208[];
extern char lbl_121_data_5628[];
extern char lbl_121_data_56D0[];
extern char lbl_121_data_4854[];
extern char lbl_121_data_4CF4[];
extern char lbl_121_data_4D94[];
extern char lbl_121_data_43C8[];

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

extern "C" void* fn_121_54E8(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_121_data_3F4C;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_121_data_76EC;
    *(void**)(self + 0xe8) = lbl_121_data_77AC;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_121_data_784C;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_734C;
    *(void**)(p + 0x60) = lbl_121_data_74E0;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_121_data_7580;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_6EA4;
    *(void**)(p + 0x94) = lbl_121_data_70BC;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_121_data_7160;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_6908;
    *(void**)(p + 0xec) = lbl_121_data_6B9C;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_121_data_6C38;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_626C;
    *(void**)(p + 0x134) = lbl_121_data_6580;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_121_data_6620;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_121_data_7FE4;
    a4 = 2;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_5AC4;
    *(void**)(p + 0x17c) = lbl_121_data_5E5C;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_121_data_5F00;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_5208;
    *(void**)(p + 0x1c8) = lbl_121_data_5628;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_121_data_56D0;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_4854;
    *(void**)(p + 0x204) = lbl_121_data_4CF4;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_121_data_4D94;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_121_data_43C8;
    return self;
}
