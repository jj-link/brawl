#pragma force_active on
extern "C" {
void fn_27_199F1C(void*, int, int);
void fn_27_6A244(void*, void*, void*);
}

extern "C" void* fn_94_16C84(void* a, void* b) {
    fn_27_199F1C(a, 7, 0);
    fn_27_6A244((char*)a + 0x178, b, a);
    return a;
}
