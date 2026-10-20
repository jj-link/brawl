#pragma force_active on
extern "C" {
typedef struct S {
    unsigned int x0;
    unsigned int x4;
    unsigned int low : 4;
    signed int val : 4;
    unsigned int rest : 24;
} S;

int fn_27_1A47D4(S* s) {
    return s->val;
}
}
