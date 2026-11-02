#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    int command;
    int result;
    int fd;
    int pad[5];
    void *callback;
    void *argument;
    int relaunch;
    int queue[5];
} Request;

typedef struct IpcQueue {
    u32 acked;
    u32 sent;
    u32 rd;
    u32 wr;
    Request *q[16];
} IpcQueue;

extern int lbl_8059ECCC;
extern int lbl_8059ECC8;
extern int lbl_805A0BF0;
extern Request *lbl_805A0BF4;
extern Request *lbl_805A0BF8;
extern Request lbl_804F65A0;
extern IpcQueue lbl_804F6540;

extern int OSDisableInterrupts(void);
extern int OSRestoreInterrupts(int);
extern void DCFlushRange(void *, u32);
extern void *memcpy(void *, const void *, unsigned long);
extern void fn_801E0704(void *);
extern void fn_801E1790(void *);
extern u32 fn_80211AC0(int);
extern void fn_80211AD0(int, u32);
extern int fn_80212E70(Request *, int, int, int, void *);
extern Request *fn_802137A4(int, int, int);
extern void fn_802137A8(int, void *);
extern void fn_80213A4C(Request *, int);

static inline int create_request(Request **out, int fd)
{
    int result = 0;
    Request *request;

    if (out == 0) {
        result = -4;
    } else {
        request = fn_802137A4(lbl_8059ECCC, 0x40, 0x20);
        *out = request;
        if (request == 0) {
            result = -22;
        } else {
            (*out)->callback = 0;
            (*out)->argument = 0;
            (*out)->relaunch = 0;
            request->command = 7;
            request->fd = fd;
        }
    }
    return result;
}

static inline int queue_full(void)
{
    u32 n;
    if (lbl_804F6540.sent < lbl_804F6540.acked) {
        n = (u32)((char *)0 - lbl_804F6540.acked);
        n += lbl_804F6540.sent;
        return n;
    }
    return lbl_804F6540.sent - lbl_804F6540.acked >= 16;
}

static inline int queue_empty(void)
{
    u32 n;
    if (lbl_804F6540.sent < lbl_804F6540.acked) {
        n = (u32)((char *)0 - lbl_804F6540.acked);
        n += lbl_804F6540.sent;
        return n;
    }
    return lbl_804F6540.sent - lbl_804F6540.acked == 0;
}

static inline void send_next(void)
{
    Request *rpc;
    if (lbl_8059ECC8 > 0 && !queue_empty()) {
        rpc = lbl_804F6540.q[lbl_804F6540.rd];
        if (rpc != 0) {
            if (rpc->relaunch) {
                lbl_8059ECC8--;
            }
            fn_80211AD0(0, (u32)rpc + 0x80000000);
            lbl_804F6540.rd = (lbl_804F6540.rd + 1) & 15;
            lbl_804F6540.acked++;
            lbl_8059ECC8--;
            fn_80211AD0(1, (fn_80211AC0(1) & 0x30) | 1);
        }
    }
}

int fn_8021316C(int fd, int cmd, int nin, int nout, void *vec)
{
    int ret;
    Request *rpc;

    {
        int e = OSDisableInterrupts();
        if (lbl_805A0BF0 != 0) {
            OSRestoreInterrupts(e);
            ret = -10;
            goto finish;
        }
        lbl_805A0BF0 = 1;
        OSRestoreInterrupts(e);
    }

    ret = create_request(&rpc, fd);
    if (ret == 0) {
        lbl_805A0BF8 = rpc;
        rpc->relaunch = 1;
        ret = fn_80212E70(rpc, cmd, nin, nout, vec);
        if (ret == 0) {
            int enabled;
            Request *save;
            Request *r;
            memcpy(&lbl_804F65A0, rpc, 0x40);
            save = &lbl_804F65A0;
            r = rpc;
            lbl_805A0BF4 = save;
            fn_801E0704(&save->queue);
            DCFlushRange(r, 0x20);
            enabled = OSDisableInterrupts();
            ret = 0;
            if (queue_full()) {
                ret = -8;
            } else {
                lbl_804F6540.q[lbl_804F6540.wr] = r;
                lbl_804F6540.wr = (lbl_804F6540.wr + 1) & 15;
                lbl_804F6540.sent++;
                fn_80213A4C(r, r->fd);
            }
            if (ret != 0) {
                OSRestoreInterrupts(enabled);
            } else {
                send_next();
                fn_801E1790(&lbl_805A0BF4->queue);
                OSRestoreInterrupts(enabled);
                ret = lbl_805A0BF4->result;
            }
        }
    }

    lbl_805A0BF0 = 0;
    lbl_805A0BF8 = 0;
    if (rpc != 0 && ret != 0) {
        fn_802137A8(lbl_8059ECCC, rpc);
    }
finish:
    return ret;
}
