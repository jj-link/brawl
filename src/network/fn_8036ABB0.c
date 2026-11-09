#pragma force_active on
typedef struct Pair { int a, b; } Pair;
typedef struct Node Node;
struct Node {
    Pair pair;
    int c, d, e;
    Node *next;
};
typedef struct Context {
    char pad[0x454];
    Node *head;
    Node *tail;
} Context;
typedef struct Other {
    char pad[0x18];
    int value;
} Other;
extern void *fn_8035DFE8(int);
extern void fn_803732E0(Context **, const void *);
extern char lbl_8048EDE8[];
int fn_8036ABB0(Context **arg0, Pair *arg1, int arg2, Other *arg3, int arg4)
{
    Context *ctx = *arg0;
    Node *node = fn_8035DFE8(0x18);
    if (node == 0) {
        fn_803732E0(arg0, lbl_8048EDE8);
        return 1;
    }
    node->pair = *arg1;
    node->c = arg2;
    if (arg3 != 0)
        node->e = arg3->value;
    else
        node->e = 0;
    node->d = arg4;
    node->next = 0;
    if (ctx->head == 0)
        ctx->head = node;
    if (ctx->tail != 0)
        ctx->tail->next = node;
    ctx->tail = node;
    return 0;
}