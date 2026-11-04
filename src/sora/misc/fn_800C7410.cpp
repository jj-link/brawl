#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
void netReport__FPCce(const char*, ...);
extern char lbl_80457158[];
extern char lbl_80459AE0[];
extern char* g_muWifiInterfaceTask;
extern char* lbl_805A02A0;
extern signed char lbl_805A02A8;
void* create__19muWifiInterfaceTaskFv() {
    char* base = lbl_80457158;
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x1058, 6);
    if (p) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(p, base + 0x40, 8, 2, 6, true);
        *(void**)(p + 0x3c) = lbl_80459AE0;
        *(int*)(p + 0x40) = 1;
        *(int*)(p + 0x44) = 0;
        p[0x48] = 0;
        *(signed char*)(p + 0xfcb) &= ~0x80;
        *(int*)(p + 0x1048) = 0;
        *(int*)(p + 0x104c) = 0;
        *(short*)(p + 0x1050) = 0x46;
        *(unsigned char*)(p + 0x2c) &= ~2;
        *(short*)(p + 0x1052) = 0;
        netReport__FPCce(base + 0x50);
    }
    g_muWifiInterfaceTask = p;
    lbl_805A02A0 = p;
    netReport__FPCce(base + 0x88);
    lbl_805A02A8 = 0;
    return g_muWifiInterfaceTask;
}
}