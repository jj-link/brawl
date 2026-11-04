#pragma force_active on

struct S {
    int v[10];
};

struct O {
    char pad[0xAC];
    int id;
};

extern "C" O* fn_40_15694(int, int);
extern "C" S lbl_40_data_3630;

extern "C" void fn_40_1693C(void* arg0, int arg1, int arg2) {
    S local = lbl_40_data_3630;
    O* p = fn_40_15694((int)arg0, arg1);
    int found;
    int i;
    int* arr = (int*)&local;

    i = 0;
    while (i < 10) {
        if (p && *arr == p->id) {
            found = 0;
            goto end;
        }
        ++arr;
        ++i;
    }
    found = 1;

end:
    if (found != 0) {
        char* base = (char*)arg0 + arg2 * 0x28;
        *(int*)(base + 8) = arg1;
        *(unsigned char*)(base + 0xE) = 1;
        *(unsigned char*)(base + 0xC) = 1;
        *(int*)(base + 0x10) = 0;
        *(unsigned char*)(base + 0x28) = 0;
        *(unsigned char*)(base + 0x29) = 0;
        *(int*)(base + 0x2C) = 0;
        *(unsigned char*)((char*)arg0 + 6) = 1;
    }
}