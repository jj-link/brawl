#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

unsigned int strcspn(const char* arg0, const char* arg1) {
    u8 tbl[32];
    const char* r8;
    const char* r7;
    u8 c;

    *(u32*)&tbl[0] = 0;
    *(u32*)&tbl[4] = 0;
    *(u32*)&tbl[8] = 0;
    *(u32*)&tbl[12] = 0;
    *(u32*)&tbl[16] = 0;
    *(u32*)&tbl[20] = 0;
    *(u32*)&tbl[24] = 0;
    *(u32*)&tbl[28] = 0;

    r8 = arg1 - 1;
    while ((c = *++r8) != 0) {
        tbl[(c >> 3) & 0x1F] |= (u8)(1 << (c & 7));
    }

    r7 = arg0 - 1;
    while ((c = *++r7) != 0) {
        if (tbl[(c >> 3) & 0x1F] & (u8)(1 << (c & 7))) {
            break;
        }
    }
    return (u32)(r7 - arg0);
}
