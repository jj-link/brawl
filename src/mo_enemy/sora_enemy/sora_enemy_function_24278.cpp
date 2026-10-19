#pragma force_active on
struct V2 {
    float x, y;
};

extern "C" {
void fn_8003DC64(V2*, float, V2*);

V2 fn_41_24278(V2* p, float a, float b, float c) {
    p->x = p->x * a;
    fn_8003DC64(p, c, p);
    p->x = p->x * b;
    p->y = p->y * b;
    return *p;
}
}
