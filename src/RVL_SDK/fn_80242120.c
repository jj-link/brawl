#include <types.h>
#pragma force_active on
extern char lbl_80529CF8[];
extern u8 fn_8023D57C(void *, void *, int, int, int);
typedef u8 (*Callback)(void *, void *, void *, void *, u8, u8);
u8 fn_80242120(u8 *p)
{
    u8 *data;
    u8 *ptr = 0;
    u8 value;
    u8 result;
    u8 old;
    if ((p[0x76] & 8) || *(u16 *)(p + 0x18) == 0xffff) {
        if (*(Callback *)(lbl_80529CF8 + 0x190c) == 0)
            return 4;
        data = *(u8 **)p;
        if (data != 0) {
            if (p[0x80] != 0)
                ptr = data + 0x10;
            else
                ptr = data + 0x26;
            value = data[0xf];
        } else {
            value = 0;
        }
        p[0x7f] = 4;
        result = (*(Callback *)(lbl_80529CF8 + 0x190c))(p + 0x1c, p + 0x22, p + 0x35, ptr, value, p[0x80]);
        if (result == 0) {
            u8 flags = p[0x76];
            p[0x7f] = 0;
            p[0x76] = flags | 1;
        }
        return result;
    }
    old = p[0x7f];
    p[0x7f] = 3;
    if (fn_8023D57C(p + 0x1c, 0, 2, 0x1e, 0) != 1)
        p[0x7f] = old;
    return 1;
}