#pragma force_active on
extern "C" unsigned int fn_41_B34C(void*);
extern "C" void* getInstance__9emManagerFv();
extern "C" void* fn_41_D044(void*, unsigned int);
extern "C" void* fn_41_CECC(void*, void*);
extern "C" void fn_41_B1E8(void*, void*, void*, int, int);

extern "C" void fn_41_B438(void* p, int a, int b) {
    if (b < 0 || a == 0) {
        return;
    }
    if (fn_41_B34C(p) == 1) {
        return;
    }
    void* task = fn_41_D044(
        getInstance__9emManagerFv(),
        *(unsigned int*)((char*)p + 0xB0));
    void* node = fn_41_CECC(getInstance__9emManagerFv(), task);
    fn_41_B1E8(p, node, p, a, b);
}
