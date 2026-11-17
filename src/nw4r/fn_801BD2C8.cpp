#pragma force_active on
extern "C" int fn_801BD2C8(void* arg0) {
    int b;
    int a;
    a = *(int*)((char*)arg0 + 0x4C);
    b = *(int*)((char*)arg0 + 0x50);
    return a <= b ? 0 : a - b;
}
