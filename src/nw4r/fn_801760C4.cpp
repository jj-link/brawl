#pragma force_active on
extern "C" {
void* fn_801760C4(void* arg0, void* arg1) {
    unsigned short index = *(unsigned short*)((char*)arg0 + 0x42);
    void* ptr = *(void**)((char*)arg1 + index + 4);
    goto check;
next:
    ptr = *(void**)((char*)ptr + index + 4);
check:
    if (ptr == 0) return ptr;
    if (*(int*)((char*)ptr + 0xc) == 1) return ptr;
    goto next;
}
}
