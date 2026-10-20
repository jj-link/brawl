#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int val;
} S;

extern "C" int fn_27_1A2290(S *p) {
    unsigned int t = p->val;
    t = ((t >> 25) & 0xF) << 28;
    return (int)t >> 29;
}
