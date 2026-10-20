#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int f : 5;
    unsigned int g : 27;
} S;

extern "C" {
void fn_27_1A1188(S *p, unsigned int v) {
    p->f = v;
}
}
