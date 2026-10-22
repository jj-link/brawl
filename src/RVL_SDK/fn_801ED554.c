#pragma force_active on
extern int fn_801F2D34(int);
extern unsigned char fn_801F2D54(int);
extern unsigned char* const __GXData;

void* fn_801ED554(int arg0, int arg1)
{
    int type = fn_801F2D34(arg0);
    unsigned char flag = fn_801F2D54(arg0);

    arg1 %= 8;

    switch (type) {
    case 6:
        if (flag) {
            return __GXData + arg1 * 16 + 0x358;
        }
        return __GXData + arg1 * 16 + 0x2D8;

    case 8:
    case 9:
    case 10:
        return __GXData + arg1 * 16 + 0x258;

    default:
        if (flag) {
            return __GXData + arg1 * 16 + 0x2D8;
        }
        return __GXData + arg1 * 16 + 0x258;
    }
}
