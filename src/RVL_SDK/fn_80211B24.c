#pragma force_active on
typedef int bool;
typedef struct OSModuleHeader OSModuleHeader;
#include <revolution/IPC/ipcclt.h>
#include <revolution/OS/OSAddress.h>

extern u32 fn_80211AC0(int);
extern void fn_80211AD0(int, u32);
extern void fn_801D76BC(void *, u32);
extern void fn_801D81F4(OSContext *);
extern void fn_801D7FCC(OSContext *);
extern void fn_801E187C(OSThreadQueue *);
extern void fn_802137A8(int, void *);
extern void fn_80213ADC(IPCRequestEx *, int);

extern int lbl_8059ECC8;
extern int lbl_8059ECCC;
extern int lbl_805A0BF0;
extern IPCRequestEx *lbl_805A0BF8;

void fn_80211B24(int unused, OSContext *ctx)
{
    IPCRequestEx *req;
    IPCIoctlvArgs *args;
    u32 reg;
    OSContext temp;
    int i;

    reg = fn_80211AC0(2);
    if (reg != 0) {
        req = (IPCRequestEx *)OSPhysicalToCached(reg);
        fn_80211AD0(1, (fn_80211AC0(1) & 0x30) | 4);
        *(u32 *)0xCD000030 = 0x40000000;
        fn_801D76BC(&req->base, sizeof(IPCRequest));
        switch (req->base.fd) {
        case IPC_REQ_READ:
            req->base.rw.data = req->base.rw.data != 0
                ? OSPhysicalToCached((u32)req->base.rw.data) : 0;
            if (req->base.ret > 0) {
                fn_801D76BC(req->base.rw.data, req->base.ret);
            }
            break;
        case IPC_REQ_IOCTL:
            req->base.ioctl.out = req->base.ioctl.out != 0
                ? OSPhysicalToCached((u32)req->base.ioctl.out) : 0;
            fn_801D76BC(req->base.ioctl.in, req->base.ioctl.inSize);
            fn_801D76BC(req->base.ioctl.out, req->base.ioctl.outSize);
            break;
        case IPC_REQ_IOCTLV:
            args = &req->base.ioctlv;
            req->base.ioctlv.vectors = req->base.ioctlv.vectors != 0
                ? OSPhysicalToCached((u32)req->base.ioctlv.vectors) : 0;
            fn_801D76BC(req->base.ioctlv.vectors,
                (args->inCount + args->outCount) * sizeof(IPCIOVector));
            for (i = 0; i < args->inCount + args->outCount; i++) {
                i++;
                i--;
                req->base.ioctlv.vectors[i].base = args->vectors[i].base != 0
                    ? OSPhysicalToCached((u32)args->vectors[i].base) : 0;
                fn_801D76BC(args->vectors[i].base,
                    req->base.ioctlv.vectors[i].length);
            }
            if (lbl_805A0BF0 && lbl_805A0BF8 == req) {
                lbl_805A0BF0 = 0;
                if (lbl_8059ECC8 < 1) {
                    lbl_8059ECC8++;
                }
            }
            break;
        }
        if (req->callback != 0) {
            fn_801D81F4(&temp);
            fn_801D7FCC(&temp);
            req->callback(req->base.ret, req->callbackArg);
            fn_801D81F4(&temp);
            fn_801D7FCC(ctx);
            fn_802137A8(lbl_8059ECCC, req);
        } else {
            fn_801E187C(&req->queue);
        }
        fn_80211AD0(1, (fn_80211AC0(1) & 0x30) | 8);
        fn_80213ADC(req, req->base.fd);
    }
}
