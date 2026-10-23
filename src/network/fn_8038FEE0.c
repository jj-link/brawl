#pragma force_active on
typedef unsigned int u32;

typedef struct Block {
    u32 a, b, c, d;
} Block;

extern void fn_8038F550(Block *, Block *, Block *);

void fn_8038FEE0(Block *arg0, Block *arg1, const Block *arg2) {
    Block buf;
    u32 a, c, b, t;

    a = arg2->a;
    b = arg2->b;
    c = arg2->c;
    t = a ^ arg0->a;
    a = arg2->d;
    buf.a = t;
    buf.b = b ^ arg0->b;
    buf.c = c ^ arg0->c;
    buf.d = a ^ arg0->d;

    fn_8038F550(arg0, arg1, &buf);

    arg0->a = arg1->a;
    arg0->b = arg1->b;
    arg0->c = arg1->c;
    arg0->d = arg1->d;
}
