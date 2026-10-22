#pragma force_active on
namespace nw4r { namespace g3d { struct AnmObjChrRes; } }
struct soAnimChr {
    char pad[0x1C];
    int m1c;
    char pad2[0x20];
    int m40;
    char m44;
};
struct Arr {
    virtual void v0();
    virtual soAnimChr* get(int);
};
struct P8 { char p[8]; };
struct Res : P8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32();
    virtual int v33(int);
    virtual int v34(int);
};
struct Ke { char pad[4]; Res* r; };
struct Mid { char pad[0xD8]; Ke* k; };
struct Owner {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(int);
    virtual void v41(); virtual void v42();
    virtual void v43(int);
    char pad[0x34 - 4];
    char m34[0x8C - 0x34];
    Arr* arr;
    char pad2[0x165 - 0x90];
    unsigned char hi : 4;
    unsigned char f : 2;
    unsigned char lo : 2;
    char pad3[2];
    Mid* mid;
};
struct Res9 : P8 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); };
extern "C" {
void setAnimObj__9soAnimChrFffPQ34nw4r3g3d12AnmObjChrResUcUc(soAnimChr*, float, float, nw4r::g3d::AnmObjChrRes*, int, int);
nw4r::g3d::AnmObjChrRes* fn_27_151A4(Owner*, int, int, int, int, int);
void fn_27_1B614(Owner*, int, int, int, short*, int, float);
char* fn_27_20FE4(void*, int, int);
void fn_27_16CC0(Owner* o, int a, int b, int c, int d, char e, float f1, float f2) {
    Res* r;
    int x;
    soAnimChr* ch;
    int t;
    short sb[2];
    short sa[2];
    r = o->mid->k->r;
    t = r->v34(r->v33(c));
    ch = o->arr->get(a);
    o->v40(a);
    if (d == 0) {
        d = (fn_27_20FE4(o->m34, b, 1)[1] >> 1) & 1;
    }
    setAnimObj__9soAnimChrFffPQ34nw4r3g3d12AnmObjChrResUcUc(ch, f1, f2, fn_27_151A4(o, b, t, 1, 0, 0), d, 0);
    ch->m1c = b;
    ch->m40 = t;
    ch->m44 = e;
    o->v43(a);
    ((Res9*)o->mid->k->r)->v7();
    x = ch->m1c;
    sa[0] = 0x20;
    fn_27_1B614(o, a, x, 1, sa, 0, f1);
    sb[0] = 0x80;
    fn_27_1B614(o, a, x, 0, sb, 0, f1);
    o->f = 1;
}
}
