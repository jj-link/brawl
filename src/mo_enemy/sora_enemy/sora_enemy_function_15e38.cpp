#pragma always_inline on
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on
struct V2 { float x, y; };
struct Words { int x, y; };
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
    virtual void v56();
    virtual Words get(int, int);
};
extern "C" {
extern float lbl_41_rodata_C38[];
float fn_41_10830(float*);
float fn_41_15FB0(float, float);
int fn_41_15E38(char* self, V2* input, int id) {
    float* constants = lbl_41_rodata_C38;
    if (constants[1] == fn_41_10830((float*)input))
        return 3;
    Module* mod = *(Module**)(*(char**)(self + 0xd8) + 0x10);
    if (!mod->has(id, 0))
        return 3;
    V2 output;
    *(Words*)&output = mod->get(id, 0);
    if (constants[1] == fn_41_10830((float*)&output))
        return 3;
    float first = constants[2] * fn_41_15FB0(input->y, input->x);
    float second = constants[2] * fn_41_15FB0(output.y, output.x);
    float difference = second - first;
    if (difference > constants[1]) {
        float magnitude = (float)(double)nw4r::ut::Abs(difference);
        if (magnitude <= constants[9])
            return 1;
        return 2;
    }
    if (difference < constants[1]) {
        float magnitude = (float)(double)nw4r::ut::Abs(difference);
        if (magnitude <= constants[9])
            return 2;
        return 1;
    }
    return 0;
}
}