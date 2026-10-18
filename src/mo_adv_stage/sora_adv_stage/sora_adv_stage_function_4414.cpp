#pragma force_active on
typedef struct {
    int a;
    int b;
    int c;
} Vec3i;

extern "C" void fn_40_4414(Vec3i* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
}
