#pragma force_active on
struct Block { unsigned int w[11]; float f[5]; };
struct Obj { char pad[0x84]; Block b; char padc4[0x64]; float a[8]; float out[8]; float x, y; };
extern "C" void fn_8009D014(Obj* p, const Block* q) {
    int changed = 0;
    if (*(float*)&p->b.w[8] != *(const float*)&q->w[8] || *(float*)&p->b.w[9] != *(const float*)&q->w[9]) changed = 1;
    p->b.w[0] = q->w[0]; p->b.w[1] = q->w[1]; p->b.w[2] = q->w[2]; p->b.w[3] = q->w[3];
    p->b.w[4] = q->w[4]; p->b.w[5] = q->w[5]; p->b.w[6] = q->w[6]; p->b.w[7] = q->w[7];
    p->b.w[8] = q->w[8]; p->b.w[9] = q->w[9]; p->b.w[10] = q->w[10];
    p->b.f[0] = q->f[0]; p->b.f[1] = q->f[1]; p->b.f[2] = q->f[2]; p->b.f[3] = q->f[3]; p->b.f[4] = q->f[4];
    if (changed) {
        float y;
        float x = *(float*)&p->b.w[8] + p->x;
        y = *(float*)&p->b.w[9] + p->y;
        p->out[0] = p->a[0] + x;
        p->out[1] = p->a[1] + x;
        p->out[2] = p->a[2] + y;
        p->out[3] = p->a[3] + y;
        p->out[4] = p->a[4] + x;
        p->out[5] = p->a[5] + x;
        p->out[6] = p->a[6] + y;
        p->out[7] = p->a[7] + y;
    }
}