#pragma force_active on
typedef struct fn_27_inner {
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0c;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1c;
    int unk_20;
    int unk_24;
    int unk_28;
    float unk_2c;
} fn_27_inner;

typedef struct fn_27_outer {
    fn_27_inner* ptr;
} fn_27_outer;

extern "C" fn_27_inner* fn_27_111894(fn_27_outer* p, float f) {
    fn_27_inner* inner = p->ptr;
    inner->unk_2c = f;
    return inner;
}
