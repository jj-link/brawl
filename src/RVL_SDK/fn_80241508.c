#include <string.h>
#pragma force_active on


extern u8 lbl_80529CF8[];
extern void *fn_8023A038(unsigned int);
extern void fn_80232020(void *);
extern int fn_803F6150(const void *, const void *, unsigned long);

typedef void (*Callback)(void *, void *, void *, int);

void fn_80241508(unsigned int arg0, unsigned int arg1)
{
    u8 *obj = fn_8023A038(arg0);
    if (obj != 0) {
        if ((obj[0x81] & 0x40) && *(Callback *)(lbl_80529CF8 + 0x191c)) {
            if (arg1 == 0x17)
                (*(Callback *)(lbl_80529CF8 + 0x191c))(obj + 0x1c, obj + 0x22, obj + 0x35, 0x17);
            else
                (*(Callback *)(lbl_80529CF8 + 0x191c))(obj + 0x1c, obj + 0x22, obj + 0x35, 5);
        }
        if (*(int *)(lbl_80529CF8 + 0x194c) && fn_803F6150(lbl_80529CF8 + 0x1954, obj + 0x1c, 6) == 0) {
            fn_80232020(lbl_80529CF8 + 0x193c);
            *(int *)(lbl_80529CF8 + 0x194c) = 0;
            memset(lbl_80529CF8 + 0x1954, 0xff, 6);
            if (*(Callback *)(lbl_80529CF8 + 0x191c))
                (*(Callback *)(lbl_80529CF8 + 0x191c))(obj + 0x1c, obj + 0x22, obj + 0x35, 0xe);
        }
        *(u16 *)(obj + 0x18) = 0xffff;
        obj[0x7f] = 0;
        obj[0x76] &= 0xf8;
        obj[0x81] &= 0x80;
        *(u32 *)(obj + 4) = 0;
    }
}
