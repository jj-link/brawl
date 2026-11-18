#include <types.h>
#pragma force_active on

extern u8 *fn_8025B480(u8 *, u16, void *);
extern void fn_8025B344(void *, int, u16, u8 *);
extern void *fn_80257724(void *, void *);
extern void *fn_8022EFF8(u32);
extern void fn_802319E4(u32, const char *);
extern int fn_8024ABC4(u16, void *);
extern u8 lbl_8052D9C0[];
extern char lbl_80485164[];

#define U16_AT(base, offset) (*(u16 *)((u8 *)(base) + (offset)))
#define READ16(value, src) do { (value) = ((src)[0] << 8) + (src)[1]; (src) += 2; } while (0)
#define WRITE8(dst, value) do { *(dst)++ = (u8)(value); } while (0)
#define WRITE16(dst, value) do { *(dst)++ = (u8)((value) >> 8); *(dst)++ = (u8)(value); } while (0)
#define WRITE32(dst, value) do { *(dst)++ = (u8)((value) >> 24); *(dst)++ = (u8)((value) >> 16); *(dst)++ = (u8)((value) >> 8); *(dst)++ = (u8)(value); } while (0)

typedef struct {
    u16 count;
    u16 data[0x91];
} UuidSequence;

void fn_8025A328(void *connection, u16 transaction, u16 requestLength, u8 *request, u8 *requestEnd)
{
    u16 maxReplies, current, remaining, continuation;
    UuidSequence uuids;
    u8 *response, *start, *lengthField;
    u16 length, total, index;
    u32 handles[20];
    u32 *record = 0;
    u8 *packet;
    u8 more = 0;

    request = fn_8025B480(request, requestLength, &uuids);
    if (!request || !uuids.count) {
        fn_8025B344(connection, transaction, 3, 0);
        return;
    }
    READ16(maxReplies, request);
    if (maxReplies > 20) {
        maxReplies = 20;
    }
    for (total = 0; total < maxReplies;) {
        record = fn_80257724(record, &uuids);
        if (record) {
            handles[total++] = *record;
        } else {
            break;
        }
    }
    if (*request) {
        if (*request++ != 2) {
            fn_8025B344(connection, transaction, 5, 0);
            return;
        }
        READ16(continuation, request);
        if (continuation != U16_AT(connection, 0x476)) {
            fn_8025B344(connection, transaction, 5, 0);
            return;
        }
        remaining = total - continuation;
    } else {
        remaining = total;
        continuation = 0;
    }
    current = (U16_AT(connection, 0x20) - 12) / 4;
    if (remaining <= current) {
        current = remaining;
    } else {
        U16_AT(connection, 0x476) += current;
        more = 1;
    }
    packet = fn_8022EFF8(2);
    if (!packet) {
        if (lbl_8052D9C0[0x4630] >= 1U) {
            fn_802319E4(0xA0000, lbl_80485164);
        }
        return;
    }
    U16_AT(packet, 4) = 9;
    response = start = packet + 0x11;
    WRITE8(response, 3);
    WRITE16(response, transaction);
    lengthField = response;
    response += 2;
    WRITE16(response, total);
    WRITE16(response, current);
    for (index = continuation; index < continuation + current; index++) {
        WRITE32(response, handles[index]);
    }
    if (more) {
        WRITE8(response, 2);
        WRITE16(response, U16_AT(connection, 0x476));
    } else {
        WRITE8(response, 0);
    }
    length = response - lengthField - 2;
    WRITE16(lengthField, length);
    U16_AT(packet, 2) = response - start;
    fn_8024ABC4(U16_AT(connection, 0x22), packet);
}
