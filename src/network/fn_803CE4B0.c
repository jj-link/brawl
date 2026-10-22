#pragma force_active on
extern void OSCreateAlarm(void *alarm);
extern void *fn_80204768(void *p, int size, int align);
extern void *fn_803CD3B4(unsigned short idx);
extern void *memset(void *s, int c, unsigned long n);

void fn_803CE4B0(void *arg0) {
    unsigned short i;
    char *temp_r30;

    for (i = 0; i < 2; i++) {
        temp_r30 = (char *)fn_803CD3B4(i);
        memset(temp_r30, 0, 0x1E0);
        *(void **)(temp_r30 + 0x1D4) = fn_80204768(arg0, 0x2000, 0x20);
        OSCreateAlarm(temp_r30 + 0x198);
    }
}
