#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int :2;
    unsigned int f:2;
    unsigned int rest:28;
} Obj;

extern "C" {
void fn_40_24AB8(Obj* obj, unsigned int v) {
    obj->f = v;
}
}
