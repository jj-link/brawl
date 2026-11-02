#pragma force_active on
extern "C" {
struct ntFriendInfo;
void** getInstance__12ntFriendInfoFv(ntFriendInfo* self);
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_80146FCC(int);
void fn_8014B130(int);
void fn_801473AC(void);
extern char lbl_8045F7A8[];
extern int lbl_805A03E8;
extern int lbl_805A03F4;
extern int g_NtMatchingStatus;

int fn_80149644(char* self) {
    char* base = lbl_8045F7A8;
    char* p = (char*)*getInstance__12ntFriendInfoFv((ntFriendInfo*)self) + 0x4f0;
    if (p != 0) {
        p[0x87] = 1;
        self[0x33f4] = 1;
    }
    if (*(int*)(self + 0x34a4) != 0) {
        *(int*)(self + 0x34a4) = 0;
        netReport__FPCce(base + 0x7ac);
    }
    *(int*)(self + 0x3428) = 0;
    *(int*)(self + 0x342c) = 0;
    *(int*)(self + 0x34a4) = 0;
    *(int*)(self + 0x3430) = 0;
    *(int*)(self + 0x3434) = 0;
    int v;
    switch (lbl_805A03F4) {
    case 2: case 3: case 4: case 5: case 6: case 7:
        v = 1; break;
    default:
        v = 0; break;
    }
    if (v == 0) {
        int w;
        switch (lbl_805A03E8) {
        case 7: {
            int u;
            switch (lbl_805A03F4) {
            case 2: case 3: case 4: case 5: case 6: case 7:
                u = 1; break;
            default:
                u = 0; break;
            }
            if (u == 0) goto L;
            w = 1;
            break;
        }
        case 2: case 3: case 6: case 14:
            w = 1; break;
        default:
        L:
            w = 0; break;
        }
        if (w == 0) fn_801473AC();
    }
    switch (g_NtMatchingStatus) {
    case 5: case 10:
        return 1;
    case 7: case 8: case 9: case 12:
        fn_80146FCC(10);
        return 1;
    default:
        netReport__FPCce(base + 0xa84);
        fn_800C8F68(base + 0xaa0);
        fn_8014B130(6);
        return 0;
    }
}
}
