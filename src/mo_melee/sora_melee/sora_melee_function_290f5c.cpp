#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    struct {
        unsigned int a : 10;
        unsigned int f : 6;
        unsigned int b : 16;
    } w;
} Obj;

extern "C" int fn_27_290F5C(Obj *p)
{
    return ((int)(p->w.f << 26)) >> 27;
}
