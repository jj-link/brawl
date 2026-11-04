#include <types.h>
#pragma force_active on

typedef struct Buffer { int a, b, c, d; } Buffer;
typedef struct Callback { int a, b; } Callback;
typedef struct State { char pad[0x1c0]; Callback cb1, cb5; } State;
typedef struct Context { State *state; } Context;
typedef struct Node {
    int status, pad04, socket, id;
    u64 time;
    int pad18;
    Buffer input;
    char output[8];
    int active, pad38;
    void *queue;
} Node;
typedef struct Event { int id, time, data; } Event;

extern int fn_8035A590(void *);
extern Buffer *fn_8035A598(void *, int);
extern void fn_8035A918(void *, int);
extern u64 fn_8035D258(int);
extern int fn_8035D654(int);
extern void *fn_8035DFE8(int);
extern void fn_80369D58(Context *, int, int, char *, int);
extern int fn_8036A6DC(Context *, int, Buffer *, int *, int *, char *);
extern int fn_8036A81C(Context *, int, Buffer *, int *, int, char *);
extern int fn_8036A91C(Context *, Buffer *, int *, int *, int *);
extern void fn_8036AA70(Context *, Buffer *);
extern int fn_8036ABB0(Context *, Callback, Event *, int, int);
extern void fn_80372BC4(Context *, Node *, int, int, int, int);
extern void fn_803732E0(Context *, char *);
extern char lbl_8048F588[];
extern char lbl_8059F828[3], lbl_8059F848[2];

static inline int flush(Context *ctx, Node *node) {
    Buffer *buffer;
    int err, result;
    if (node->active) return 0;
    while (fn_8035A590(node->queue)) {
        buffer = fn_8035A598(node->queue, 0);
        result = fn_8036A81C(ctx, node->socket, buffer, &err, 0, lbl_8059F828);
        if (err || result) {
            node->status = 0x6a;
            return 0;
        }
        if (buffer->d != buffer->c) break;
        fn_8035A918(node->queue, 0);
    }
    return 0;
}

int fn_8036F5CC(Context *ctx, Node *node) {
    State *state = ctx->state;
    int count, err, msg, type, extra, result;
    Event *event;
    Callback cb;
    Buffer *buffer;
    if (node->active) {
        result = fn_8036A81C(ctx, node->socket, (Buffer *)node->output, &err, 1, lbl_8059F828);
        if (err || result) {
            node->status = 0x6a;
            return 0;
        }
    }
    if (!node->active) {
        result = flush(ctx, node);
        if (result) return result;
        if (node->status == 0x6a) return 0;
    }
    if (fn_8036A6DC(ctx, node->socket, &node->input, &count, &err, lbl_8059F828)) {
        node->status = 0x6a;
        return 0;
    }
    if (count > 0) node->time = fn_8035D258(0) + 300;
    do {
        result = fn_8036A91C(ctx, &node->input, &msg, &type, &extra);
        if (result) return result;
        if (msg) {
            switch (type) {
            case 1:
                cb = state->cb1;
                if (cb.a) {
                    event = fn_8035DFE8(12);
                    if (!event) { fn_803732E0(ctx, lbl_8048F588); return 1; }
                    event->id = node->id;
                    event->data = fn_8035D654(msg);
                    event->time = fn_8035D258(0);
                    result = fn_8036ABB0(ctx, cb, event, 0, 2);
                    if (result) return result;
                }
                break;
            case 5:
                cb = state->cb5;
                if (cb.a) {
                    event = fn_8035DFE8(12);
                    if (!event) { fn_803732E0(ctx, lbl_8048F588); return 1; }
                    event->id = node->id;
                    event->data = fn_8035D654(msg);
                    event->time = fn_8035D258(0);
                    result = fn_8036ABB0(ctx, cb, event, 0, 2);
                    if (result) return result;
                }
                break;
            case 102:
                fn_80369D58(ctx, node->id, 103, lbl_8059F848, 0);
                break;
            case 200: case 201: case 202: case 203: case 204: case 205: case 206: case 207: case 208:
                fn_80372BC4(ctx, node, type, node->input.a, msg, extra);
                break;
            }
            fn_8036AA70(ctx, &node->input);
        }
    } while (msg);
    if (err) node->status = 0x6a;
    return 0;
}