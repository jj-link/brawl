#pragma force_active on
extern "C" char* fn_802981B8(void* arg0, char* arg1) {
    int n = *(int*)((char*)arg0 + 8);
    int t = (n << 2) - n;
    return arg1 + (t * 0x30) + (t << 5);
}
