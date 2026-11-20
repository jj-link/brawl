#pragma force_active on
typedef struct { int a, b, c, d; } Item;
void fn_80281BC0(Item *__restrict dst, const Item *__restrict src, int count) {
    int i;
    for (i = 0; i < count; i++) {
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
        dst++;
        src++;
    }
}