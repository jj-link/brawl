#include <types.h>
#pragma force_active on
struct Cmd { float *cur; u32 pad; u32 *top; };
static inline void cp(float *p, float y, float x, float *a, float *b) {
    float v0, v1, v2, v3;
    p[0] = x;
    v0 = a[2]; p[1] = y;
    v1 = a[3]; p[2] = v0;
    v2 = b[0]; p[3] = v1;
    v3 = b[1]; p[4] = v2;
    v2 = b[2]; p[5] = v3;
    v3 = b[3]; p[6] = v2;
    p[7] = v3;
}
void fn_8028F8F4(float *a, float *b, void *unused, struct Cmd *s) {
    float *p = s->cur;
    u32 *t = s->top;
    float x = a[0];
    *t = 0x10050004;
    cp(p, a[1], x, a, b);
    s->top = t + 1;
    s->cur = s->cur + 8;
}
