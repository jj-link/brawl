#pragma force_active on
extern "C" {
extern void fn_802CD1D0(void*, int, int);

void fn_802CD3F0(void* arg0, void* arg1, void* arg2) {
    fn_802CD1D0(arg0, *(int*)((char*)arg1 + 0x24), *(int*)((char*)arg2 + 0x1C));
}
}
