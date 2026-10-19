#pragma force_active on
struct V2 {
    float x, y;
};

struct Words {
    int x, y;
};

union Pair {
    Words bits;
    V2 vec;
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
    virtual void v55();
    virtual int has(int);
    virtual Words get(int, int);
};

struct Unit {
    virtual void v0();
    virtual void v1();
    virtual Words get();
};

extern "C" {
extern float lbl_41_rodata_C3C;

float fn_41_10830(V2*);
float fn_41_108AC(V2*, V2*);
Unit* fn_41_15FD4(void*, int);
bool fn_41_1AE7C(Unit*);
bool fn_41_1C678(Unit*);
void fn_41_1592C(V2*, Words*);
Words fn_27_899AC(V2*, V2*);
int fn_41_1680C(V2*, V2*);

int fn_41_170B0(char* self, int id) {
    Module* mod =
        *(Module**)(*(char**)(*(char**)(self + 0x20) + 0xD8) + 0x10);

    V2 sum = {lbl_41_rodata_C3C, lbl_41_rodata_C3C};
    V2 out = {lbl_41_rodata_C3C, lbl_41_rodata_C3C};
    Pair input;

    if (!mod->has(0))
        return 0;

    Words initial = mod->get(255, 0);
    input.bits = initial;

    if (lbl_41_rodata_C3C == fn_41_10830(&input.vec))
        return 0;

    if (id == -1) {
        for (int i = 0; i < 8; ++i) {
            Unit* unit = fn_41_15FD4(self, i);
            if (fn_41_1AE7C(unit) != 1 && fn_41_1C678(unit)) {
                Words value = unit->get();
                fn_41_1592C(&sum, &value);
            }
        }
    } else {
        Unit* unit = fn_41_15FD4(self, id);
        if (fn_41_1AE7C(unit) == 0 && fn_41_1C678(unit) == 1) {
            Words value = unit->get();
            fn_41_1592C(&sum, &value);
        }
    }

    if (lbl_41_rodata_C3C == fn_41_10830(&sum))
        return 0;

    if (fn_41_108AC(&sum, &input.vec) >= lbl_41_rodata_C3C)
        return 0;

    Words result = fn_27_899AC(&sum, &input.vec);
    out.x = *(float*)&result.x;
    out.y = *(float*)&result.y;

    return !fn_41_1680C(&sum, &out);
}
}
