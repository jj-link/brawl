#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern u16 SONtoHs(u16);
extern s32 fn_8038A298(const u8 *arg0, s32 arg1);
extern s32 fn_8038A1B0(s32 arg0, const u8 *arg1);
extern void fn_8035B078(void *arg0, s32 *arg1);
extern char lbl_8059FBB4[5];
extern void *memcpy(void *, const void *, unsigned long);
extern int sprintf(char *, const char *, ...);
extern unsigned long strlen(const char *);

void fn_80388B84(void *arg0, u8 *pos, s32 remaining)
{
    u8 *val;
    u8 *key;
    u8 *cur;
    u8 *field;
    s32 count;
    s32 pass;
    s32 second;
    s32 item;
    s32 length;
    s32 pair[2];
    s32 indexed[2];
    char name[128];
    u16 entries;

    while ((s8)*pos != 0) {
        length = fn_8038A298(pos, remaining);
        if (length < 0) {
            return;
        }
        key = pos;
        remaining -= length;
        pos += length;

        length = fn_8038A298(pos, remaining);
        if (length < 0) {
            return;
        }
        val = pos;
        pos += length;
        remaining -= length;

        pair[0] = fn_8038A1B0(0, key);
        pair[1] = fn_8038A1B0(0, val);
        fn_8035B078(*(void **)((char *)arg0 + 0x18), pair);
    }

    pos++;
    remaining--;

    for (pass = 0; pass < 2; pass++) {
        if (remaining < 2) {
            return;
        }
        memcpy(&entries, pos, 2);
        entries = SONtoHs(entries);
        pos += 2;
        remaining -= 2;

        field = pos;
        count = 0;
        while ((s8)*pos != 0) {
            length = fn_8038A298(pos, remaining);
            if (length < 0) {
                return;
            }
            if (length > 100) {
                return;
            }
            pos += length;
            remaining -= length;
            count++;
        }
        pos++;
        remaining--;

        for (second = 0; second < (s32)entries; second++) {
            cur = field;
            for (item = 0; item < count; item++) {
                length = fn_8038A298(pos, remaining);
                if (length < 0) {
                    return;
                }
                sprintf(name, lbl_8059FBB4, cur, second);
                indexed[0] = fn_8038A1B0(0, (u8 *)name);
                indexed[1] = fn_8038A1B0(0, pos);
                fn_8035B078(*(void **)((char *)arg0 + 0x18), indexed);
                pos += length;
                remaining -= length;
                cur += strlen((char *)cur) + 1;
            }
        }
    }
}
