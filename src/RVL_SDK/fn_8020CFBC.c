#pragma force_active on
#pragma global_optimizer off

extern unsigned long strlen(const char *);
extern char *strcpy(char *, const char *);
extern int strncmp(const char *, const char *, unsigned long);
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);
extern void fn_8020C90C(char *, const char *, const char *);
extern int fn_80214210(char *, int, int *, void (*)(int, void *), void *);
extern int fn_802140BC(const char *, int, int *);
extern void fn_8020D294(int, void *);
extern char lbl_8047C120[];
extern char lbl_8047C170[];
extern char lbl_8059EB50;

int fn_8020CFBC(const char *path, char *obj, int useObj, int flag)
{
    int buf[16];
    int size;
    int var_r0;
    unsigned long len;
    int r;
    int irq;

    if (useObj != 0) {
        if (strlen(path) == 0) {
            strcpy(obj + 0x34, &lbl_8059EB50);
        } else {
            if (path[0] == '/') {
                var_r0 = 0;
            } else {
                var_r0 = 1;
            }
            if (var_r0 != 0) {
                fn_8020C90C(obj + 0x34, lbl_8047C120, path);
            } else {
                strcpy(obj + 0x34, path);
                len = strlen(obj + 0x34);
                if (len != 0) {
                    if (obj[0x33 + len] == '/' && len - 1 != 0) {
                        obj[0x33 + len] = '\0';
                    }
                }
            }
        }
        if (flag == 0) {
            if (strncmp(obj + 0x34, lbl_8047C170, 8) == 0) {
                var_r0 = 1;
            } else {
                var_r0 = 0;
            }
            if (var_r0 != 0) {
                return -0x66;
            }
        }
        return fn_80214210(obj + 0x34, 0, (int *)(obj + 0x30), fn_8020D294, obj);
    }

    size = 0;
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

    if (strlen(path) == 0) {
        strcpy((char *)buf, &lbl_8059EB50);
    } else {
        if (path[0] == '/') {
            var_r0 = 0;
        } else {
            var_r0 = 1;
        }
        if (var_r0 != 0) {
            fn_8020C90C((char *)buf, lbl_8047C120, path);
        } else {
            strcpy((char *)buf, path);
            len = strlen((char *)buf);
            if (len != 0) {
                if (((char *)buf)[len - 1] == '/' && len - 1 != 0) {
                    ((char *)buf)[len - 1] = '\0';
                }
            }
        }
    }
    if (flag == 0) {
        if (strncmp((char *)buf, lbl_8047C170, 8) == 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (var_r0 != 0) {
            return -0x66;
        }
    }

    r = fn_802140BC((char *)buf, 0, &size);
    if (r == 0) {
        irq = OSDisableInterrupts();
        strcpy(lbl_8047C120, (char *)buf);
        OSRestoreInterrupts(irq);
    }
    return r;
}
