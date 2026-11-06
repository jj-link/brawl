#pragma force_active on

typedef long long s64;

typedef struct Node Node;
struct Node {
    int status, flag, sock, id;
    s64 time;
    char pad[0x24];
    void *handle;
    Node *next;
    int tail;
};

typedef struct State {
    char pad0[0x220];
    int socket;
    char pad224[0x22c];
    Node *head;
} State;

extern int CanReceiveOnSocket(int);
extern int accept(int, void *, void *);
extern void closesocket(int);
extern void *fn_8035DFE8(int);
extern void *memset(void *, int, unsigned long);
extern s64 fn_8035D258(int);
extern void fn_8036FD90(void **);
extern void *fn_8035A460(int, int, void (*)(void **));
extern int fn_8035CD04(int, int);
extern int fn_8035CD7C(int, int);
extern int fn_8035CDD8(int, int);
extern int fn_8035CE34(int);
extern int fn_8035CE98(int);
extern int fn_8036F06C(State **, Node *);
extern int fn_8036F3CC(State **, Node *);
extern int fn_8036F5CC(State **, Node *);
extern void fn_8036F9F0(State **, Node *);

int fn_8036FB04(State **self)
{
    State *ctx;
    Node *node, *iter;
    int active_socket;
    State *state = *self;
    Node *next;
    int sock, result;

    if (state->socket != -1 && CanReceiveOnSocket(state->socket)) {
        sock = accept(state->socket, 0, 0);
        if (sock != -1) {
            ctx = *self;
            node = fn_8035DFE8(0x48);
            if (node == 0) {
                node = 0;
            } else {
                memset(node, 0, 0x48);
                node->status = 100;
                node->flag = 0;
                node->sock = -1;
                node->id = -1;
                node->time = fn_8035D258(0) + 300;
                node->next = ctx->head;
                node->handle = fn_8035A460(0x18, 0, fn_8036FD90);
                ctx->head = node;
            }

            if (node) {
                node->status = 104;
                node->sock = sock;
                fn_8035CD04(sock, 0);
                active_socket = node->sock;
                fn_8035CD7C(active_socket, 0x4000);
                fn_8035CD7C(active_socket, 0x8000);
                fn_8035CD7C(active_socket, 0x10000);
                fn_8035CD7C(active_socket, 0x20000);
                fn_8035CD7C(active_socket, 0x40000);
                fn_8035CDD8(active_socket, 0x4000);
                fn_8035CDD8(active_socket, 0x8000);
                fn_8035CDD8(active_socket, 0x10000);
                fn_8035CE34(active_socket);
                fn_8035CE98(active_socket);
            } else {
                closesocket(sock);
            }
        }
    }

    iter = state->head;
    while (iter) {
        result = 0;
        next = iter->next;
        if (iter->status != 105) {
            if (iter->flag)
                result = fn_8036F06C(self, iter);
            else
                result = fn_8036F3CC(self, iter);
        }
        if (result == 0 && iter->status == 105)
            result = fn_8036F5CC(self, iter);
        if (iter->status == 106 || result != 0 ||
            iter->time < fn_8035D258(0))
            fn_8036F9F0(self, iter);
        iter = next;
    }
    return 0;
}
