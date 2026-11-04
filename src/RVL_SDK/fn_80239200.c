#pragma force_active on
extern int fn_803F6150(const void *, const void *, unsigned long);
extern unsigned char lbl_80529CF8[];
extern unsigned char lbl_805297D0[];
unsigned int fn_80239200(const void *arg0)
{
    unsigned int i;
    unsigned char *entry;
    unsigned char *found;
    unsigned short flags;
    unsigned int result;
    i = 0;
    entry = lbl_80529CF8 + 0x34;
    for (;;) {
        if (entry[0x119] != 0 && fn_803F6150(entry + 8, arg0, 6) == 0) {
            found = entry;
            break;
        }
        i++;
        entry += 0x11c;
        if (i >= 4) {
            found = 0;
            break;
        }
    }
    flags = 0;
    result = 0;
    if (found != 0)
        flags = *(unsigned short *)(found + 2);
    else if (fn_803F6150(lbl_80529CF8 + 0x630, arg0, 6) == 0)
        flags = *(unsigned short *)(lbl_80529CF8 + 0x654);
    if (flags != 0) {
        if (!(flags & 0x2000)) result = 0x3fd;
        else if (!(flags & 0x1000)) result = 0x2a7;
        else if (!(flags & 0x200)) result = 0x228;
        else if (flags & 0x8000) result = 0x153;
        else if (!(flags & 0x100)) result = 0x16f;
        else if (flags & 0x4000) result = 0xe0;
        else if (flags & 0x800) result = 0xb7;
        else if (flags & 0x400) result = 0x79;
        else if (!(flags & 4)) result = 0x53;
        else if (!(flags & 2)) result = 0x36;
        else if (flags & 0x10) result = 0x1b;
        else if (flags & 8) result = 0x11;
    }
    if (result == 0x3fd && *(unsigned short *)(lbl_805297D0 + 0x7c) == 0x3f9)
        result = 0x3f9;
    return result;
}