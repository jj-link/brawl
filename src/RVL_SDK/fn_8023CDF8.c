#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern void *memset(void *, int, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern char lbl_80529CF8[];

typedef struct Entry {
    u32 age;
    u8 pad[6];
    u8 address[6];
    u8 pad10[10];
    u8 used;
    u8 pad1b;
} Entry;

Entry *fn_8023CDF8(const void *address)
{
    Entry *p = (Entry *)(lbl_80529CF8 + 0x16e4);
    Entry *oldest = p;
    u8 i = 0;
    u32 age = 0xffffffff;

    for (; i < 12; ++i, ++p) {
        if (p->used == 0) {
            memset(p, 0, 0x1c);
            memcpy(p->address, address, 6);
            p->used = 1;
            return p;
        }
        if (p->age < age) {
            oldest = p;
            age = p->age;
        }
    }

    if (*(void (**)(void *, int))(lbl_80529CF8 + 0x16bc))
        (*(void (**)(void *, int))(lbl_80529CF8 + 0x16bc))((u8 *)oldest + 8, 0);

    memset(oldest, 0, 0x1c);
    memcpy(oldest->address, address, 6);
    oldest->used = 1;
    return oldest;
}
