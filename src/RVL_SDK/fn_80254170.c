#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern void fn_80250E18(s32, u8, u8 *);
extern void fn_80250F90(void *, u8, u8 *);
extern void fn_802514BC(s32, u8, u8);
extern void *fn_80251AD0(s32, u16);
extern void fn_802550F0(s32, u8, s32, u8 *);
extern void fn_8025648C(void *);

void fn_80254170(s32 arg0, s32 arg1, u8 *arg2) {
    u8 buf[5];
    u8 *entry;
    u8 r27;
    u8 var;
    u8 s;
    u8 *tmp;

    r27 = arg2[9];
    entry = fn_80251AD0(arg0, arg2[0]);
    if (entry != 0) {
        buf[0] = 0;
        if (r27 & 4) {
            buf[0] |= 1;
        }
        if (r27 & 8) {
            buf[0] |= 2;
        }
        if (r27 & 0x40) {
            buf[0] |= 4;
        }
        if (r27 & 0x80) {
            buf[0] |= 8;
        }
        buf[4] = (r27 >> 1) & 1;
        if (arg2[10] != 0) {
            var = arg2[11];
        } else {
            var = 0;
        }
        buf[1] = var;
        buf[2] = 0;
        buf[3] = 1;
        if (arg1 != 0) {
            fn_802550F0(arg0, arg2[0], 0, buf);
            tmp = *(u8 **)(entry + 0x6c);
            if (tmp[0x72] != 2) {
                s = buf[4];
                entry[0x63] = s;
                if (s != entry[0x24]) {
                    fn_802514BC(arg0, arg2[0], s == 0);
                }
            }
            fn_80250E18(arg0, arg2[0], buf);
            return;
        }
        if (entry[0x69] & 8) {
            entry[0x69] = entry[0x69] & ~8;
            fn_8025648C(entry);
            fn_80250F90(*(void **)(entry + 0x6c), entry[0xd], buf);
        }
    }
}
