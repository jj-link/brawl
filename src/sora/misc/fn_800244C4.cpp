#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" int fn_801D712C(void);
extern "C" int fn_801D7134(void);
extern "C" int fn_801D7144(void);
extern "C" int fn_801D714C(void);
extern "C" void createHeap__13gfHeapManagerFiPCcii(int idx, void* name, int a, int b);
extern "C" char g_HeapInfos[];

extern "C" void fn_800244C4(void* arg0) {
    s32* p = (s32*)arg0;
    for (;;) {
        if (p[0] == 0) {
            break;
        }
        s32 idx = p[1];
        if (*(s32*)(g_HeapInfos + (idx << 4) + 8) == 0) {
            createHeap__13gfHeapManagerFiPCcii(idx, (void*)p[0], p[2], p[3]);
        }
        p += 4;
    }
    fn_801D7144();
    fn_801D712C();
    fn_801D714C();
    fn_801D7134();
}
