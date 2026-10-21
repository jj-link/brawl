#pragma force_active on
extern "C" void fn_8004B23C(void* arg0, void** arg1, int* arg2) {
    *arg1 = *(void**)((char*)arg0 + 0x24);
    void* ptr = *(void**)((char*)arg0 + 0x24);
    *arg2 = 0x388;
    int val = (int)*(unsigned short*)((char*)ptr + 0x33E) + 0x388;
    *arg2 = val;
    val += (int)*(unsigned short*)((char*)ptr + 0x33A);
    *arg2 = val;
    int res = val + *(int*)((char*)ptr + 0x10);
    *arg2 = res;
}
