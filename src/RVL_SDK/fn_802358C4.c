#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 padding[0x18];
    u8 address[6];
    u8 active;
    u8 unused;
} Entry;

typedef struct {
    u8 padding[0x98];
    Entry entries[3];
} Global;

extern u8 lbl_80529994[];
extern void *fn_8022EE58(u16);
extern void fn_80232034(u8 *, const u8 *);
extern void fn_802324E0(void *);

void fn_802358C4(void *arg0)
{
    u8 *packet;
    u32 index;
    u8 *base = lbl_80529994;

    index = 0;
    if (base[0xB6] != 0 && base + 0x98 == arg0) {
        base[0xB6] = 0;
    } else {
        index = 1;
        if (base[0xD6] != 0 && base + 0xB8 == arg0) {
            base[0xD6] = 0;
        } else {
            index = 2;
            if (base[0xF6] != 0 && base + 0xD8 == arg0) {
                base[0xF6] = 0;
            } else {
                index = 3;
            }
        }
    }

    if (index != 3) {
        packet = fn_8022EE58(0xE);
        if (packet != 0) {
            *(u16 *)packet = 0x10A;
            fn_80232034(
                packet + 8,
                ((Global *)lbl_80529994)->entries[(u8)index].address);
            fn_802324E0(packet);
        }
    }
}
