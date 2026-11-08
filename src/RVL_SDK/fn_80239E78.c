#pragma force_active on
extern char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);

static inline char *find_entry(const void *arg0, int i)
{
    char *ptr = lbl_80529CF8 + 0x1F30;
    while (i < 0x10) {
        if ((*(unsigned char *)(ptr + 0x76) & 0x80) &&
            fn_803F6150(ptr + 0x1C, arg0, 6) == 0) {
            return ptr;
        }
        i++;
        ptr += 0x88;
    }
    return 0;
}

void *fn_80239E78(const void *arg0)
{
    int i = 0;
    void *result = 0;
    char *ptr = find_entry(arg0, i);
    if (ptr != 0) {
        result = ptr + 0x35;
    }
    return result;
}
