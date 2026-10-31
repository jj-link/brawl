#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getParamFloat__8BaseItemFUl(void*, unsigned long);

extern void* lbl_27_bss_F0;
extern const char lbl_27_data_71BE0[];
extern const char lbl_27_data_CDC0[];
extern float lbl_27_rodata_46DC;
}

class ObjA {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual int call5C();
};

class ObjB {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual float call48();
};

class ObjC {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v64(float*, void*);
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void callC0(int, void*);
};

class ObjD {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual int call4C(int);
    virtual void call50(int);
};

class ObjE {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void call44(int, void*);
};

struct InnerObj {
    char pad0[8];
    ObjA* m8;
    char padC[0x48];
    ObjE* m54;
    char pad58[4];
    ObjB* m5C;
    char pad60[4];
    ObjD* m64;
    char pad68[0x14];
    void* m7C;
};

struct OuterObj {
    char pad[0xD8];
    InnerObj* mD8;
};

struct Self {
    char pad[0x60];
    OuterObj* m60;
};

struct TwoFields {
    int x;
    char y;
};

extern "C" int fn_27_29CB98(void*, void* self) {
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }

    if (fn_27_5BEA8(lbl_27_bss_F0) == 0) {
        return 1;
    }

    Self* s = (Self*)self;
    if (s->m60->mD8->m8->call5C() != 3) {
        return 1;
    }

    ObjD* d = s->m60->mD8->m64;
    ObjB* b = s->m60->mD8->m5C;
    ObjC* c = (ObjC*)__dynamic_cast(
        s->m60->mD8->m7C, 0, lbl_27_data_71BE0, lbl_27_data_CDC0, 1);

    float value[3];
    value[0] = lbl_27_rodata_46DC;
    value[1] = lbl_27_rodata_46DC;
    value[2] = lbl_27_rodata_46DC;

    float param = getParamFloat__8BaseItemFUl(self, 0x1D1A);
    float result = b->call48();
    value[0] = result * param;

    c->callC0(1, s->m60);
    c->v64(value, s->m60);

    if (d->call4C(0x12000000) == 0) {
        TwoFields event;
        event.x = 0x451;
        event.y = 0;
        s->m60->mD8->m54->call44(3, &event);
        d->call50(0x12000000);
    }

    return 1;
}
