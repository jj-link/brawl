#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct Event {
    u16 index;
    s16 a;
    s16 b;
    u8 address[6];
    s8 status;
    s8 c;
    s8 d;
} Event;

typedef struct Entry {
    u8 pad0[8];
    u16 type;
    u16 id;
    u8 padC[4];
    void (*callback)(int, Event *);
    u8 pad14[16];
    s16 a;
    s16 b;
    u8 address[6];
    u8 pad2E;
    s8 c;
    s8 d;
    u8 pad31[3];
} Entry;

extern char lbl_80529CF8[];
extern char lbl_8048148C[];
extern void fn_80231A14(u32, const char *, u32, int);
extern void *memcpy(void *, const void *, unsigned long);

void fn_8023F130(int status, u32 id, s8 c, s8 d, s16 a, s16 b)
{
    Event event;
    Entry *entry = (Entry *)(lbl_80529CF8 + 0x1854);
    int i;

    if ((u8)lbl_80529CF8[0x27C0] >= 4U)
        fn_80231A14(0xD0003, lbl_8048148C, id, status);

    for (i = 0; i < 3; ++i, ++entry) {
        if (entry->type == 4 && id == entry->id) {
            if (entry->callback) {
                memcpy(event.address, entry->address, 6);
                entry->a = a;
                entry->b = b;
                entry->c = c;
                entry->d = d;
                event.status = status;
                event.index = i;
                event.a = a;
                event.b = b;
                event.c = c;
                event.d = d;
                entry->callback(1, &event);
            }
            break;
        }
    }
}
