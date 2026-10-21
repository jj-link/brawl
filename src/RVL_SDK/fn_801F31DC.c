#pragma force_active on
extern int* __GXData;

int fn_801F31DC(int arg0) {
    int old = ((int*)__GXData)[0x518 / 4];
    ((int*)__GXData)[0x518 / 4] = arg0;
    return old;
}
