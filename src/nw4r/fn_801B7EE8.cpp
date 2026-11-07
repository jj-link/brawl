#pragma force_active on
extern "C" {
int OSDisableInterrupts();
void OSRestoreInterrupts(int);
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);
}

extern "C" void fn_801B7EE8(char* a, char* b, int c) {
    int s = OSDisableInterrupts();
    *(int*)(b + 8) = c;
    void* it = a + 0xc;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(a + 8, &it, b);
    OSRestoreInterrupts(s);
}
