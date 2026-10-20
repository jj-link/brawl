#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int a : 4;
    unsigned int b : 4;
    unsigned int c : 24;
} FlagObj;

extern "C" {
void fn_27_D1F64(FlagObj* o, unsigned int v) {
    o->b = v;
}
}
