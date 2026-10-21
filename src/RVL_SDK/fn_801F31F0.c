#pragma force_active on
extern char* __GXData;

int fn_801F31F0(int arg0) {
    int old = *(int*)(__GXData + 0x51c);
    *(int*)(__GXData + 0x51c) = arg0;
    return old;
}
