#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Channel {
    u8 active;
    u8 flags;
    u8 pad2[2];
    u16 cid1;
    u16 cid2;
    u16 mtu;
    u8 padA[0x1a];
} Channel;
typedef struct Entry {
    u8 active;
    u8 pad1[9];
    u8 flag;
    u8 padB[5];
    Channel channel;
} Entry;
typedef struct Config {
    u16 field0;
    u8 field2;
    u8 pad3;
    u16 field4;
    u8 pad6[0x1a];
    u8 field20;
} Config;
extern u8 lbl_8052C9B8[0x408];
extern char lbl_804826AC[];
extern char lbl_804826D8[];
extern void fn_802319FC(int, const char *, u32);
extern void fn_8024A9AC(u32, Config *);
void fn_80248EF0(u32 arg0, Config *arg1)
{
    u8 i;
    Channel *channel = 0;
    for (i = 0; i < 16; i++) {
        Entry *entry = &((Entry *)lbl_8052C9B8)[i];
        if (entry->active && entry->channel.active &&
            (arg0 == entry->channel.cid1 || arg0 == entry->channel.cid2)) {
            break;
        }
    }
    if (i != 16) {
        channel = &((Entry *)lbl_8052C9B8)[i].channel;
    }
    if (channel == 0) {
        if (lbl_8052C9B8[0x401] >= 2U) {
            fn_802319FC(0x1E0001, lbl_804826AC, arg0);
        }
    } else {
        if (lbl_8052C9B8[0x401] >= 4U) {
            fn_802319FC(0x1E0003, lbl_804826D8, arg0);
        }
        if (arg1->field2 == 0 || arg1->field4 > 0x280U) {
            channel->mtu = 0x280;
        } else {
            channel->mtu = arg1->field4;
        }
        arg1->field20 = 0;
        arg1->field2 = 0;
        arg1->field0 = 0;
        fn_8024A9AC(arg0, arg1);
        if (arg0 == channel->cid1) {
            channel->flags |= 2;
        } else {
            channel->flags |= 8;
        }
        if ((channel->flags & 0x1e) == 0x1e && channel->active == 3) {
            channel->active = 4;
            ((Entry *)lbl_8052C9B8)[i].flag = 1;
            (*(void (**)(u8, int, int, int))(lbl_8052C9B8 + 0x340))(i, 0, 0, 0);
        }
    }
}