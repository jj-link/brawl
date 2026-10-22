#pragma force_active on

extern "C" int fn_8020FC24();
extern void* g_gfApplication;
extern void* lbl_1_bss_20;
extern void* lbl_1_data_4B08;

extern "C" void fn_1_F61C(void* arg0) {
    int zero = 0;
    *(int*)((char*)arg0 + 0xC) = zero;
    *(int*)((char*)arg0 + 0x10) = zero;
    *(int*)((char*)arg0 + 0x14) = zero;
    *(int*)((char*)arg0 + 0x18) = zero;
    *(int*)((char*)arg0 + 0x1C) = zero;
    *(char*)((char*)arg0 + 0x20) = (char)fn_8020FC24();
    *(int*)((char*)arg0 + 0x24) = 2;
    *(int*)((char*)arg0 + 0x28) = zero;
    int v = *(int*)((char*)g_gfApplication + 0xE4) >> 24;
    if (v == 1) {
        *(char*)((char*)arg0 + 0x2C) = 1;
    } else {
        *(char*)((char*)arg0 + 0x2C) = 3;
    }
    char* p = (char*)lbl_1_bss_20;
    *(char*)(p + 0x30) = 0;
    *(void**)(p + 0x0) = lbl_1_data_4B08;
    *(int*)(p + 0x4) = 0;
    *(void**)(p + 0x8) = lbl_1_data_4B08;
    *(int*)(p + 0xC) = 0;
}
