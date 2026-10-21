#pragma force_active on
int fn_80261244(void* arg0, int arg1, int arg2) {
    int sum = arg1 + arg2;
    *(int*)((char*)arg0 + 0xC) = arg1;
    *(int*)((char*)arg0 + 0x8) = arg1;
    *(int*)((char*)arg0 + 0x10) = sum;
    *(int*)((char*)arg0 + 0x14) = sum - 0xA;
    return 0;
}
