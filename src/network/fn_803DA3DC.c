#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Node Node;
struct Node {
    u16 flags;
    u16 pad2;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    Node *next;
    Node *prev;
};

typedef struct Pool {
    u8 pad0[0x162C];
    Node *f162C;
    Node *f1630;
    s32 f1634;
    s32 f1638;
} Pool;

extern s32 fn_803D936C(Pool *, Node **, void *, Node **, s32 *);

s32 fn_803DA3DC(Pool *pool, void *arg1, Node **ppnode, s32 *arg3) {
    if (pool->f1630 == 0) {
        pool->f162C->f4 = pool->f1638;
        pool->f162C->f8 = pool->f1638;
        *ppnode = pool->f162C;
        return 0;
    }
    {
        s32 r = fn_803D936C(pool, &pool->f1630, arg1, ppnode, arg3);
        return r & ((-r | r) >> 31);
    }
}
