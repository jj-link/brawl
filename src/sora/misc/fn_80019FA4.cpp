#pragma force_active on
struct gfCameraManager {
    gfCameraManager* getManager();
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_80019FEC();
extern int lbl_8059FFC0;

gfCameraManager* gfCameraManager::getManager() {
    if (lbl_8059FFC0 == 0 && lbl_8059FFC0 == 0 && __nw__FUlQ25Heaps8HeapType(0x740, 1) != 0) {
        fn_80019FEC();
    }
    return (gfCameraManager*)lbl_8059FFC0;
}
