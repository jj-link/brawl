#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Pair {
    s32 a;
    s32 b;
} Pair;

typedef struct Request {
    s32 kind;
    u8 pad0[8];
    Pair cb;
    u8 pad1[8];
    s32 value;
} Request;

typedef struct State {
    u8 pad0[0x1a0];
    s32 field;
    u8 pad1[0x290];
    s32 status;
} State;

typedef struct Event {
    s32 value;
    s32 field;
    s32 pad;
    s32 extra;
} Event;

extern void *fn_8035DFE8(s32);
extern s32 fn_8036ABB0(void **, Pair *, void *, const Request *, s32);
extern void fn_803732E0(void **, const void *);
extern u8 lbl_8048F518[];

s32 fn_8036E9EC(void **ctx, const Request *req)
{
    Pair cb;
    State *state;
    s32 result;

    cb.a = req->cb.a;
    state = *ctx;
    cb.b = req->cb.b;

    if (cb.a != 0) {
        switch (req->kind) {
        case 0: {
            Event *ev;
            Pair tmp;
            ev = fn_8035DFE8(0x20);
            if (ev == NULL) {
                fn_803732E0(ctx, lbl_8048F518);
                return 1;
            }
            memset(ev, 0, 0x20);
            ev->value = req->value;
            if (state->status == 0x201) {
                ev->field = state->field;
                state->field = 0;
            }
            tmp = cb;
            result = fn_8036ABB0(ctx, &tmp, ev, req, 0);
            if (result != 0) return result;
            break;
        }
        case 1: {
            Event *ev;
            Pair tmp;
            ev = fn_8035DFE8(8);
            if (ev == NULL) {
                fn_803732E0(ctx, lbl_8048F518);
                return 1;
            }
            memset(ev, 0, 8);
            ev->value = req->value;
            tmp = cb;
            result = fn_8036ABB0(ctx, &tmp, ev, req, 0);
            if (result != 0) return result;
            break;
        }
        case 5: {
            Event *ev;
            Pair tmp;
            ev = fn_8035DFE8(8);
            if (ev == NULL) {
                fn_803732E0(ctx, lbl_8048F518);
                return 1;
            }
            memset(ev, 0, 8);
            ev->value = req->value;
            tmp = cb;
            result = fn_8036ABB0(ctx, &tmp, ev, req, 0);
            if (result != 0) return result;
            break;
        }
        case 2: {
            Event *ev;
            Pair tmp;
            ev = fn_8035DFE8(0x204);
            if (ev == NULL) {
                fn_803732E0(ctx, lbl_8048F518);
                return 1;
            }
            memset(ev, 0, 0x204);
            ev->value = req->value;
            tmp = cb;
            result = fn_8036ABB0(ctx, &tmp, ev, req, 0);
            if (result != 0) return result;
            break;
        }
        case 3: {
            Event *ev;
            Pair tmp;
            ev = fn_8035DFE8(0x10);
            if (ev == NULL) {
                fn_803732E0(ctx, lbl_8048F518);
                return 1;
            }
            memset(ev, 0, 0x10);
            ev->value = req->value;
            ev->extra = 0;
            tmp = cb;
            result = fn_8036ABB0(ctx, &tmp, ev, req, 0);
            if (result != 0) return result;
            break;
        }
        case 4: {
            Event *ev;
            Pair tmp;
            ev = fn_8035DFE8(4);
            if (ev == NULL) {
                fn_803732E0(ctx, lbl_8048F518);
                return 1;
            }
            memset(ev, 0, 4);
            ev->value = req->value;
            tmp = cb;
            result = fn_8036ABB0(ctx, &tmp, ev, req, 0);
            if (result != 0) return result;
            break;
        }
        }
    }
    return 0;
}
