#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int skip : 12;
    signed int f : 6;
    unsigned int rest : 14;
} S;

extern "C" int fn_54_10198(S *p) {
    return p->f;
}
