#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad0[4];
    int field4;
    int field8;
    char padC[4];
    int field10;
    char pad14[4];
    int field18;
    char pad1C;
    u8 state;
    u8 previous;
    char pad1F[3];
    u16 type;
    char pad24[0x24];
} Entry;

typedef struct {
    u32 size;
    u16 type;
    char magic[2];
} Header;

extern Entry *lbl_805A0FB0;
extern char lbl_8059F1B0[3];
extern char lbl_8048D1B0[];
extern char lbl_8048D1D0[];

extern void fn_8034F028(void *, const void *, u32);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_80335638(int, const char *, ...);

void fn_8034ED40(short aid, const void *data, u32 length)
{
    Header packet;
    Header head;
    Entry *entry = &lbl_805A0FB0[aid];
    u16 type;

    entry->previous = entry->state;
    fn_8034F028(&head, data, 8);
    if (fn_803F6150(head.magic, lbl_8059F1B0, 2) == 0) {
        type = (head.type >> 8) | (head.type << 8);
    } else {
        type = 0;
    }

    switch (type) {
    case 1:
        if (length != 8) {
            fn_80335638(0x10000, lbl_8048D1B0, aid);
            return;
        }
        fn_8034F028(&packet, data, 8);
        packet.size = ((((packet.size >> 8) & 0xff) |
                        ((packet.size >> 8) & 0xff0000)) |
                       (((packet.size << 8) & 0xff000000) |
                        ((packet.size << 8) & 0xff00)));
        packet.size = (packet.size >> 16) | (packet.size << 16);
        {
            u16 packet_type = packet.type;
            packet.type = (packet_type << 8) | (packet_type >> 8);
        }
        entry->field18 = packet.size;
        entry->field10 = 0;
        if (entry->field4 && entry->field8 >= entry->field18) {
            entry->state = 2;
        } else {
            entry->state = 4;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        fn_80335638(0x10000, lbl_8048D1D0, type);
        entry->state = 3;
        break;
    default:
        fn_80335638(0x10000, lbl_8048D1B0, aid);
        break;
    }
    entry->type = type;
}
