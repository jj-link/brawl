#pragma force_active on
typedef struct {
    char pad0[0xc];
    float x;
    float y;
    float z;
    char pad1[0xc];
    float bx;
    float by;
    float bz;
} FnStruct;

extern "C" void fn_27_25454(FnStruct* s) {
    s->x = s->bx;
    s->y = s->by;
    s->z = s->bz;
}
