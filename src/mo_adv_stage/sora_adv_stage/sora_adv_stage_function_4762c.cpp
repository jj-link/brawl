#pragma force_active on
extern "C" void fn_40_42F04(void* a, int b, int c);

extern "C" void fn_40_4762C(void* arg1, int arg2) {
    char* base = (char*)arg1;
    int* field = (int*)(base + 0x1bc);
    *field = 0;
    int* ptr = (int*)(base + 4);
    for (int i = 1; i < arg2; i++) {
        int idx = *field;
        *field = idx + 1;
        int val = ptr[0x4D2];
        fn_40_42F04(base + idx * 0x58 + 0x1c0, i, val);
        ptr++;
    }
}
