#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int a : 14;
    unsigned int b : 7;
    unsigned int c : 11;
} FnStruct;

void fn_48_B86C(FnStruct *s, unsigned int v) {
    s->b = v;
}
}
