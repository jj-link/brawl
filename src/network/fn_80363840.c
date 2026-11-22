#pragma force_active on
typedef struct {
    char *start;
    int len;
} Token;

typedef struct {
    char reserved[8];
    unsigned short *classes;
} CTypeMap;

typedef struct {
    char reserved[0x38];
    CTypeMap *ctype;
} Locale;

extern Locale lbl_804942B8;
extern char lbl_8059F5B0[5];
extern char *strchr(const char *s, int c);

static inline int CharClass(int c, int mask)
{
    return (c < 0 || c >= 256) ? 0 : (lbl_804942B8.ctype->classes[c] & mask);
}

int fn_80363840(void *unused, char *buf, int len, int *pos, Token *out)
{
    int p;
    char c;
    int seen_colon;
    int ok;
    char *start;

    seen_colon = 0;
    while ((p = *pos) < len) {
        if (strchr(lbl_8059F5B0, (signed char)buf[p]) == 0) {
            ok = 1;
            goto merge;
        }
        *pos += 1;
    }
    ok = 0;
merge:
    if (ok == 0) {
        return 0;
    }
    if (p >= len) {
        return 0;
    }
    start = buf + p;
    if (CharClass((signed char)buf[p], 9) == 0 ||
        CharClass((signed char)buf[p], 8) != 0) {
        return 0;
    }
    out->start = start;
    out->len = 1;
    *pos += 1;

    while (*pos < len && (c = buf[*pos], strchr(lbl_8059F5B0, c) == 0)) {
        int ch = c;
        if (ch == ':') {
            if (seen_colon != 0) {
                return 0;
            }
            seen_colon = 1;
        } else if (ch != '_' && ch != '-') {
            if (CharClass(ch, 9) == 0) {
                return 1;
            }
        }
        out->len += 1;
        *pos += 1;
    }
    return 1;
}
