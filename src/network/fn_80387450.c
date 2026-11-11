#include <types.h>
#include <string.h>
#pragma force_active on
extern int fn_803F6150(const void *, const void *, unsigned long);
extern char lbl_8059FB68[8];
extern s32 lbl_805A10F0;
extern char *SOInetNtoA(s32 *);
extern u16 SONtoHs(u16);
extern s32 fn_803A7AF4(s32);
extern s32 fn_8035A590(s32);
extern void *fn_8035A598(s32, s32);
extern void fn_80386C88(void *, void *, void *);
extern void fn_80386ED4(void *, void *, void *);
extern void fn_8038724C(void *, void *, void *);
typedef struct SocketAddress { u8 pad0[2]; u16 port; s32 address; } SocketAddress;
typedef struct Record { u8 pad0[8]; s32 id; } Record;
static inline void *find(s32 id) {
    s32 i;
    void *found;
    if (lbl_805A10F0 == 0) return 0;
    for (i = 0; i < fn_8035A590(lbl_805A10F0); i++) {
        found = fn_8035A598(lbl_805A10F0, i);
        if (((Record *)found)->id == id) return found;
    }
    return 0;
}
void fn_80387450(u8 *arg0, s32 arg1, SocketAddress *arg2) {
    u8 packet[0x45];
    s32 address;
    u8 type;
    s32 id;
    void *found;
    s32 matched;
    matched = !fn_803F6150(arg0, lbl_8059FB68, 6);
    if (matched) {
        type = arg0[7];
        address = arg2->address;
        SOInetNtoA(&address);
        SONtoHs(arg2->port);
        if (type == 5 || type == 7) {
            if (arg1 >= 0x14) {
                memcpy(packet, arg0, 0x14);
                id = fn_803A7AF4(*(s32 *)(packet + 8));
                found = find(id);
                if (found != 0) {
                    if (type == 5)
                        fn_80386C88(found, packet, arg2);
                    else
                        fn_80386ED4(found, packet, arg2);
                }
            }
        } else {
            if (arg1 >= 0x15) {
                memcpy(packet, arg0, 0x15);
                id = fn_803A7AF4(*(s32 *)(packet + 8));
                found = find(id);
                if (found != 0)
                    fn_8038724C(found, packet, arg2);
            }
        }
    }
}