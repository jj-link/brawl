#include <types.h>
#include <string.h>
#pragma force_active on

extern s32 fn_80213090(s32, s32, s32, s32, void *);
extern s32 fn_803A66E8(void);
extern void *fn_803A6740(s32, s32);
extern void fn_803A6828(s32, void *, s32);
extern s32 fn_803A685C(s32, s32 *);
extern s32 fn_803A6944(s32, s32);

void SORecvFrom(s32 socket, s32 address, s32 buffer, s32 length,
                s32 flags, s32 from)
{
    s32 handle, error;

    if (length > 0x8000) {
        length = 0x8000;
    }

    if (fn_803A685C(socket, &handle) == 0) {
        s32 direct, alignedLength, fromLength;
        void *data, *request;

        if (from && (*(u8 *)from > 8 || *(u8 *)from < 8)) {
            error = -28;
            goto done;
        }

        if (length < 0 || (length > 0 && buffer == 0)) {
            error = -28;
            goto done;
        }

        direct = 1;
        if (length != 0) {
            int aligned;

            data = 0;
            aligned = 0;
            if (((u32)buffer & 31) == 0 && length % 32 == 0) {
                aligned = 1;
            }

            if (aligned) {
                alignedLength = 1;

                if (fn_803A66E8()) {
                    int inrange = 0;
                    u32 p = (u32)buffer & 0x1fffffff;

                    if (p >= 0x10000000 && p < 0x18000000) {
                        inrange = 1;
                    }
                    if (!inrange) {
                        alignedLength = 0;
                    }
                }
                if (alignedLength) {
                    data = (void *)1;
                }
            }
            if (!data) {
                direct = 0;
            }
        }

        if (from == 0) {
            fromLength = 0;
        } else {
            fromLength = *(u8 *)from;
        }
        data = (void *)((fromLength + 0x5f) & ~31);
        request = fn_803A6740(12, (s32)data);

        alignedLength = (s32)(!direct
            ? fn_803A6740(13, (length + 31) & ~31)
            : (void *)buffer);

        if (!request || !alignedLength) {
            error = -49;
        } else {
            u8 *params = (u8 *)request + 0x20;
            u8 *fromCopy = params + 0x20;

            *(s32 *)params = address;
            *(s32 *)(params + 4) = flags;
            *(void **)request = params;
            *(s32 *)((u8 *)request + 4) = 8;
            *(void **)((u8 *)request + 8) = (void *)alignedLength;
            *(s32 *)((u8 *)request + 12) = length;

            if (!from) {
                *(void **)((u8 *)request + 16) = 0;
                *(s32 *)((u8 *)request + 20) = 0;
                error = fn_80213090(handle, 12, 1, 2, request);
            } else {
                memcpy(fromCopy, (void *)from, *(u8 *)from);
                *(u8 **)((u8 *)request + 16) = fromCopy;
                *(s32 *)((u8 *)request + 20) = *(u8 *)from;
                error = fn_80213090(handle, 12, 1, 2, request);

                if (error >= 0) {
                    memcpy((void *)from, fromCopy,
                           *(u8 *)from > fromCopy[0]
                               ? fromCopy[0] : *(u8 *)from);
                }
            }

            if (error >= 0 && !direct) {
                memcpy((void *)buffer, (void *)alignedLength, length);
            }
        }

        if (!direct) {
            fn_803A6828(13, (void *)alignedLength, (length + 31) & ~31);
        }
        fn_803A6828(12, request, (s32)data);

    done:
        fn_803A6944(socket, error);
    }
}
