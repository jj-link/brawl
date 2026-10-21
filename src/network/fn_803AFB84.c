#pragma force_active on
typedef unsigned char u8;

void fn_803AFB84(u8 *arg0, int arg1, int arg2, short arg3, short arg4) {
    *(int *)(arg0 + 0x15F0) = arg1;
    *(int *)(arg0 + 0x15FC) = arg2;
    *(short *)(arg0 + 0x15EC) = arg3;
    *(short *)(arg0 + 0x15EE) = arg4;
}
