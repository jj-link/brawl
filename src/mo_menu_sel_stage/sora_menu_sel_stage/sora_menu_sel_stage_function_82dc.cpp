#pragma force_active on
extern "C" {
void fn_80039E90(int, int, int);
void fn_80039D40(int, int, int);
}

extern "C" void fn_11_82DC(char* arg0) {
    char* base = arg0 + *(int*)(arg0 + 0x44) * 0x58;
    *(int*)(base + 0x70) = 2;
    int mode = *(int*)(base + 0x74);
    int idx = *(int*)(base + 0x78);
    int val = *(int*)(arg0 + (mode << 4) + 0x54) + idx * 0x18;
    if (mode == 1)
        fn_80039E90(*(int*)(arg0 + 0x68), 3, val);
    else
        fn_80039D40(*(int*)(arg0 + 0x68), 3, val);
}
