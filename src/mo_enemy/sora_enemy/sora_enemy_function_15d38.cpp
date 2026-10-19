#pragma force_active on
struct V2 {
    float x, y;
};

struct U64 {
    int x, y;
};

struct Module {
    int pad[2];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual int has(int, int);
    virtual void unused();
    virtual U64 get(int, int);
};

extern "C" {
extern float lbl_41_rodata_C38[];

float fn_8003DDD0(const V2*, const V2*);
V2* fn_41_2354(V2*, float, float);
float fn_41_108AC(V2*, V2*);

float fn_41_15D38(char* self, V2* input, int id) {
    float angle = lbl_41_rodata_C38[1];
    Module* mod = *(Module**)(*(char**)(self + 0xd8) + 0x10);

    if (!mod->has(id, 0))
        return angle;

    union Pair {
        U64 bits;
        V2 vec;
    };

    Pair b;
    U64 a = mod->get(id, 0);
    b.bits = a;

    angle = lbl_41_rodata_C38[2] * fn_8003DDD0(&b.vec, input);

    V2 temp;
    if (fn_41_108AC(fn_41_2354(&temp, b.vec.x, b.vec.y), input)
        >= lbl_41_rodata_C38[1])
        return lbl_41_rodata_C38[8] - angle;

    return angle - lbl_41_rodata_C38[8];
}
}
