#include <types.h>
#pragma force_active on
typedef struct { u32 d[9]; } Pow10Table;
extern const Pow10Table lbl_80416818;
static inline char get_digit(u32 *value, u32 divisor) {
    u32 quotient = *value / divisor;
    *value %= divisor;
    return (char)(quotient + '0');
}
s32 fn_80392B58(char *buf, u32 value) {
    Pow10Table tbl;
    s32 i;
    s32 started;
    s32 count;
    u32 d;
    u32 q;
    count = 0;
    started = 0;
    tbl = lbl_80416818;
    for (i = 0; i < 9; i++) {
        d = tbl.d[i];
        if (value >= d) {
            started = 1;
            buf[count++] = get_digit(&value, d);
        } else if (started != 0) {
            buf[count++] = '0';
        }
    }
    buf[count] = (char)(value + '0');
    return count + 1;
}
