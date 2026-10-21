#pragma force_active on
typedef unsigned char u8;

extern void fn_8021A558(int type, int arg);

void fn_8027AC0C(void* obj) {
    int type = *(int*)obj;
    u8* p = (u8*)obj;
    if (type >= 4) {
        return;
    }
    if (p[0x1c] == 0) {
        return;
    }
    p[0x1c] = 0;
    fn_8021A558(type, 0);
}
