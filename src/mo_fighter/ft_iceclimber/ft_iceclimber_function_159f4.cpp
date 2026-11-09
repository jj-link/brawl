#pragma force_active on

extern "C" {
extern char lbl_105_data_698[];
extern char lbl_105_data_3860[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getLr__23soExternalValueAccesserFP11StageObject(void*);
int getSituationKind__23soExternalValueAccesserFP11StageObject(void*);
}

#define M10(b) virtual void* g##b##0(); virtual void* g##b##1(); virtual void* g##b##2(); virtual void* g##b##3(); virtual void* g##b##4(); virtual void* g##b##5(); virtual void* g##b##6(); virtual void* g##b##7(); virtual void* g##b##8(); virtual void* g##b##9();

struct B3c { char pad[0x3c]; };

struct T : B3c {
    virtual void* g02(); virtual void* g03(); virtual void* g04(); virtual void* g05(); virtual void* g06(); virtual void* g07(); virtual void* g08(); virtual void* g09();
    M10(1) M10(2) M10(3) M10(4) M10(5) M10(6) M10(7) M10(8) M10(9) M10(10) M10(11) M10(12) M10(13) M10(14)
    virtual void* g150(); virtual void* g151(); virtual void* g152(); virtual void* g153(); virtual void* g154();
};

struct V {
    virtual void a02(); virtual void a03(); virtual void a04(); virtual void a05(); virtual void a06(); virtual void a07(); virtual void a08(); virtual void a09();
    virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
    virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18();
    virtual unsigned int a19(int);
};

struct P {
    virtual void p2(); virtual void p3();
    virtual void p4(); virtual void p5(); virtual void p6(); virtual void p7();
    virtual void p8(); virtual void p9(); virtual void p10(); virtual void p11();
    virtual void p12(float); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21();
};

struct Q {
    virtual void q2(); virtual void q3();
    virtual void q4(); virtual int q5();
};

struct Modules {
    char pad0[0x0c];
    P* m_c;
    char pad1[0x04];
    Q* m_14;
    char pad2[0x4c];
    V* m_64;
};

struct Self {
    char pad0[0x08];
    T* m_8;
    char pad1[0xcc];
    Modules* m_d8;
};

extern "C" int fn_105_159F4(void* arg1, Self* self) {
    P* c;
    void* obj;
    if (self->m_d8->m_64->a19(0x22000010) == 1) {
        T* t = (T*)__dynamic_cast(self->m_8, 0x3c, lbl_105_data_698, lbl_105_data_3860, 0);
        if (t == 0) {
            return 1;
        }
        obj = t->g154();
        if (self->m_d8->m_14->q5() == 0) {
            if (getSituationKind__23soExternalValueAccesserFP11StageObject(obj) == 0 && obj != 0) {
                c = self->m_d8->m_c;
                c->p12(-getLr__23soExternalValueAccesserFP11StageObject(obj));
                self->m_d8->m_c->p21();
                self->m_8->g45();
                return 0;
            }
        }
    }
    return 1;
}
