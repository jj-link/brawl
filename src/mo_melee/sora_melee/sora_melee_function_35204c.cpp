#pragma force_active on

typedef unsigned long long u64;

struct Pair {
    float x, y;
};

class Query {
    char pad[8];

public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual void q21();
    virtual void q22();
    virtual void q23();
    virtual void q24();
    virtual void q25();
    virtual void q26();
    virtual void q27();
    virtual void q28();
    virtual void q29();
    virtual void q30();
    virtual void q31();
    virtual void q32();
    virtual void q33();
    virtual void q34();
    virtual void q35();
    virtual void q36();
    virtual void q37();
    virtual void q38();
    virtual void q39();
    virtual void q40();
    virtual void q41();
    virtual void q42();
    virtual void q43();
    virtual void q44();
    virtual void q45();
    virtual void q46();
    virtual void q47();
    virtual void q48();
    virtual void q49();
    virtual void q50();
    virtual void q51();
    virtual void q52();
    virtual void q53();
    virtual void q54();
    virtual int test(int, int);
};

class Energy {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void* get(int);
};

class Result {
public:
    virtual void r0();
    virtual void r1();
    virtual u64 get();

    Pair speed() {
        union {
            u64 raw;
            Pair pair;
        } temp;
        temp.raw = get();
        return temp.pair;
    }

    char pad[4];
    Pair value;
};

struct Modules {
    char pad0[0x10];
    Query* query;
    char pad1[0x68];
    Energy* energy;
};

struct Context {
    char pad0[8];
    void* object;
    char pad1[0xCC];
    Modules* modules;
};

struct Owner {
    char pad[0x2148];
    float* config;
};

extern "C" {
extern char lbl_27_data_8D9E8[];
extern char lbl_27_data_248[];
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
extern float lbl_27_rodata_7948;

void* __dynamic_cast(void*, long, const void*, const void*, short);

void fn_27_35204C(void*, Context* context) {
    if (context->modules->query->test(6, 0)) {
        float* config = ((Owner*)__dynamic_cast(
            context->object, 0x3C,
            lbl_27_data_8D9E8, lbl_27_data_248, 1))->config;

        Result* result = (Result*)__dynamic_cast(
            context->modules->energy->get(0), 0,
            lbl_27_data_457C0, lbl_27_data_CDF8, 1);

        Pair value = result->speed();
        if (lbl_27_rodata_7948 != value.x) {
            value.x *= -*config;
            result->value = value;
        }
    }
}
}
