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
extern IpcQueue lbl_804F6540;

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void DCFlushRange(void *, u32);
extern void fn_801E0704(void *);
extern void fn_801E1790(void *);
extern u32 fn_80211AC0(int);
extern void fn_80211AD0(int, u32);
extern void fn_802137A8(int, void *);
extern void fn_80213A4C(Request *, int);

int fn_80212050(Request *arg0, int arg1)
{
    int var_r31;
    int enabled;
    u32 n;

    if (arg0 == 0) {
        var_r31 = -4;
    } else {
        if (arg1 == 0) {
            fn_801E0704(&arg0->queue);
        }
        DCFlushRange(arg0, 0x20);
        enabled = OSDisableInterrupts();
        var_r31 = 0;
        if (lbl_804F6540.sent < lbl_804F6540.acked) {
            n = lbl_804F6540.sent - lbl_804F6540.acked;
        } else {
            n = (lbl_804F6540.sent - lbl_804F6540.acked) >= 16;
        }
        if (n != 0) {
            var_r31 = -8;
        } else {
            lbl_804F6540.q[lbl_804F6540.wr] = arg0;
            lbl_804F6540.wr = (lbl_804F6540.wr + 1) & 15;
            lbl_804F6540.sent++;
            fn_80213A4C(arg0, arg0->fd);
        }
        if (var_r31 != 0) {
            OSRestoreInterrupts(enabled);
            if (arg1 != 0) {
                fn_802137A8(lbl_8059ECCC, arg0);
            }
        } else {
            if (lbl_8059ECC8 > 0) {
                if (lbl_804F6540.sent < lbl_804F6540.acked) {
                    n = lbl_804F6540.sent - lbl_804F6540.acked;
                } else {
                    n = (lbl_804F6540.sent - lbl_804F6540.acked) == 0;
                }
                if (n == 0) {
                    Request *rpc = lbl_804F6540.q[lbl_804F6540.rd];
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
            if (arg1 == 0) {
                fn_801E1790(&arg0->queue);
            }
            OSRestoreInterrupts(enabled);
            if (arg1 == 0) {
                var_r31 = arg0->result;
            }
        }
    }
    if (arg0 != 0 && arg1 == 0) {
        fn_802137A8(lbl_8059ECCC, arg0);
    }
    return var_r31;
}
