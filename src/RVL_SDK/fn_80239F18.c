#include <stl/internal/mem.h>
#pragma force_active on

extern unsigned char lbl_80529CF8[];
extern void *fn_8023A178(void);
extern void *fn_8023C7FC(void *);
extern unsigned short fn_80238E78(const void *);

typedef struct {
    unsigned char padding[0x1F30];
    unsigned char entries[16][0x88];
} EntryTable;

void *fn_80239F18(void *arg0)
{
    unsigned char *entry = 0;
    unsigned char *scan = lbl_80529CF8;
    unsigned char *found;
    int i;

    for (i = 0; i < 16; scan += 0x88, ++i) {
        if (!(scan[0x1FA6] & 0x80)) {
            entry = ((EntryTable *)lbl_80529CF8)->entries[i];
            break;
        }
    }
    if (entry == 0)
        entry = fn_8023A178();
    memset(entry, 0, 0x88);
    entry[0x76] = 0x80;
    entry[0x85] = 0;
    found = fn_8023C7FC(arg0);
    if (found != 0)
        memcpy(entry + 0x22, found + 8, 3);
    else
        memcpy(entry + 0x22, lbl_80529CF8 + 0x27BA, 3);
    memcpy(entry + 0x1C, arg0, 6);
    *(unsigned short *)(entry + 0x18) = fn_80238E78(arg0);
    *(unsigned int *)(entry + 0x0C) = (*(unsigned int *)(lbl_80529CF8 + 0x1974))++;
    return entry;
}
