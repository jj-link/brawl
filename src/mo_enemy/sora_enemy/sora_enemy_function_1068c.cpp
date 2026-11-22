#pragma force_active on
#include <so/so_value_accesser.h>

struct V2 {
    float x, y;
};

struct Words {
    int x, y;
};

union Pair {
    Words bits;
    V2 vec;
    unsigned long long raw;
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
    virtual unsigned int getInt(int);
    virtual Words get(int, int);
};

extern "C" {

extern const float lbl_41_rodata_BE0;
extern const float lbl_41_rodata_BF4;

float fn_41_10830(V2*);
float fn_41_108AC(V2*, V2*);
unsigned long long fn_41_108CC(const V2*, float);


}

inline V2 calculate(V2* arg0, V2* arg1)
{
    V2 d;
    Pair t;
    Pair u;
    t.raw = fn_41_108CC(arg0, lbl_41_rodata_BF4);
    float s = fn_41_108AC(arg0, arg1);
    u.raw = fn_41_108CC(&t.vec, s);
    d.x = arg1->x - u.vec.x;
    d.y = arg1->y - u.vec.y;
    return d;
}

inline void calculate_into(V2* a, V2* b, V2* out)
{
    V2 e = calculate(a, b);
    out->x = e.x;
    out->y = e.y;
}

extern "C" {
void fn_41_1068C(char* self, Module* m, V2* p) {
    struct Frame {
        V2 dir;
        Pair input;
    } frame;

    Words initial = m->get(0xFF, 0);
    frame.input.bits = initial;

    if (lbl_41_rodata_BE0 == fn_41_10830(&frame.input.vec))
        return;

    frame.dir.x = lbl_41_rodata_BE0;
    frame.dir.y = lbl_41_rodata_BE0;

    if (lbl_41_rodata_BE0 == fn_41_10830(p))
        return;

    if (fn_41_108AC(p, &frame.input.vec) >= lbl_41_rodata_BE0)
        return;

    if ((unsigned int)m->getInt(0) > 1U) {
        unsigned long long rawResult =
            fn_41_108CC(&frame.input.vec, fn_41_10830(p));
        Pair result;
        result.raw = rawResult;
        frame.dir.x = result.vec.x;
        frame.dir.y = result.vec.y;
    } else {
        calculate_into(&frame.input.vec, p, &frame.dir);
    }

    soModuleAccesser* acc = *(soModuleAccesser**)(self + 0x3C);
    float scale = soValueAccesser::getValueFloat(acc, 0xBF0, 0);
    unsigned long long rawOutput = fn_41_108CC(&frame.dir, scale);
    Pair output;
    output.raw = rawOutput;
    p->x = output.vec.x;
    p->y = output.vec.y;
}

}
