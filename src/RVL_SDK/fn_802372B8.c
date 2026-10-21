#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);

void fn_802372B8(void) {
    short *packet;

    packet = (short *)fn_8022EE58(8);
    if (packet != 0) {
        *packet = 0x170D;
        fn_802324E0(packet);
    }
}
