#pragma force_active on
extern "C" {
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
void* create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(void*, int);
}

extern "C" void fn_63_23B0(char* self) {
    void* archive = *(void**)(self + 0x1a0);
    if (archive != 0) {
        void* data = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 1, 0x15, 0xFFFE);
        if (data != 0) {
            *(void**)(self + 0x45c) = create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 0xF);
        }
    }
}
