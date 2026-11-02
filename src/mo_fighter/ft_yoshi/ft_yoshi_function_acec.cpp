#pragma force_active on

extern "C" {
void fn_27_1FA94(void* self, int* a, int* b, int c, int d);
void fn_27_1FE18(void* self, void* target);
}

struct Pad8 {
    int unk0;
    int unk4;
};

class Class_8DBC {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16C80();
    virtual void fn_95_17664();
    virtual void fn_95_1765C();
    virtual void fn_95_17654();
    virtual void fn_95_1764C();
    virtual void fn_95_17644();
    virtual void fn_95_1763C();
    virtual void fn_95_17634();
    virtual void fn_95_1762C();
    virtual void fn_95_17624();
    virtual void fn_95_1761C();
    virtual void fn_95_17614();
    virtual void fn_95_1760C();
    virtual void fn_95_175BC();
    virtual void fn_95_17604();
    virtual void fn_95_175F4();
    virtual int fn_95_175E4(unsigned int);
    virtual void fn_95_175D4(unsigned int);
};

class Class_R : public Pad8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void* s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual int s11(int, int, int);
};

class Class_V : public Pad8 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void* s13();
};

class Class_S {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual int s10();
};

class Class_U {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual int s5();
};

extern "C" void fn_95_ACEC(void* arg0) {
    char* ft = *(char**)((char*)arg0 + 0x60);
    Class_8DBC* q = *(Class_8DBC**)(*(char**)(ft + 0xd8) + 0x64);
    if (q->fn_95_175E4(0x1200003d) == 0) {
        Class_R* r = *(Class_R**)(*(char**)(ft + 0xd8));
        Class_S* s = (Class_S*)r->s4();
        int v = s->s10();
        int arr[4];
        arr[3] = r->s11(v, 4, 0);
        Class_U* u = *(Class_U**)(*(char**)(ft + 0xd8) + 0xc0);
        Class_V* vv = *(Class_V**)(*(char**)(ft + 0xd8) + 0x4);
        char* w = (char*)vv->s13();
        int e8 = *(int*)(w + 0xe8);
        arr[0] = e8;
        arr[1] = e8;
        arr[2] = arr[3];
        int c = u->s5();
        fn_27_1FA94((char*)arg0 + 0x22288, &arr[2], &arr[1], c, 0);
        Class_V* vv2 = *(Class_V**)(*(char**)(ft + 0xd8) + 0x4);
        char* t = (char*)vv2->s13();
        fn_27_1FE18((char*)((int)arg0 + 0x22288), t);
        Class_8DBC* q2 = *(Class_8DBC**)(*(char**)(ft + 0xd8) + 0x64);
        q2->fn_95_175D4(0x1200003d);
    }
}
