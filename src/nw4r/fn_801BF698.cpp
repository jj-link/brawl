#pragma force_active on

extern "C" void fn_801BF698(int* p) {
    void* base = (void*)p;
    int* a = (int*)base;
    int* b = (int*)((char*)base + 4);
    int* c = (int*)((char*)base + 8);
    int* d = (int*)((char*)base + 12);

    *c = 0;
    *d = 0;
    *a = 0;
    *b = 0;
    *c = (int)c;
    *d = (int)c;
}
