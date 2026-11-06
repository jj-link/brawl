#pragma force_active on
extern int *fn_8035B1C4(void *, int *);
extern double fn_803FBBF8(const char *);

double fn_803888B8(void *arg0, int arg1, double value) {
    int key;
    int *entry;
    const char *str;
    if (arg0 == 0) {
        str = 0;
    } else {
        key = arg1;
        entry = fn_8035B1C4(*(void **)((char *)arg0 + 0x18), &key);
        if (entry == 0) {
            str = 0;
        } else {
            str = (const char *)entry[1];
        }
    }
    if (str == 0) {
        return value;
    }
    return fn_803FBBF8(str);
}