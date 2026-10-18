#pragma force_active on
extern "C" void fn_79_178(int* p) {
    void* base = (void*)p;
    int* a = (int*)base;
    int* b = (int*)((char*)base + 4);
    int* c = (int*)((char*)base + 8);
    *b = 0;
    *c = 0;
    *a = 0;
    *b = (int)b;
    *c = (int)b;
}
