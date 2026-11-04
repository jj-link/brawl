#pragma force_active on
struct St { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual int get(); };
struct K { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void call(int,int,int); };
struct P { union { unsigned long long bits; struct { float f; int i; }; }; };
struct WW { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void* a(int); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual P get(short*); };
struct Ms { char p[0x28]; K* k; char q[0x44]; St* st; char r[8]; WW* w; };
struct O { char p[0xd8]; Ms* m; };
struct E { char p[8]; float a; float b; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(O*, unsigned long, unsigned long);
void fn_27_89DAC(int, O*);
extern char lbl_27_data_13690[];
extern char lbl_27_data_CDF8[];
extern float lbl_27_rodata_7488;
void fn_27_3113A0(void* self, O* o) {
    switch (o->m->st->get()) {
    case 0x115: {
        short sh = 1;
        P p1;
        P p2 = o->m->w->get(&sh);
        p1.bits = p2.bits;
        void* r = o->m->w->a(3);
        E* e = (E*)__dynamic_cast(r, 0, lbl_27_data_13690, lbl_27_data_CDF8, 1);
        float v[2];
        v[0] = p1.f / getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(o, 0xfba, 0);
        v[1] = lbl_27_rodata_7488;
        e->a = v[0];
        e->b = v[1];
        ((unsigned char*)e)[5] |= 0x80;
        fn_27_89DAC(2, o);
        fn_27_89DAC(0, o);
        break;
    }
    case 0x11a:
    case 0x11b:
        o->m->k->call(0, 1, 2);
        break;
    }
}
}