#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
extern void* fn_8022EFF8(int);
extern u8 fn_802560DC(int, void*);
extern void fn_80256858(void*, void*);

void fn_80254CB8(u8* self, int arg) {
    int v = 1;
    u8* p;
    char* pkt;
    int f;
    if (self[0x6d] == 0) v = 0;
    f = (v << 1) & 0xFE;
    pkt = fn_8022EFF8(2);
    if (pkt != 0) {
        p = (u8*)pkt + 0x11;
        *(u16*)(pkt + 4) = 9;
        p[0] = (u8)(f | 1 | ((arg << 2) & 0x3FC));
        p[1] = 0x53;
        p[2] = 1;
        p[3] = fn_802560DC(3, p);
        *(u16*)(pkt + 2) = 4;
        fn_80256858(self, pkt);
    }
}
