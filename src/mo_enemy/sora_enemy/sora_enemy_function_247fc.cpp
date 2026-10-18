#pragma force_active on
struct V2 {
    float x, y;
    void set(float a, float b) { x = a; y = b; }
    V2() {}
    V2(const V2& o) : x(o.x), y(o.y) {}
    V2(float a, float b) : x(a), y(b) {}
};

struct V3 {
    float x, y, z;
};

extern "C" {
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
extern float lbl_41_rodata_D58;

void* __dynamic_cast(void*, long, const void*, const void*, short);
V3* fn_41_5AC4(V3*, float, float, float);
void getCenterPos__23emExternalValueAccesserFP5Enemy(V3*, void*);
V3* fn_41_534C(V3*, const V3&);
void fn_41_249FC(V2*, const V2*, const V2*);
void fn_800400FC(V2*, const V2*, int);
V2* fn_41_2354(V2*, float, float);
float fn_41_24A20(const V2*, const V2*);

int fn_41_247FC(char* self, V2* input) {
    char* area = (char*)__dynamic_cast(
        *(void**)(*(char**)(self + 0xd8) + 0x90),
        0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, 1);

    if (!*(int*)(area + 0x5c))
        return 6;

    struct Frame {
        V2 w, v, pos;
        V3 c;
        V2 bn;
        float p0;
        V2 b;
        float p1[2];
        V2 an;
        float p2;
        V2 a;
        float p3[2];
        V3 center;
    } f;

    fn_41_5AC4(&f.center,
               lbl_41_rodata_D58,
               lbl_41_rodata_D58,
               lbl_41_rodata_D58);

    getCenterPos__23emExternalValueAccesserFP5Enemy(
        &f.c,
        __dynamic_cast(*(void**)(self + 8), 0x3c,
                       __RTTI__5Enemy, __RTTI__11StageObject, 1));

    fn_41_534C(&f.center, f.c);
    f.pos.set(f.center.x, f.center.y);

    fn_41_249FC(&f.a, &f.pos, (V2*)(area + 0x5c8));
    fn_800400FC(&f.an, &f.a, 0);
    float first = fn_41_24A20(
        &f.an, fn_41_2354(&f.v, input->x, input->y));

    fn_41_249FC(&f.b, &f.pos, (V2*)(area + 0x5d0));
    fn_800400FC(&f.bn, &f.b, 0);
    float second = fn_41_24A20(
        &f.bn, fn_41_2354(&f.w, input->x, input->y));

    if (first >= lbl_41_rodata_D58 && second >= lbl_41_rodata_D58)
        return 0;
    if (first <= lbl_41_rodata_D58 && second <= lbl_41_rodata_D58)
        return 1;
    if (first <= lbl_41_rodata_D58 && second >= lbl_41_rodata_D58)
        return 2;
    if (first >= lbl_41_rodata_D58 && second <= lbl_41_rodata_D58)
        return 3;
    return 6;
}
}
