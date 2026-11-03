#pragma force_active on
typedef struct Block { float v[12]; } Block;
extern void fn_802829F8(Block *, const Block *, const Block *);
void fn_80284240(Block *out, const Block *a, const Block *b)
{
    Block tmp __attribute__((aligned(16)));
    int x, y;
    char *row;
    int j, i;
    for (i = 0, x = 0; i < 2; i++, x += 96) {
        row = (char *)out + x;
        for (j = 0, y = 0; j < 2; j++, y += 48) {
            Block *p;
            fn_802829F8(&tmp, (const Block *)((const char *)a + x), (const Block *)((const char *)b + y));
            fn_802829F8((Block *)((char *)(y + (unsigned int)row)), (const Block *)((const char *)a + x + 48), (const Block *)((const char *)b + y + 96));
            p = (Block *)((char *)(y + (unsigned int)row));
            p->v[0] += tmp.v[0];
            p->v[1] += tmp.v[1];
            p->v[2] += tmp.v[2];
            p->v[3] += tmp.v[3];
            p->v[4] += tmp.v[4];
            p->v[5] += tmp.v[5];
            p->v[6] += tmp.v[6];
            p->v[7] += tmp.v[7];
            p->v[8] += tmp.v[8];
            p->v[9] += tmp.v[9];
            p->v[10] += tmp.v[10];
            p->v[11] += tmp.v[11];
        }
    }
}