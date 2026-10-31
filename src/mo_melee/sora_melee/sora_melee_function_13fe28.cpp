#pragma force_active on
extern "C" {
void fn_27_1E3C78(void*, void*, void*, void*, void*, void*, void*, void*);

void fn_27_13FE28(char* self, void* p2, void* p3, void* p4, void* p5, void* p6) {
    void* r0 = *(void**)(self + 0x114);
    if (r0 == 0) {
        return;
    }
    void* a = *(void**)(self + 0xac);
    void* b = *(void**)(self + 0xb8);
    fn_27_1E3C78(r0, p2, p3, p4, p5, p6, a, b);
}
}
