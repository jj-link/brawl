#pragma force_active on
extern "C" {
void fn_8015AAA4(void*);
void fn_8015AE80(void*, int);
extern void* g_GameGlobal;

void fn_80159690(void* arg0) {
    unsigned char* p;

    p = *(unsigned char**)((unsigned char*)g_GameGlobal + 0x30);
    *(int*)(p + 0x60C) = *(int*)(p + 0x60C) + *(int*)(p + 0x4910);
    p = *(unsigned char**)((unsigned char*)g_GameGlobal + 0x30);
    if ((unsigned int)*(int*)(p + 0x60C) > 0x3B9AC9FFU) {
        *(int*)(p + 0x60C) = 0x3B9AC9FF;
    }
    fn_8015AAA4(arg0);
    fn_8015AE80(arg0, 1);
}
}
