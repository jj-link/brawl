#pragma force_active on
typedef struct { unsigned char reserved[8]; const unsigned short *classes; } CTypeMap;
typedef struct { unsigned char reserved[0x38]; CTypeMap *ctype; } Locale;
extern Locale lbl_804942B8;

typedef struct { unsigned char pad[0xC]; int **ref; } LookupResult;

extern int atoi(const char *);
extern char *strchr(const char *, int);
extern void *memcpy(void *, const void *, unsigned long);
extern int fn_8035C620(char *);
extern LookupResult *fn_8035C788(char *);

static inline int IsDigit(int c) {
    return (c < 0 || c >= 256) ? 0 : lbl_804942B8.ctype->classes[c] & 8;
}

int fn_803789AC(char *arg0, int *arg1, unsigned short *arg2) {
    char buf[0x110];
    char *host;
    char *colon;
    char *p;
    LookupResult *res;
    int addr = 0;
    unsigned short port = 0;
    int n;
    int v;

    host = arg0;
    if (arg0 == 0 || *arg0 == 0) {
        addr = 0;
        port = 0;
        goto store;
    }
    colon = strchr(arg0, ':');
    if (colon == 0) {
        port = 0;
        goto lookup;
    }
    if (colon == arg0) {
        host = 0;
        addr = 0;
    } else {
        n = colon - arg0;
        memcpy(buf, arg0, n);
        buf[n] = 0;
        host = buf;
    }
    p = colon + 1;
    while (*p != 0) {
        if (!IsDigit(*p)) {
            return 0;
        }
        p++;
    }
    v = atoi(colon + 1);
    if (v < 0 || v > 0xFFFF) {
        return 0;
    }
    port = (unsigned short)v;
lookup:
    if (host != 0) {
        addr = fn_8035C620(host);
        if ((unsigned int)(addr + 0x10000) == 0xFFFF) {
            res = fn_8035C788(host);
            if (res == 0) {
                return 0;
            }
            addr = **res->ref;
        }
    }
store:
    if (arg1 != 0) {
        *arg1 = addr;
    }
    if (arg2 != 0) {
        *arg2 = port;
    }
    return 1;
}
