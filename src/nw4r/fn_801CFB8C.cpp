#pragma force_active on
extern "C" {
int OSDisableInterrupts();
void OSRestoreInterrupts(int);
void fn_801E187C(void*);
void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);
}

extern "C" void fn_801CFB8C(char* a, char* b, int c) {
    int s = OSDisableInterrupts();
    b[0xc] = 1;
    char* p = a + c * 12;
    void* it = p + 4;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(p, &it, b + 4);
    fn_801E187C(a + 0x2c);
    OSRestoreInterrupts(s);
}
