#pragma force_active on
struct Vec { float x,y,z,w; };
struct Context { char pad[0x50]; Vec values[6]; char pad2[8]; int count; };
struct Work { Vec a,b; };
extern "C" {
extern const float lbl_805A4270, lbl_805A4278, lbl_805A427C, lbl_805A4280;
float fn_802DC0D4(int, Context*);
void fn_80287FE8(void*, void*, void*);
void fn_802DCCC8(void*, int** indices, Vec** data, void*, Context* ctx, void* a, void* b) {
    Work work __attribute__((aligned(16)));
    ++*indices;
    int index = **indices;
    work.b.w = lbl_805A4278;
    work.a = ctx->values[index];
    work.b.z = fn_802DC0D4(index, ctx);
    Vec* v = *data;
    ++*data;
    work.b.x = v->x;
    work.b.y = v->y;
    if (work.b.z < lbl_805A4270 && v->z > lbl_805A4270 && v->z - work.b.z > lbl_805A427C)
        work.b.z += lbl_805A4280;
    if (work.b.z > lbl_805A4270 && v->z < lbl_805A4270 && work.b.z - v->z > lbl_805A427C)
        work.b.z -= lbl_805A4280;
    v->z = work.b.z;
    fn_80287FE8(&work, a, b);
    ctx->count++;
}
}