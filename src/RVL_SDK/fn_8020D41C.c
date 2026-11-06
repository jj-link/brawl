#pragma force_active on
#pragma global_optimizer off

typedef int s32;

extern unsigned long strlen(const char *);
extern char *strcpy(char *, const char *);
extern int strncmp(const char *, const char *, unsigned long);
extern void fn_8020C90C(char *, const char *, const char *);
extern int fn_80214210(char *, int, int *, void (*)(void), void *);
extern int fn_802140BC(const char *, int, int *);
extern void fn_8020D738(void);
extern char lbl_8047C120[];
extern char lbl_8047C17C[];
extern char lbl_8059EB50;

int fn_8020D41C(char *arg0, unsigned char *arg1, char *arg2, int arg3, int arg4)
{
    s32 buf[16];
    s32 out;
    int var_r0;
    int var_r0_2;
    unsigned long len;
    int r;

    if (strlen(arg0) == 0) {
        return -0x65;
    }
    if (arg3 != 0) {
        if (strlen(arg0) == 0) {
            strcpy(arg2 + 0x34, &lbl_8059EB50);
        } else {
            if (arg0[0] == '/') {
                var_r0 = 0;
            } else {
                var_r0 = 1;
            }
            if (var_r0 != 0) {
                fn_8020C90C(arg2 + 0x34, lbl_8047C120, arg0);
            } else {
                strcpy(arg2 + 0x34, arg0);
                len = strlen(arg2 + 0x34);
                if (len != 0) {
                    if (arg2[0x34 + len - 1] == '/' && len - 1 != 0) {
                        arg2[0x34 + len - 1] = '\0';
                    }
                }
            }
        }
        if (arg4 == 0) {
            if (strncmp(arg2 + 0x34, lbl_8047C17C, 9) == 0 && arg2[0x3D] != 0) {
                var_r0_2 = 1;
            } else {
                var_r0_2 = 0;
            }
            if (var_r0_2 != 0) {
                return -0x66;
            }
        }
        *(s32 *)(arg2 + 0x88) = (s32)arg1;
        return fn_80214210(arg2 + 0x34, 0, (int *)(arg2 + 0x30), fn_8020D738, arg2);
    }

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 0;
    buf[8] = 0;
    buf[9] = 0;
    buf[10] = 0;
    buf[11] = 0;
    buf[12] = 0;
    buf[13] = 0;
    buf[14] = 0;
    buf[15] = 0;

    if (strlen(arg0) == 0) {
        strcpy((char *)buf, &lbl_8059EB50);
    } else {
        if (arg0[0] == '/') {
            var_r0 = 0;
        } else {
            var_r0 = 1;
        }
        if (var_r0 != 0) {
            fn_8020C90C((char *)buf, lbl_8047C120, arg0);
        } else {
            strcpy((char *)buf, arg0);
            len = strlen((char *)buf);
            if (len != 0) {
                if (((char *)buf)[len - 1] == '/' && len - 1 != 0) {
                    ((char *)buf)[len - 1] = '\0';
                }
            }
        }
    }
    if (arg4 == 0) {
        if (strncmp((char *)buf, lbl_8047C17C, 9) == 0 && ((char *)buf)[9] != 0) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 != 0) {
            return -0x66;
        }
    }

    out = 0;
    r = fn_802140BC((char *)buf, 0, &out);
    if (r == 0 || r == -0x66) {
        *arg1 = 2;
        return 0;
    }
    if (r == -0x65) {
        *arg1 = 1;
        return 0;
    }
    return r;
}
