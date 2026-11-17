#include <types.h>
#pragma force_active on

typedef struct Channel {
    u8 active;
    u8 flags;
    u8 pad2[2];
    u16 cid1;
    u16 cid2;
    u8 pad8[0x1c];
} Channel;

typedef struct Entry {
    u8 active;
    u8 pad1[9];
    u8 flag;
    u8 padB[5];
    Channel channel;
} Entry;

extern u8 lbl_8052C9B8[0x408];
extern char lbl_80482490[];
extern void fn_802319E4(int, const char *);
extern void fn_802319FC(int, const char *, u32);
extern void fn_80231A14(int, const char *, u32, u16);
extern void fn_8024AA7C(u16);

void fn_80249198(u32 arg0, u16 *arg1)
{
    char *str = lbl_80482490;
    u8 i;
    Channel *channel = 0;

    if (lbl_8052C9B8[0x401] >= 4U) {
        fn_80231A14(0x1E0003, str + 0x274, arg0, *arg1);
    }
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
            fn_802319FC(0x1E0001, str + 0x21C, arg0);
        }
    } else {
        if (*arg1 != 0) {
            Entry *entry = &((Entry *)lbl_8052C9B8)[i];
            if (lbl_8052C9B8[0x401] >= 4U) {
                fn_802319E4(0x1E0003, str + 0x44);
            }
            if (entry->channel.cid1 != 0 || entry->channel.cid2 != 0) {
                entry->channel.active = 5;
                if (entry->channel.cid2 != 0) {
                    fn_8024AA7C(entry->channel.cid2);
                }
                if (entry->channel.cid1 != 0) {
                    fn_8024AA7C(entry->channel.cid1);
                }
            } else {
                entry->channel.active = 0;
            }
            (*(void (**)(u8, int, int, int))(lbl_8052C9B8 + 0x340))(i, 1, *arg1 | 0x400, 0);
            return;
        }
        if (arg0 == channel->cid1) {
            channel->flags |= 4;
        } else {
            channel->flags |= 0x10;
        }
        if ((channel->flags & 0x1E) == 0x1E && channel->active == 3) {
            channel->active = 4;
            ((Entry *)lbl_8052C9B8)[i].flag = 1;
            (*(void (**)(u8, int, int, int))(lbl_8052C9B8 + 0x340))(i, 0, 0, 0);
        }
    }
}
