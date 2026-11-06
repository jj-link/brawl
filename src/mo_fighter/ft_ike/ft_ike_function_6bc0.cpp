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
extern char lbl_119_data_2070[];
extern char lbl_119_data_5800[];
extern char lbl_119_data_58C0[];
extern char lbl_119_data_5960[];
extern char lbl_119_data_5460[];
extern char lbl_119_data_55F4[];
extern char lbl_119_data_5694[];
extern char lbl_119_data_4FB8[];
extern char lbl_119_data_51D0[];
extern char lbl_119_data_5274[];
extern char lbl_119_data_4A1C[];
extern char lbl_119_data_4CB0[];
extern char lbl_119_data_4D4C[];
extern char lbl_119_data_4380[];
extern char lbl_119_data_4694[];
extern char lbl_119_data_4734[];
extern char lbl_119_data_5B38[];
extern char lbl_119_data_3BD8[];
extern char lbl_119_data_3F70[];
extern char lbl_119_data_4014[];
extern char lbl_119_data_331C[];
extern char lbl_119_data_373C[];
extern char lbl_119_data_37E4[];
extern char lbl_119_data_2968[];
extern char lbl_119_data_2E08[];
extern char lbl_119_data_2EA8[];
extern char lbl_119_data_24DC[];

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

extern "C" void* fn_119_6BC0(char* input, char* context) {
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
    *(void**)(self + 0xe0) = lbl_119_data_2070;
    p = self + 0xe4;
    *(void**)(self + 0xe4) = lbl_119_data_5800;
    *(void**)(self + 0xe8) = lbl_119_data_58C0;
    char* q0 = p + 0xc;
    *(void**)(self + 0xf0) = lbl_119_data_5960;
    fn_27_15D8F8(q0 + 4);
    one = 1;
    a0 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q0 + 4, 0, &a0, minusOne = -1);
    ((EnergyFlag*)(q0 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_5460;
    *(void**)(p + 0x60) = lbl_119_data_55F4;
    char* q1 = p + 0x68;
    *(void**)(p + 0x68) = lbl_119_data_5694;
    fn_27_15CFE0(q1 + 4);
    a1 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q1 + 4, 1, &a1, minusOne);
    ((EnergyFlag*)(q1 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_4FB8;
    *(void**)(p + 0x94) = lbl_119_data_51D0;
    char* q2 = p + 0x9c;
    *(void**)(p + 0x9c) = lbl_119_data_5274;
    fn_27_15BD28(q2 + 4);
    a2 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q2 + 4, 2, &a2, minusOne);
    ((EnergyFlag*)(q2 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_4A1C;
    *(void**)(p + 0xec) = lbl_119_data_4CB0;
    char* q3 = p + 0xf4;
    *(void**)(p + 0xf4) = lbl_119_data_4D4C;
    fn_27_15E6C8(q3 + 4);
    a3 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q3 + 4, 3, &a3, minusOne);
    ((EnergyFlag*)(q3 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_4380;
    *(void**)(p + 0x134) = lbl_119_data_4694;
    char* q4 = p + 0x13c;
    *(void**)(p + 0x13c) = lbl_119_data_4734;
    char* energy = q4 + 4;
    fn_27_15E6C8(energy);
    *(void**)energy = lbl_119_data_5B38;
    a4 = 2;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(energy, 4, &a4, minusOne);
    ((EnergyFlag*)(q4 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_3BD8;
    *(void**)(p + 0x17c) = lbl_119_data_3F70;
    char* q5 = p + 0x184;
    *(void**)(p + 0x184) = lbl_119_data_4014;
    fn_27_B7634(q5 + 4);
    one = 4;
    a5 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q5 + 4, 5, &a5, minusOne);
    ((EnergyFlag*)(q5 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_331C;
    *(void**)(p + 0x1c8) = lbl_119_data_373C;
    char* q6 = p + 0x1d0;
    *(void**)(p + 0x1d0) = lbl_119_data_37E4;
    fn_27_B7148(q6 + 4);
    a6 = 8;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q6 + 4, 6, &a6, minusOne);
    ((EnergyFlag*)(q6 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_2968;
    *(void**)(p + 0x204) = lbl_119_data_2E08;
    char* q7 = p + 0x20c;
    *(void**)(p + 0x20c) = lbl_119_data_2EA8;
    fn_27_B7B54(q7 + 4);
    a7 = one;
    (*(Object_vptr_0**)(*(char**)(accesser + 0xd8) + 0x7c))->slot3(q7 + 4, 7, &a7, minusOne);
    ((EnergyFlag*)(q7 + 9))->disabled = 0;

    *(void**)p = lbl_119_data_24DC;
    return self;
}
