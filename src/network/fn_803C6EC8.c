#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 name[9]; } Entry;
extern Entry lbl_80563360[31];

int fn_803C6EC8(u16 *s) {
    int len = 0;
    u16 *p = s;
    int hash;
    while (*p) { p++; len++; }
    if (len < 8) {
        u32 shift;
        u32 sum;
        u16 *q;
        int i;
        q = s;
        sum = 0;
        shift = 0;
        for (i = 0; i < (u32)len; i++) {
            if (shift > 7) shift = 0;
            sum += *q << (shift * 4);
            q++;
            shift++;
        }
        hash = sum % 31;
    } else {
        hash = -1;
    }
    if (hash != -1) {
        int n = 0;
        int m;
        int j;
        p = s;
        while (*p) { p++; n++; }
        for (j = 0; j < 15; j++) {
            int idx = (hash + j * j) % 31;
            u16 *entry = lbl_80563360[idx].name;
            u16 *t = entry;
            m = 0;
            while (*t) { t++; m++; }
            if (n == m) {
                u16 *a;
                int k;
                int equal;
                a = s;
                equal = 1;
                for (k = 0; k < n; k++) {
                    if (*a != *entry) { equal = 0; break; }
                    a++;
                    entry++;
                }
                if (equal) return idx;
            }
        }
    }
    return -1;
}