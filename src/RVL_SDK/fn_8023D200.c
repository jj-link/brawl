#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef void (*Callback)(void *);
typedef void (*Notify)(void *, int);
typedef u8 (*Filter)(u8 *, u8 *);

extern u8 lbl_80529CF8[];
extern u8 fn_8023CD1C(u8 *);
extern void *fn_8023CDF8(u8 *);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern int fn_8022FE78(void);
extern u8 fn_80244964(void);

void fn_8023D200(u8 *data, int mode)
{
    u8 address[6];
    u8 device[3];
    u8 b, a, count;
    u8 *base = lbl_80529CF8;
    u8 i;
    u8 *entry;
    u8 *found;
    u32 j;
    u8 *info;
    u32 update;
    Callback callback;
    u8 extra;
    u8 signal;
    u16 value;
    u32 n;

    update = 1;
    extra = 0;
    callback = *(Callback *)(lbl_80529CF8 + 0x16B4);
    signal = 0;

    if (lbl_80529CF8[0x1848] != 0) {
        count = data[0];
        data++;
        for (i = 0; i < count; i++) {
            address[5] = data[0];
            address[4] = data[1];
            address[3] = data[2];
            address[2] = data[3];
            address[1] = data[4];
            address[0] = data[5];
            a = data[6];
            b = data[7];
            data += 8;

            if (mode == 0) {
                extra = *data++;
            }

            device[2] = data[0];
            device[1] = data[1];
            device[0] = data[2];
            value = data[3] + (data[4] << 8);
            data += 5;

            if (mode != 0) {
                signal = *data++;
            }

            if (fn_8023CD1C(address) == 0 &&
                (*(Filter *)(lbl_80529CF8 + 0x184C) == 0 ||
                 (*(Filter *)(lbl_80529CF8 + 0x184C))(address, device) != 0)) {
                entry = base + 0x16E4;
                j = 0;

                for (;;) {
                    if (entry[0x1A] != 0 &&
                        fn_803F6150(entry + 0xA, address, 6) == 0) {
                        found = entry;
                        break;
                    }
                    j++;
                    entry += 0x1C;
                    if (j >= 12) {
                        found = 0;
                        break;
                    }
                }

                entry = found;
                if (entry == 0) {
                    entry = fn_8023CDF8(address);
                    update = 1;
                } else if (*(u32 *)(entry + 4) ==
                           *(u32 *)(lbl_80529CF8 + 0x16C0)) {
                    update = 0;
                }

                if (update == 1) {
                    info = entry + 8;
                    info[0xB] = a;
                    info[0xC] = b;
                    info[0xD] = extra;
                    info[8] = device[0];
                    info[9] = device[1];
                    info[0xA] = device[2];
                    *(u16 *)info = value | 0x8000;

                    if (mode != 0) {
                        info[0xE] = signal;
                    } else {
                        info[0xE] = 0x7F;
                    }

                    *(int *)entry = fn_8022FE78();
                    *(u32 *)(entry + 4) = *(u32 *)(lbl_80529CF8 + 0x16C0);
                    n = lbl_80529CF8[0x183F] + 1;
                    lbl_80529CF8[0x183F] = n;

                    if (!(lbl_80529CF8[0x1848] & 4) &&
                        lbl_80529CF8[0x1836] != 0 &&
                        (u8)n == lbl_80529CF8[0x1836]) {
                        fn_80244964();
                    }

                    entry[0x18] = 0;
                    if (callback != 0) {
                        callback(info);
                    }
                    if (*(Notify *)(lbl_80529CF8 + 0x16BC) != 0) {
                        (*(Notify *)(lbl_80529CF8 + 0x16BC))(entry + 8, 1);
                    }
                }
            }
        }
    }
}
