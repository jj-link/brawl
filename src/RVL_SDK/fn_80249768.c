#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Channel {
    u8 active;
    u8 pad1[3];
    u16 cid1;
    u16 cid2;
    u8 pad8[2];
    u16 handle;
    u8 padC[0x18];
} Channel;

typedef struct Entry {
    u8 active;
    u8 pad1[9];
    u8 flag;
    u8 padB[5];
    Channel channel;
} Entry;

extern u8 lbl_8052C9B8[0x408];
extern char lbl_80482780[];
extern char lbl_804827B0[];
extern void fn_802319FC(int, const char *, u32);

void fn_80249768(u32 arg0)
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
            fn_802319FC(0x1E0001, lbl_80482780, arg0);
        }
    } else {
        if (lbl_8052C9B8[0x401] >= 4U) {
            fn_802319FC(0x1E0003, lbl_804827B0, arg0);
        }
        if (arg0 == channel->cid1) {
            channel->cid1 = 0;
        } else {
            channel->cid2 = 0;
        }
        if (channel->cid1 == 0 && channel->cid2 == 0) {
            ((Entry *)lbl_8052C9B8)[i].flag = 0;
            channel->active = 0;
            (*(void (**)(u8, int, u16, int))(lbl_8052C9B8 + 0x340))(i, 1, channel->handle, 0);
        }
    }
}
