#include <types.h>
#pragma force_active on
static inline s32 my_strlen(char *s)
{
    s32 n = 0;
    while (*s != 0) {
        s++;
        n++;
    }
    return n;
}
static inline void insert_char(char *buf, char c)
{
    s32 i;
    for (i = my_strlen(buf); i >= 0; i--) {
        buf[i + 1] = buf[i];
    }
    buf[0] = c;
}
static inline void shift_buf(char *buf)
{
    s32 i;
    for (i = my_strlen(buf); i >= 0; i--) {
        buf[i + 1] = buf[i];
    }
}
static inline void append_char(char *buf, char c)
{
    s32 n = my_strlen(buf);
    buf[n] = c;
    buf[n + 1] = 0;
}
s32 fn_80397878(char *buf, u32 value, u32 base, s8 letter, s32 is_signed, s32 width, s8 pad, s32 conv)
{
    s32 len;
    s32 i;
    char *p;
    s32 ret;
    s32 count;
    s32 neg;

    if (is_signed != 0 && (value & 0x80000000)) {
        value = -value;
        neg = 1;
    } else {
        neg = 0;
    }
    count = 0;
    ret = 0;

    while (value != 0) {
        s8 digit;
        char c;

        p = buf;
        len = 0;
        digit = (s8)(value % base);
        value = value / base;

        while (*p != 0) {
            p++;
            len++;
        }
        i = len;
        while (i >= 0) {
            buf[i + 1] = buf[i];
            i--;
        }
        c = (char)(digit + (digit > 9 ? letter : '0'));
        ret++;
        buf[0] = c;
        count++;
    }

    if (buf[0] == 0) {
        value = (u32)buf;
        len = 0;
        while (*(char *)value != 0) {
            value++;
            len++;
        }
        i = len;
        while (i >= 0) {
            buf[i + 1] = buf[i];
            i--;
        }
        ret++;
        buf[0] = '0';
        count++;
    }

    if (pad != '0') {
        pad = ' ';
    }
    conv = (s8)conv;
    count += neg;

    while (count < width) {
        if (conv == 'L') {
            s32 len;
            char *p;
            len = 0;
            p = buf;
            while (*p != 0) {
                p++;
                len++;
            }
            i = len;
            buf[i++] = ' ';
            ret++;
            buf[i] = 0;
        } else {
            s32 len;
            s32 i;
            char *p;

            len = 0;
            p = buf;
            while (*p != 0) {
                p++;
                len++;
            }
            i = len;
            while (i >= 0) {
                buf[i + 1] = buf[i];
                i--;
            }
            buf[0] = pad;
            ret++;
        }
        count++;
    }

    if (neg) {
        insert_char(buf, '-');
    }

    return ret;
}
