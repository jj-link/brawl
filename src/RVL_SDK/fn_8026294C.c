#pragma force_active on
extern int fn_80262B60(void *);

int fn_8026294C(void *arg0) {
    int result;
    result = fn_80262B60(arg0);
    if (result < 0) {
        return result;
    }
    if (*(unsigned short *)((char *)arg0 + 0x17DC) == 0) {
        return -0x50;
    }
    *(int *)((char *)arg0 + 0x17E0) =
        *(unsigned char *)((char *)arg0 + 0x17E9) *
        *(unsigned short *)((char *)arg0 + 0x17EC);
    *(int *)((char *)arg0 + 0x17E4) =
        *(unsigned char *)((char *)arg0 + 0x17EA) *
        *(unsigned short *)((char *)arg0 + 0x17EE);
    return result;
}
