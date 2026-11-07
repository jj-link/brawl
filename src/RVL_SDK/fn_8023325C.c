#include <string.h>
#pragma force_active on

extern unsigned char lbl_80529918[];
extern const unsigned short lbl_8040D738[];
extern void *fn_80256D1C(void *, unsigned int, void *);
extern void *fn_80256CF4(void *, unsigned short);
extern void fn_8022F0E0(void *);
extern void fn_802337D0(void *);
extern void fn_80233B74(int, int, const char *);
extern int fn_8023F454(void (*)(int, int, const char *));
extern void *fn_8022EE58(unsigned short);
extern void fn_80232034(void *, const void *);
extern char *fn_80239E78(void *);
extern void fn_802324E0(void *);

void fn_8023325C(void *arg0)
{
    unsigned short code = *(unsigned short *)((unsigned char *)arg0 + 8);
    void *entry = 0;
    unsigned short id;
    unsigned char *packet;
    char *name;
    char *other;
    unsigned char *packet2;
    int found = 0;

    if (code == 0 || code == 0xFFF0 || code == 0xFFF4) {
        id = lbl_8040D738[lbl_80529918[0x70] - 1];
        if (code == 0xFFF4 ||
            (entry = fn_80256D1C(*(void **)(lbl_80529918 + 0x14), id, 0)) != 0) {
            if (id == 0x1200) {
                if (entry != 0 && fn_80256CF4(entry, (unsigned short)0x8001) != 0)
                    found = 1;
            } else {
                found = 1;
            }
            if (found != 0)
                *(int *)(lbl_80529918 + 0x10) |= 1 << (lbl_80529918[0x70] - 1);
        }
        fn_8022F0E0(*(void **)(lbl_80529918 + 0x14));
        *(void **)(lbl_80529918 + 0x14) = 0;
        if (*(int *)(lbl_80529918 + 0xC) != 0) {
            fn_802337D0(lbl_80529918 + 0x1A);
            return;
        }
        fn_8023F454(fn_80233B74);
        packet = fn_8022EE58(0x110);
        if (packet != 0) {
            *(unsigned short *)packet = 0x208;
            packet[0x10C] = 0;
            *(int *)(packet + 0x108) = *(int *)(lbl_80529918 + 0x10);
            fn_80232034(packet + 8, lbl_80529918 + 0x1A);
            name = (char *)lbl_80529918 + 0x20;
            if ((signed char)lbl_80529918[0x20] == 0) {
                other = fn_80239E78(lbl_80529918 + 0x1A);
                if (other != 0)
                    name = other;
            }
            strncpy((char *)packet + 0xE, name, 0x20);
            fn_802324E0(packet);
        }
    } else {
        if (code == 0xFFF1 || (unsigned short)(code + 0xA) <= 1U)
            lbl_80529918[0x78] = 0;
        fn_8022F0E0(*(void **)(lbl_80529918 + 0x14));
        *(void **)(lbl_80529918 + 0x14) = 0;
        fn_8023F454(fn_80233B74);
        packet2 = fn_8022EE58(0x110);
        if (packet2 != 0) {
            *(unsigned short *)packet2 = 0x208;
            packet2[0x10C] = 1;
            *(int *)(packet2 + 0x108) = *(int *)(lbl_80529918 + 0x10);
            fn_80232034(packet2 + 8, lbl_80529918 + 0x1A);
            name = (char *)lbl_80529918 + 0x20;
            if ((signed char)lbl_80529918[0x20] == 0) {
                other = fn_80239E78(lbl_80529918 + 0x1A);
                if (other != 0)
                    name = other;
            }
            strncpy((char *)packet2 + 0xE, name, 0x20);
            fn_802324E0(packet2);
        }
    }
}
