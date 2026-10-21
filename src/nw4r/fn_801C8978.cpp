#pragma force_active on
extern "C" void fn_801C8978(int* p) {
    int* a = p;
    int* b = (int*)((char*)p + 4);
    int* c = (int*)((char*)p + 8);
    *b = 0;
    *c = 0;
    *a = 0;
    *b = (int)b;
    *c = (int)b;
}
