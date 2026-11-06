#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_80529994[];
extern int fn_80232068(void *, void *);
extern int fn_8023251C(void *);
extern void fn_802354CC(void *, int);

void fn_802359BC(u8 *self)
{
    u8 *entry;
    u32 offset;
    u32 offset2;
    u8 i;
    int flags;

    for (i = 0; i < 3; ++i) {
        offset = (u8)i * 0x20;
        entry = lbl_80529994 + offset;
        if (entry[0xB6] != 0 &&
            fn_80232068(entry + 0xB0, self + 8) == 0) {
            fn_8023251C(lbl_80529994 + 0x98 + offset);
            entry[0xB6] = 0;
            break;
        }
    }

    switch (self[0xE]) {
    default:
        return;
    case 0:
        break;
    }

    if (self[0x12] != 0) {
        for (i = 0; i < lbl_80529994[0x4D]; ++i) {
            offset2 = i * 0xB;
            if (fn_80232068(lbl_80529994 + offset2, self + 8) == 0) {
                flags = (lbl_80529994 + 9)[offset2] & 3;
                if (flags != 0) {
                    (lbl_80529994 + 0xA)[offset2] |= flags;
                    fn_802354CC(self + 8, 0);
                }
                break;
            }
        }
    } else {
        fn_802354CC(self + 8, 0);
    }
}
