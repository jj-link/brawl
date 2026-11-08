#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Packet {
    u16 event;
    u16 len;
    u16 offset;
    u16 layer;
    u8 data[1];
} Packet;

typedef struct Entry {
    u8 pad[0x11];
    u8 flags;
    u8 pad2[2];
    u16 a;
    u16 b;
    u16 mtu;
    u8 rest[0x1a];
} Entry;

extern Entry lbl_8052C9B8[];
extern Packet *fn_8022EFF8(u32);
extern void fn_8022F0E0(void *);
extern u8 fn_8024ABC4(u16, Packet *);

int fn_80249F40(int index, int type, int flags, int value, int extra, Packet *input)
{
    u8 bits, low, high;
    Entry *entry = &lbl_8052C9B8[index];
    Packet *out;
    u16 count, remaining;
    u16 channel;
    int pool;
    int suffix = 0;
    int again = 0;
    int copy;
    u8 *p;

    if (entry->flags & 0x20) {
        if (input != 0)
            fn_8022F0E0(input);
        return 8;
    }
    switch (type) {
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        channel = entry->a;
        pool = 2;
        break;
    case 10:
        channel = entry->b;
        pool = 2;
        break;
    default:
        return 5;
    }
    if ((u32)type == 9)
        suffix = 1;
    else if ((u32)type == 4 && (flags & 8))
        suffix = 2;
    bits = flags & 15;
    low = value;
    high = value >> 8;
    do {
        if (input == 0 || again != 0) {
            out = fn_8022EFF8(pool);
            if (out == 0)
                return 3;
            out->offset = 9;
            copy = 0;
            remaining = 0;
            count = 0;
            again = 0;
        } else {
            remaining = input->len;
            if (remaining > entry->mtu - 1) {
                out = fn_8022EFF8(pool);
                if (out == 0)
                    return 3;
                out->offset = 9;
                copy = 1;
                remaining = input->len;
                count = entry->mtu - 1;
            } else {
                out = input;
                count = remaining;
                copy = 0;
                input->offset--;
            }
        }
        p = (u8 *)out + out->offset + 8;
        *p++ = ((type & 0xff) << 4) | bits;
        if ((u32)type == 4 && extra != 0) {
            *p = extra;
            count = 1;
            remaining = 1;
        }
        if (copy) {
            memcpy(p, (u8 *)input + input->offset + 8, count);
            input->offset += count;
            input->len -= count;
        } else if ((u32)suffix == 1) {
            p[count] = low;
        } else if ((u32)suffix == 2) {
            p[count] = low;
            p[count + 1] = high;
        }
        remaining -= count;
        out->len = count + suffix + 1;
        if ((entry->flags & 0x20) || !fn_8024ABC4(channel, out))
            return 8;
        if (remaining != 0) {
            type = 11;
        } else if (count == entry->mtu - 1) {
            type = 11;
            again = 1;
        }
    } while (remaining != 0 || again != 0);
    return 0;
}