#pragma force_active on

struct Vec2 {
    float x, y;
};

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* v6(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned long long v13(short*);

    Vec2 speed(short* s) {
        union {
            unsigned long long raw;
            Vec2 v;
        } t;
        t.raw = v13(s);
        return t.v;
    }
};

struct Dst {
    char pad[8];
    Vec2 pos;

    void set(const Vec2& v) {
        pos = v;
    }
};

struct Inner {
    char pad[0x7C];
    VObj* vo;
};

struct Params {
    char pad[0x1C];
    float scale;
};

struct Obj {
    char pad0[0x60];
    Obj* sub;
    char pad1[0xD8 - 0x64];
    Inner* inner;
    char pad2[0x1A80 - 0xDC];
    Params* params;
};

extern "C" {

extern char lbl_27_data_457C0[];
extern char lbl_27_data_45940[];
extern char lbl_27_data_CDF8[];
extern const float lbl_27_rodata_642C;

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DAE14(Obj*);
void* __memcpy(void*, const void*, unsigned long);

inline void setup(Obj* self) {
    Obj* sub = self->sub;
    Dst* d26 = (Dst*)__dynamic_cast(
        sub->inner->vo->v6(0), 0,
        lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    Dst* d29 = (Dst*)__dynamic_cast(
        sub->inner->vo->v6(2), 0,
        lbl_27_data_45940, lbl_27_data_CDF8, 1);

    union {
        short s;
        unsigned int mask;
    } flag;
    flag.s = 1;

    Vec2 a = sub->inner->vo->speed(&flag.s);
    d26->set(a);
    d29->pos.x = lbl_27_rodata_642C;
}

inline void scaleAndSet(Vec2& w, float scale, Dst* e1, Dst* e2) {
    Vec2 prod;
    Vec2 flat;
    Vec2 result;

    prod.x = w.x * scale;
    prod.y = w.y * scale;
    __memcpy(&result, &prod, 8);
    w = result;
    flat.x = w.x;
    flat.y = lbl_27_rodata_642C;
    e1->set(flat);
    e2->pos.x = w.y;
}

inline void setup2(Obj* self) {
    Obj* sub = self->sub;
    Dst* e1 = (Dst*)__dynamic_cast(
        sub->inner->vo->v6(0), 0,
        lbl_27_data_457C0, lbl_27_data_CDF8, 1);
    Dst* e2 = (Dst*)__dynamic_cast(
        sub->inner->vo->v6(2), 0,
        lbl_27_data_45940, lbl_27_data_CDF8, 1);

    union {
        short s;
        unsigned int mask;
    } flag;
    flag.s = 1;

    Vec2 w = sub->inner->vo->speed(&flag.s);
    scaleAndSet(w, self->params->scale, e1, e2);
}

int fn_27_2E9F28(Obj* self) {
    setup(self);
    int ret = fn_27_1DAE14(self);
    setup2(self);
    return ret;
}

}
