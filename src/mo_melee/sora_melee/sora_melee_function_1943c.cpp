#pragma force_active on

class soAnimChr {
public:
    void turnBack();
    int m_first;
    char pad[0x18];
    int m_1c;
    char pad2[0x10];
};

struct Item2 {
    char pad[0x28];
    int m_28;
};

class List1 {
public:
    virtual void v0();
    virtual soAnimChr* get(int i);
    virtual void v2();
    virtual int count();
};

class List2 {
public:
    virtual void v0();
    virtual Item2* get(int i);
    virtual void v2();
    virtual int count();
};

struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
};

struct S2 { char pad[4]; Class_90D8* m_4; };
struct S1 { char pad[0xd8]; S2* m_d8; };

extern "C" void fn_27_2058C(Item2*);

class Self {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24(float f);
};

extern "C" void fn_27_1943C(Self* self) {
    char* p = (char*)self;
    ((soAnimChr*)(p + 0x3c))->turnBack();
    if (*(int*)(p + 0x88) != -1) {
        ((soAnimChr*)(p + 0x6c))->turnBack();
        self->slot24(*(float*)(p + 0x64));
    }
    int n = (*(List1**)(p + 0x8c))->count();
    for (int i = 0; i < n; i++) {
        if ((*(List1**)(p + 0x8c))->get(i)->m_1c != -1) {
            (*(List1**)(p + 0x8c))->get(i)->turnBack();
        }
    }
    n = (*(List2**)(p + 0x90))->count();
    for (int i = 0; i < n; i++) {
        if ((*(List2**)(p + 0x90))->get(i)->m_28 != -1) {
            fn_27_2058C((*(List2**)(p + 0x90))->get(i));
        }
    }
    if (*(int*)(p + 0x3c) != 0) {
        (*(S1**)(p + 0x168))->m_d8->m_4->fn_27_7AEDC();
    }
}
