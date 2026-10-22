#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;
struct E { u8 a; void* b; u32 c; };
struct L { E* p; int n; };

extern "C" void fn_80086610(L* l, void* key) {
    for (int i = 0; i < l->n; i++) {
        if (l->p[i].b == key) {
            l->p[i].b = 0;
            int n = l->n - 1;
            l->n = n;
            E* s = &l->p[n];
            E* d = &l->p[i];
            d->a = s->a;
            d->b = s->b;
            d->c = s->c;
            return;
        }
    }
}
