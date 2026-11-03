#pragma force_active on
typedef struct Inner { char pad[0x14]; int field14; } Inner;
typedef struct Entry { char pad[8]; Inner *inner; char pad2[0xc]; int field18; } Entry;
extern void *fn_8036FD58(void *, int);
extern int fn_80370758(void *, int, Entry **);
extern int fn_80369C64(void *, int, int, int);
extern void *fn_8036FDC8(void *, int, int);
extern int fn_8036FE98(void *, void *);
extern int fn_8036FF20(void *, void *);
extern int fn_80370118(void *, void *, int, int);
int fn_80369D58(void *a, int b, int c, int d, int e) {
    Entry *entry;
    void *p;
    int result;
    int out;
    p = fn_8036FD58(a, b);
    if (p == 0) {
        if (!fn_80370758(a, b, &entry) || !entry->inner || !entry->inner->field14) {
            if (e == 0xb00) return 3;
            return fn_80369C64(a,b,c,d);
        }
        p = fn_8036FDC8(a,b,1);
        if (!p) return 1;
        if (!entry->field18) {
            result = fn_8036FE98(a,p);
            if (result) return result;
        } else {
            result = fn_8036FF20(a,p);
            if (result) return result;
        }
    }
    result = fn_80370118(a,p,c,d);
    out = 0;
    if (result) out = result;
    return out;
}