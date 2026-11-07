#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_2_419C(void*, void*, int, int, int);
void fn_2_5178(void*);
void fn_2_6050(void*, unsigned int, int);
void fn_1_6DB4(void*, void*);
}

struct Class_728_base {
    char pad[0x3c];
};

class Class_728 : public Class_728_base {
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
    char pad[0x1CC];
    unsigned short owned[1];
};

struct Entry {
    unsigned char flag;
    char pad1[3];
    unsigned int idx;
    char pad2[0xC];
};

struct Self {
    char pad0[0x40];
    void* f40;
    char pad44[0x4C - 0x44];
    Entry entries[4];
    char padA0[0xA4 - 0x9C];
    char sub0A4[0xD8 - 0xA4];
    int fD8;
    int fDC;
    int fE0;
    char padE4[0x178 - 0xE4];
    void* f178;
    char pad17C[0x184 - 0x17C];
    Class_728* f184;
    char pad188[0x248 - 0x188];
    unsigned int f248;
    int f24C;
};

extern "C" void fn_2_C8C0(Self* self) {
    int dc;
    int e0;
    int d8;
    d8 = self->fD8;
    e0 = self->fE0;
    dc = self->fDC;
    Class_728* obj = (Class_728*)__nw__FUlQ25Heaps8HeapType(0x720, 0x2A);
    if (obj != 0) {
        obj = (Class_728*)fn_2_419C(obj, self->sub0A4, dc, e0, d8);
    }
    obj->slot21();
    self->f184 = obj;
    Entry* e = self->entries;
    char* p = (char*)self;
    for (int i = 0; i < 4; i++) {
        unsigned int idx;
        if ((e->flag >> 7) & 1) {
            idx = *(unsigned int*)(p + 0x50);
        } else {
            idx = 0xFFFFFFFF;
        }
        if (idx != 0xFFFFFFFF) {
            Class_728* o = self->f184;
            if (o->owned[idx] != 0) {
                o->owned[idx] = o->owned[idx] - 1;
                fn_2_5178(o);
            }
        }
        e++;
        p += 0x14;
    }
    if (self->f248 != 0xFFFFFFFF) {
        fn_2_6050(self->f184, self->f248, self->f24C);
    }
    fn_1_6DB4(self->f40, self->f178);
}
