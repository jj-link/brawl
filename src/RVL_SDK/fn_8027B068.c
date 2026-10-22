#pragma force_active on
extern char lbl_80486048[];
extern int lbl_805A0E98;
void OSCancelAlarm(void *alarm);
void __dl__FPv(void *p);

char *fn_8027B068(char *self, int arg1) {
    if (self != 0) {
        *(char **)(self + 0x1F0) = lbl_80486048;
        lbl_805A0E98 = 0;
        self[0x1EC] = 0;
        OSCancelAlarm(self + 0x1A0);
        {
            char *p = self;
            int i;
            for (i = 0; i < 4; i++) {
                OSCancelAlarm(p);
                p += 0x68;
            }
        }
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
