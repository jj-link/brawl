#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int f : 6;
    unsigned int rest : 26;
} GrBits;

extern "C" {
void fn_40_1E590(GrBits* obj, unsigned int value) {
    obj->f = value;
}
}
