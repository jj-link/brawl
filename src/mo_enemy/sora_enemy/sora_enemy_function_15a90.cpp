#pragma force_active on
struct V2 { float x, y; };
struct V3 { float x, y, z; };
struct Words { int x, y; };
union Pair { Words bits; V2 vec; };
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
    virtual void v52(); virtual void v53(); virtual void v54();
    virtual int has(int, int);
    virtual void unused();
    virtual Words get(int, int);
};
extern "C" {
extern float lbl_41_rodata_C38[];
V3* fn_41_5AC4(V3*, float, float, float);
V2* fn_41_2354(V2*, float, float);
float fn_41_108AC(V2*, V2*);
void fn_8003DC64(V2*, float, V2*);
float fn_41_10830(V2*);
V2 fn_41_108CC(const V2*, float);
Words fn_41_15A90(char* self, const Words* value, int id) {
    float* base = lbl_41_rodata_C38;
    Pair input = *(const Pair*)value;
    Module* mod = *(Module**)(*(char**)(self + 0xd8) + 0x10);
    if (!mod->has(id, 0)) return input.bits;
    Pair b;
    Words a = mod->get(id, 0);
    b.bits = a;
    V3 v, axis, cross;
    fn_41_5AC4(&v, b.vec.x, b.vec.y, base[1]);
    fn_41_5AC4(&axis, base[1], base[1], base[4]);
    fn_41_5AC4(&cross, base[1], base[1], base[1]);
    cross.x = v.y * axis.z - v.z * axis.y;
    cross.y = v.z * axis.x - v.x * axis.z;
    cross.z = v.x * axis.y - v.y * axis.x;
    V2 temp;
    if (fn_41_108AC(fn_41_2354(&temp, cross.x, cross.y), &input.vec) >= base[1])
        fn_8003DC64(&b.vec, base[5], &b.vec);
    else
        fn_8003DC64(&b.vec, base[6], &b.vec);
    input.vec = fn_41_108CC(&b.vec, fn_41_10830(&input.vec));
    return input.bits;
}
}