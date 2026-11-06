#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void *fn_8025BA20(void *arg0, u32 arg1, u32 *arg2) {
    u8 *p = (u8 *) arg0;
    u8 *var_r8 = p;

    switch (arg1 & 7) {
    case 0:
        *arg2 = 1;
        break;
    case 1:
        *arg2 = 2;
        break;
    case 2:
        *arg2 = 4;
        break;
    case 3:
        *arg2 = 8;
        break;
    case 4:
        *arg2 = 0x10;
        break;
    case 5:
        *arg2 = p[0];
        var_r8 = p + 1;
        break;
    case 6:
        *arg2 = (u16) ((p[0] << 8) + p[1]);
        var_r8 = p + 2;
        break;
    case 7:
        *arg2 = (u16) ((p[0] << 24) + (p[1] << 16) + (p[3] + (p[2] << 8)));
        var_r8 = p + 4;
        break;
    }
    return var_r8;
}
