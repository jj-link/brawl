#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];

typedef struct Reader {
    u8 *cur;
    u8 *end;
    u32 pad;
    u32 mode;
} Reader;

typedef int (*IsLeadFn)(int, int);
typedef void (*ConvFn)(void *, void *);

#define IS_LEAD (*(IsLeadFn *)(lbl_8053B248 + 0x30))
#define CONV24 (*(ConvFn *)(lbl_8053B248 + 0x24))
#define CONV28 (*(ConvFn *)(lbl_8053B248 + 0x28))

static int isLower(u16 c) {
    return c >= 0x61 && c <= 0x7a;
}

static int toUpper(u16 c) {
    if (isLower(c)) {
        return c - 0x20;
    }
    return c;
}

static u32 fullUpper(u16 c, u16 *out) {
    if (c >= 0xff41 && c <= 0xff5a) {
        *out = c - 0x20;
        return 1;
    }
    return 0;
}

static u32 fullUpper2(u16 *p) {
    if (fullUpper(*p, p) == 1) {
        CONV28(p, p);
        return 1;
    }
    return 0;
}

u16 fn_803BD364(Reader *r, s32 arg1) {
    u8 buf[3];
    u16 spC;
    u16 spA;
    u16 sp8;
    u32 ok;
    u32 ch;
    u32 *new_var;
    int islower;

    if (r->mode == 1) {
        s8 c = *r->cur++;
        buf[0] = c;
        buf[1] = 0;
        if (c == 0 || r->end < r->cur) {
            return 0;
        }
        if (IS_LEAD(c, 1)) {
            buf[1] = *r->cur++;
            spC = (buf[0] << 8) + buf[1];
        } else {
            spC = (s8)buf[0];
        }
        if (arg1 != 0) {
            CONV24(buf, &spC);
        }
    } else {
        buf[0] = *(u16 *)r->cur;
        buf[1] = *(u16 *)r->cur >> 8;
        r->cur += 2;
        buf[2] = 0;
        if (((s8)buf[0] == 0 && (s8)buf[1] == 0) || r->end < r->cur) {
            return 0;
        }
        spC = (buf[1] << 8) + buf[0];
        if (arg1 == 0) {
            CONV28(&spC, &spA);
            if (IS_LEAD(spA >> 8, 1)) {
                spC = spA;
            } else {
                spC = (s8)buf[0];
            }
        }
    }

    ch = spC;
    islower = 0;
    if (ch >= 0x61 && ch <= 0x7a) {
        islower = 1;
    }
    new_var = &ch;
    if (islower) {
        ch -= 0x20;
    }
    spC = *new_var;
    if (arg1 != 0) {
        if (fullUpper(ch, &sp8) == 1) {
            spC = sp8;
        }
    } else {
        CONV24(&spC, &sp8);
        ok = fullUpper(sp8, &sp8);
        if (ok == 1) {
            CONV28(&sp8, &sp8);
            ch = 1;
        } else {
            ch = 0;
        }
        if (*new_var == 1) {
            spC = sp8;
        }
    }
    return spC;
}
