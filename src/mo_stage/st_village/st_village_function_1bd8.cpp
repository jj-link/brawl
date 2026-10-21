#pragma force_active on
typedef unsigned short u16;

extern "C" void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
extern "C" void* create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(void*, int);

extern "C" void fn_70_1BD8(void* self) {
    void* archive = *(void**)((char*)self + 0x1A0);
    if (archive) {
        void* data = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 1, 0x15, 0xFFFE);
        if (data)
            *(void**)((char*)self + 0x28C) =
                create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 0xF);

        data = getData__9gfArchiveF11ARCNodeTypeiUs(
            *(void**)((char*)self + 0x1A0), 1, 0x16, 0xFFFE);
        if (data)
            *(void**)((char*)self + 0x290) =
                create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 0xF);
    }
}
