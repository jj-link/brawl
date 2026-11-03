#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 lbl_805297D0[];
extern void *fn_8022F77C(void *);
extern void fn_8022F63C(void *, void *);
extern void fn_8022F0E0(void *);
extern u8 fn_8022F904(void *);
extern void fn_80231FB0(void *, int, int);
extern void fn_80232020(void *);
extern void fn_80242DDC(u16, void *, u16);
extern void fn_80242908(int);

void fn_80242F34(u8 *data, int size)
{
    u16 command;
    u8 *packet;
    *(u16 *)(lbl_805297D0 + 0x80) = data[0];
    command = data[1] + (data[2] << 8);
    if (command != 0xc03 && command != 0xc35 && command != 0) {
        packet = fn_8022F77C(lbl_805297D0 + 0x70);
        if (packet != 0) {
            u16 old = packet[8] + (packet[9] << 8);
            if (command == 0xfc4c && old != command) {
                fn_8022F63C(lbl_805297D0 + 0x70, packet);
                return;
            }
            fn_8022F0E0(packet);
        }
        if (fn_8022F904(lbl_805297D0 + 0x70) == 0) {
            fn_80231FB0(lbl_805297D0 + 0x4c, 0x3c, 8);
        } else {
            fn_80232020(lbl_805297D0 + 0x4c);
        }
    }
    fn_80242DDC(command, data + 3, (u16)(size - 3));
    fn_80242908(0);
}