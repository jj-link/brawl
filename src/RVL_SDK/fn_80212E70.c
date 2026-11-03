typedef int bool;
typedef struct OSModuleHeader OSModuleHeader;
#include <revolution/IPC.h>
#include <revolution/OS.h>
#pragma force_active on
s32 fn_80212E70(IPCRequestEx* req, s32 type, s32 inCount, s32 outCount, IPCIOVector* vectors) {
    int i;
    s32 ret = IPC_RESULT_OK;
    if (req == NULL) {
        ret = IPC_RESULT_INVALID_INTERNAL;
    } else {
        req->base.ioctlv.type = type;
        req->base.ioctlv.inCount = inCount;
        req->base.ioctlv.outCount = outCount;
        req->base.ioctlv.vectors = vectors;
        for (i = 0; i < req->base.ioctlv.outCount; i++) {
            DCFlushRange(req->base.ioctlv.vectors[inCount + i].base,
                         req->base.ioctlv.vectors[inCount + i].length);
            req->base.ioctlv.vectors[inCount + i].base =
                (req->base.ioctlv.vectors[inCount + i].base != NULL)
                    ? OSCachedToPhysical(req->base.ioctlv.vectors[inCount + i].base)
                    : NULL;
        }
        for (i = 0; i < req->base.ioctlv.inCount; i++) {
            DCFlushRange(req->base.ioctlv.vectors[i].base,
                         req->base.ioctlv.vectors[i].length);
            req->base.ioctlv.vectors[i].base =
                (req->base.ioctlv.vectors[i].base != NULL)
                    ? OSCachedToPhysical(req->base.ioctlv.vectors[i].base)
                    : NULL;
        }
        DCFlushRange(req->base.ioctlv.vectors,
                     (req->base.ioctlv.inCount + req->base.ioctlv.outCount) * sizeof(IPCIOVector));
        req->base.ioctlv.vectors = (vectors != NULL) ? OSCachedToPhysical(vectors) : NULL;
    }
    return ret;
}