#include <string.h>
#pragma force_active on


typedef struct {
    char pad0[12];
    u32 flags;
    u32 value;
    void *buffer;
    char pad18[2];
    char address[6];
    char name[80];
    u8 index;
} State;

typedef struct {
    u16 type;
    char pad2[6];
    char address[6];
    char name[250];
    u32 value;
} Message;

extern State lbl_80529918;
extern u16 lbl_8040D738[];
extern const u16 lbl_805A3A68;
extern const u16 lbl_805A3A6A;
extern void *fn_8022EE58(u16);
extern void fn_8022F0E0(void *);
extern void fn_80232034(void *, void *);
extern void fn_802324E0(void *);
extern char *fn_80239E78(void *);
extern void fn_802568BC(void *, unsigned int, unsigned short, void *, unsigned short, unsigned short *);
extern unsigned char fn_80256C90(void *, void *, void (*)(short));
extern void fn_80233A50(short);

void fn_802337D0(void *arg) {
    u16 pair[2];
    struct { u16 type; u16 unused; u16 code; char pad[8]; } request;
    int count = 1;
    char *name;
    Message *msg;
    pair[0] = lbl_805A3A68;
    pair[1] = lbl_805A3A6A;
    while (lbl_80529918.index < 0x17) {
        if (lbl_80529918.flags & (1 << lbl_80529918.index)) {
            lbl_80529918.buffer = fn_8022EE58(0xfa);
            if (lbl_80529918.buffer != 0) {
                lbl_80529918.flags &= ~(1 << lbl_80529918.index);
                request.type = 2;
                request.code = lbl_8040D738[lbl_80529918.index];
                if (request.code == 0x1200)
                    count = 2;
                fn_802568BC(lbl_80529918.buffer, 0xfa, 1, &request, count, pair);
                if (!fn_80256C90(arg, lbl_80529918.buffer, fn_80233A50)) {
                    fn_8022F0E0(lbl_80529918.buffer);
                    lbl_80529918.buffer = 0;
                    lbl_80529918.index = 0x17;
                } else {
                    lbl_80529918.index++;
                    return;
                }
            }
        }
        lbl_80529918.index++;
    }
    if (lbl_80529918.index >= 0x17) {
        msg = fn_8022EE58(0x110);
        if (msg != 0) {
            msg->type = 0x208;
            msg->value = lbl_80529918.value;
            fn_80232034(msg->address, lbl_80529918.address);
            name = lbl_80529918.name;
            if (!*name) {
                char *p = fn_80239E78(lbl_80529918.address);
                if (p != 0)
                    name = p;
            }
            strncpy(msg->name, name, 0x20);
            fn_802324E0(msg);
        }
    }
}