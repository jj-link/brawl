#pragma force_active on
struct V2 { float x, y; };
struct Words { int x, y; };
union Pair { Words bits; V2 vec; long long ll; };

struct Module {
    int pad[2];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual unsigned int has(int);
    virtual Words get(int, int);
};

extern "C" {
extern float lbl_41_rodata_C38[];

float fn_41_10830(V2*);
float fn_41_108AC(V2*, V2*);
Words fn_41_108CC(const V2*);
void fn_41_1592C(V2*, Words*);
void* fn_41_15FD4(char*, int);
void fn_41_1AD14(void*);
void fn_41_1ADA0(void*, short);
unsigned int fn_41_1AE7C(void*);
void fn_41_1CD70(void*, void*);
int fn_41_1C1D4(void*, void*);
void fn_41_1C2BC(void*, void*, int);
Words fn_41_1E384(void*);
void fn_41_16764(Words*, V2*, V2*);
int fn_41_1680C(V2*, V2*);
void fn_8003DBA8(V2*);

int fn_41_164EC(char* self) {
    float* base = lbl_41_rodata_C38;
    Pair sum;
    V2 out;
    char obj[0xE0];
    Pair input;
    Pair a, b;

    Module* mod =
        *(Module**)(*(char**)(*(char**)(self + 0x20) + 0xD8) + 0x10);
    sum.vec.x = base[1];
    sum.vec.y = base[1];
    out.x = base[1];
    out.y = base[1];

    if (!mod->has(0))
        return 0;

    Words initial = mod->get(255, 0);
    input.bits = initial;

    if (base[1] == fn_41_10830(&input.vec))
        return 0;

    for (int i = 0; i < 8; ++i) {
        void* unit = fn_41_15FD4(self, i);
        fn_41_1AD14(obj);
        fn_41_1CD70(obj, unit);
        if (fn_41_1AE7C(obj) == 1) {
            fn_41_1ADA0(obj, -1);
        } else if (fn_41_1C1D4(obj, *(void**)(self + 0x20)) == 0) {
            fn_41_1ADA0(obj, -1);
        } else {
            fn_41_1C2BC(obj, *(void**)(self + 0x20), 1);
            Words value = fn_41_1E384(obj);
            fn_41_1592C(&sum.vec, &value);
            fn_41_1ADA0(obj, -1);
        }
    }

    if (fn_41_10830(&sum.vec) <= base[10])
        return 0;

    a = sum;
    fn_8003DBA8(&a.vec);
    b = input;
    fn_8003DBA8(&b.vec);

    if (fn_41_108AC(&a.vec, &b.vec) >= base[11])
        return 0;

    if (mod->has(0) > 1) {
        fn_41_10830(&sum.vec);
        Words r = fn_41_108CC(&input.vec);
        out.x = *(float*)&r.x;
        out.y = *(float*)&r.y;
    } else {
        fn_41_16764(&input.bits, &sum.vec, &out);
    }

    if (fn_41_1680C(&sum.vec, &out))
        return 0;

    return 1;
}
}
