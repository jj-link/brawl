#include <internal/printf.h>
#pragma force_active on
struct in_addr { unsigned long s_addr; };
extern char lbl_804926BC[];
extern char lbl_80537698[0x28];
char *SOInetNtoA(struct in_addr in) {
    unsigned char *addr = (unsigned char *)&in;
    sprintf(lbl_80537698, lbl_804926BC, addr[0], addr[1], addr[2], addr[3]);
    return lbl_80537698;
}
