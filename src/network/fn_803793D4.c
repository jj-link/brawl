#include <types.h>
#include <revolution/SO/SOBasic.h>
#include <string.h>
#pragma force_active on

typedef struct { unsigned char pad[12]; int **ref; } LookupResult;
typedef struct { unsigned char pad; unsigned char family; unsigned short port; unsigned int addr; } Address;
extern int fn_8035C620(char *);
extern LookupResult *fn_8035C788(char *);
extern char lbl_80490070[];

int fn_803793D4(char *host, unsigned int port, Address *addr, LookupResult **out) {
    LookupResult *result = 0;
    addr->family = 2;
    addr->port = SOHtoNs((unsigned short)port);
    if (host == 0) {
        addr->addr = 0;
    } else {
        addr->addr = fn_8035C620(host);
    }
    if ((unsigned int)(addr->addr + 0x10000) == 0xffff && strcmp(host, lbl_80490070) != 0) {
        result = fn_8035C788(host);
        if (result == 0) {
            return 0;
        }
        addr->addr = **result->ref;
    }
    if (out != 0) {
        *out = result;
    }
    return 1;
}