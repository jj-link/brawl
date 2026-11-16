#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Entry {
    u8 pad0[2];
    u8 id;
    u8 pad3[3];
    u8 x6;
    u8 pad7[5];
    u8 xC;
    u8 padD[0x13];
} Entry;

typedef struct State {
    u8 pad[0x20];
    union {
        Entry entries[16];
        struct {
            u8 pad[0x1f4];
            u8 values[16];
            void (*callback)(int, void *, void *);
        } fields;
    } data;
} State;

extern State lbl_80529AC8;
extern u8 lbl_8059EDF0[8];
extern void fn_80247A5C(void);
extern void fn_8024809C(void *, u8);
extern u8 fn_80247AA0(void *);
extern void fn_80236F98(u32, u32, u32, u32);

void fn_80235AE8(void *arg0)
{
    u8 status = 6;
    u8 i;
    fn_80247A5C();
    memset(&lbl_80529AC8, 0, 0x230);
    fn_8024809C(lbl_8059EDF0, ((u8 *)arg0)[8]);
    if (fn_80247AA0(fn_80236F98) == 0) {
        lbl_80529AC8.data.fields.callback =
            *(void (**)(int, void *, void *))((char *)arg0 + 0x30);
        status = 0;
        for (i = 0; i < 16; i++) {
            lbl_80529AC8.data.entries[i].xC = 1;
            lbl_80529AC8.data.entries[i].x6 = 0xFF;
            lbl_80529AC8.data.entries[i].id = i;
            lbl_80529AC8.data.fields.values[i] = 0x10;
        }
    }
    lbl_80529AC8.data.fields.callback(0, &status, &lbl_80529AC8);
}