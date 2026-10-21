#pragma force_active on
extern "C" {
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
void* create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(void*, int);
}

extern "C" void fn_54_286C(char* self) {
    if (*(void**)(self + 0x1a0)) {
        void* data = getData__9gfArchiveF11ARCNodeTypeiUs(*(void**)(self + 0x1a0), 1, 0x15, 0xFFFE);
        if (data) {
            *(void**)(self + 0x828) = create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 0xF);
        }
        data = getData__9gfArchiveF11ARCNodeTypeiUs(*(void**)(self + 0x1a0), 1, 0x16, 0xFFFE);
        if (data) {
            *(void**)(self + 0x82c) = create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 0xF);
        }
    }
}
