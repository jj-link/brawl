#include <types.h>
#include <string.h>
#pragma force_active on
extern u8 lbl_80529AC8[];
extern u8 lbl_8052C9B8[];
extern u8 lbl_8052CDC0[];
extern u8 *fn_8024FC18(void *, unsigned int);
typedef struct { u8 id; u8 pad; u16 a; u16 b; } Entry;
typedef struct { u16 a, b, count; Entry entries[4]; } Packet;
void fn_80236CB4(void) {
    Packet packet;
    u8 count = 0;
    u8 *base1;
    u8 *base2;
    Entry *entry;
    u32 i;
    memset(&packet, 0, 0x1e);
    base1 = lbl_8052C9B8;
    base2 = lbl_80529AC8;
    for (i = 0; i < 16; i++) {
        u8 *p = base2 + (u8)i * 0x20;
        if (p[0x28] != 0 && p[0x2c] == 3) {
            u8 *channel;
            entry = (Entry *)&packet + count;
            entry[1].id = p[0x26];
            channel = fn_8024FC18(0, *(u16 *)(base1 + entry[1].id * 0x34 + 0x16));
            if (channel != 0) {
                u8 *info = *(u8 **)(channel + 0x10);
                if (info != 0 && info[0] != 0) {
                    entry[1].a = *(u16 *)(info + 0x4c);
                    entry[1].b = *(u16 *)(info + 0x38);
                }
            }
            count++;
        }
    }
    packet.a = *(u16 *)(lbl_8052CDC0 + 4);
    packet.b = *(u16 *)(lbl_8052CDC0 + 2);
    packet.count = count;
    (*(void (**)(int, void *))(lbl_80529AC8 + 0x224))(15, &packet);
}