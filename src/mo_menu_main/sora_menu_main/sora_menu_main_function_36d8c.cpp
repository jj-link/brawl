#pragma force_active on
extern "C" void fn_2_36D8C(char* base, int a, int b) {
    char** arr = (char**)(base + a * 400 + 0x8c);
    char* p = arr[b];
    int off = *(int*)p;
    unsigned char* d = (unsigned char*)(off + (int)base);
    d[0x13cf] = 0;
}
