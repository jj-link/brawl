#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int fn_803D620C(s8 a);
void fn_803D6B68(char **arg0, u16 arg1, u8 *arg2) {
    u32 c;
    char *p;
    u16 *w;
    u8 *out;
    u16 n;
    int flag;
    out = arg2;
    n = arg1;
    if ((u32)arg0[3] == 1) {
        p = arg0[0];
        while (n != 0 && (s8)*p != 0) {
            *out = (u8)fn_803D620C((s8)*p);
            out++;
            p++;
            n--;
        }
    } else {
        w = (u16 *)arg0[0];
        while (n != 0 && *w != 0) {
            c = *w;
            flag = 0;
            if (c >= 0x61 && c <= 0x7A) {
                flag = 1;
            }
            if (flag != 0) {
                c -= 0x20;
            }
            out[0] = (u8)c;
            out[1] = (u8)(c >> 8);
            w++;
            out += 2;
            n--;
        }
        *out = 0;
    }
    *out = 0;
}