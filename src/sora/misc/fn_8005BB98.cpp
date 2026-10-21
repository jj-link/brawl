#pragma force_active on
extern "C" {
void Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(void*, void*);

void fn_8005BB98(char* base, void* node) {
    unsigned char idx = *(unsigned char*)((char*)node + 0xe);
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(base + idx * 12 + 0x108, node);
}
}
