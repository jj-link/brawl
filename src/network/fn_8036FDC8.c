#pragma force_active on
typedef unsigned long long u64;
typedef struct Node Node;
struct Node {
    int a;
    int b;
    int c;
    int d;
    u64 time;
    char pad[0x24];
    void *handle;
    Node *next;
    int tail;
};
typedef struct Context {
    char pad[0x450];
    Node *head;
} Context;
extern void *fn_8035DFE8(int);
extern void *memset(void *, int, unsigned long);
extern u64 fn_8035D258(int);
extern void fn_8036FD90(void **);
extern void *fn_8035A460(int, int, void (*)(void **));

Node *fn_8036FDC8(Context **arg0, int arg1, int arg2) {
    Node *node;
    Context *ctx;
    ctx = *arg0;
    node = fn_8035DFE8(0x48);
    if (node == 0) return 0;
    memset(node, 0, 0x48);
    node->a = 100;
    node->b = arg2;
    node->c = -1;
    node->d = arg1;
    node->time = fn_8035D258(0) + 300;
    node->next = ctx->head;
    node->handle = fn_8035A460(0x18, 0, fn_8036FD90);
    ctx->head = node;
    return node;
}