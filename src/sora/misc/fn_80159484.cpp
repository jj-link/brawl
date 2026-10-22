#pragma force_active on
extern "C" {
void fn_8015A7DC(void*, float);
void fn_8015AAA4(void*);
void fn_8015AE80(void*, int);
extern void* g_GameGlobal;
extern float lbl_805A2B90;

void fn_80159484(void* arg0) {
    unsigned char* p;

    p = *(unsigned char**)((unsigned char*)g_GameGlobal + 0x30);
    *(int*)(p + 0x4910) = *(int*)(p + 0x4910) + 1;
    p = *(unsigned char**)((unsigned char*)g_GameGlobal + 0x30);
    if ((unsigned int)*(int*)(p + 0x4910) > 0x3B9AC9FFU) {
        *(int*)(p + 0x4910) = 0x3B9AC9FF;
    }
    p = *(unsigned char**)((unsigned char*)g_GameGlobal + 0x30);
    if (p[0x4916] < 0xFF) {
        p[0x4916] = p[0x4916] + 1;
    }
    fn_8015A7DC(arg0, lbl_805A2B90);
    fn_8015AAA4(arg0);
    fn_8015AE80(arg0, 0);
}
}
