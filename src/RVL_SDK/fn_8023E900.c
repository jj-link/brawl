#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;

extern char lbl_80529CF8[];
extern char lbl_804812F4[];

extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_8023E598(u32, int, void *, int);
extern void fn_802319E4(u32, const char *);
extern void *memcpy(void *, void *, unsigned long);

void fn_8023E900(u8 *arg0, u8 *arg1, s8 arg2)
{
    struct CallbackData {
        u16 index;
        u8 address[6];
        u8 data[3];
        u8 value;
    } cb;
    u16 i = 0;
    char *source = (char *)arg1;
    char *entry = lbl_80529CF8 + 0x1854;

    for (; i < 3; i++) {
        if (((*(u16 *)(entry + 8) == 1 && *(u8 *)(entry + 0xD) != 0) ||
             *(u16 *)(entry + 8) == 3) &&
            fn_803F6150(entry + 0x28, arg0, 6) == 0) {
            *(u8 *)(entry + 0xD) = 1;
            *(u8 *)(entry + 0x2E) = arg2;
            memcpy(entry + 0x28, arg0, 6);

            if (*(void **)(entry + 0x10) == 0) {
                fn_8023E598(i, 0, arg0, 0);
                return;
            }

            memcpy(cb.address, arg0, 6);
            memcpy(cb.data, source, 3);
            cb.value = arg2;
            *(u16 *)(entry + 8) = 2;
            cb.index = i;
            ((void (*)(u32, void *))*(void **)(entry + 0x10))(2, &cb);
            return;
        }

        entry += 0x34;
    }

    if (*(void **)(lbl_80529CF8 + 0x1850) != 0) {
        u16 count = 0;
        int j = 0;

        entry = lbl_80529CF8 + 0x1854;
        for (j = 0; j < 3; j++) {
            if (*(u16 *)(entry + 8) == 0) {
                *(u8 *)(entry + 0xC) = 0;
                *(u16 *)(entry + 8) = 1;
                *(u8 *)(entry + 0x2E) = arg2;
                memcpy(entry + 0x28, arg0, 6);
                *(u8 *)(entry + 0xD) = 1;
                break;
            } else {
                count++;
            }
            entry += 0x34;
        }

        if (count < 3) {
            ((void (*)(u32, char *))*(void **)(lbl_80529CF8 + 0x1850))(
                count, lbl_80529CF8);
            return;
        }
    }

    if (*(u8 *)(lbl_80529CF8 + 0x27C0) >= 2)
        fn_802319E4(0xD0001, lbl_804812F4);

    fn_8023E598(3, 0xD, arg0, 0);
}
