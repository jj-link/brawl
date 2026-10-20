#pragma force_active on

extern "C" {
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
extern unsigned int lbl_27_bss_5918;
void fn_27_23B3BC(void*);
}

void fn_27_23B3BC(void* self) {
    unsigned int index = *(unsigned int*)((char*)self + 0xD0);
    unsigned int archiveValue = *(unsigned int*)((char*)index + 0x620);

    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(
        *(void**)((char*)self + 0xCC), 1,
        (int)(archiveValue >> 24), 0xFFFE);

    if (data && *(unsigned int*)data == lbl_27_bss_5918) {
        unsigned int size = *(unsigned int*)((char*)data + 0x10);
        unsigned int value = *(unsigned int*)((char*)data + 4);
        *(void**)((char*)self + 0xD4) = (char*)data + size;
        *(unsigned int*)((char*)self + 0xD8) = value;
    } else {
        *(unsigned int*)((char*)self + 0xD4) = 0;
        *(unsigned int*)((char*)self + 0xD8) = 0;
    }
}
