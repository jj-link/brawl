#pragma force_active on
extern char lbl_80529CF8[];
extern unsigned char fn_8023A5A4(void);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_80231FB0(void *, int, int);
extern unsigned char fn_80245390(void *, int, int, int);
extern void *memcpy(void *, const void *, unsigned long);

int fn_8023D57C(void *arg0, unsigned char *arg1, unsigned int arg2, int arg3, int arg4) {
    char *base = lbl_80529CF8;
    int var_r30 = 1;
    unsigned char var_r29 = 1;
    int var_r28 = 1;

    if (fn_8023A5A4() == 0) {
        return 6;
    }
    if (!(*(unsigned char *)(base + 0x16AE) & arg2)) {
        if (arg2 == 1) {
            if (*(unsigned char *)(base + 0x16AE) != 0) {
                if (fn_803F6150(arg0, base + 0x16A8, 6) == 0) {
                    var_r30 = 0;
                } else {
                    return 2;
                }
            }
            *(int *)(base + 0x167C) = arg4;
        } else {
            if (*(unsigned char *)(base + 0x16AE) != 0) {
                return 2;
            }
        }
        if (var_r30 != 0) {
            memcpy(base + 0x16A8, arg0, 6);
            fn_80231FB0(base + 0x1680, 0xA, arg3);
            if (arg1 != 0) {
                var_r29 = fn_80245390(arg0, arg1[0xB], arg1[0xD], *(unsigned short *)arg1 | 0x8000);
            } else {
                var_r29 = fn_80245390(arg0, 1, 0, 0);
            }
        }
        if (var_r29 != 0) {
            *(unsigned char *)(base + 0x16AE) |= arg2;
        } else {
            var_r28 = 3;
        }
    } else {
        var_r28 = 2;
    }
    return var_r28;
}
