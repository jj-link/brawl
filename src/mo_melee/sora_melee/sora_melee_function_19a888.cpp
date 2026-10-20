#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int hi : 5;
    unsigned int rest : 27;
} S;

extern "C" {
void fn_27_19A888(S* p, unsigned int v) {
    p->hi = v;
}
}
