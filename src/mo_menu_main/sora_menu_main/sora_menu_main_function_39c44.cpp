#pragma force_active on
extern "C" {
extern void* g_gfPadSystem;
extern void* g_muWifiInterfaceTask;
void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, void*);
int fn_16_998(void*, void*, char*, int, int);
void utf8to16__7MessageFPwPCc(unsigned short*, const char*);
void fn_800D2320(void*, const unsigned short*);
}
extern "C" int fn_2_39C44(unsigned char* self) {
    unsigned short wtext[6];
    char text[0x1c];
    unsigned char pad[0x48];
    int result = *(int*)(self + 0x138);
    getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, 0xf0, pad);
    *(int*)(pad + 0x4) = *(int*)(self + 0x80);
    *(int*)(pad + 0xc) = *(int*)(self + 0x84);
    *(int*)(pad + 0x14) = *(int*)(self + 0x88);
    switch (fn_16_998(self + 0x14c, pad, text, 1, 0)) {
    case 0:
        utf8to16__7MessageFPwPCc(wtext, text);
        fn_800D2320(g_muWifiInterfaceTask, wtext);
        result = 9;
        break;
    case 0x7fffffff:
        break;
    }
    return result;
}
