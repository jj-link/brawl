#pragma force_active on

typedef unsigned char u8;
typedef unsigned long u32;

extern "C" {
void* memset(void*, int, unsigned long);
void free__13gfHeapManagerFPv(void*);
extern u8 lbl_27_data_4B190[4][2];
}

extern "C" void fn_27_22DA48(void* self) {
    char* p = (char*)self;

    memset(p + 0x26C, 0, 0x1A28);

    if (*(void**)(p + 0x1F0)) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x1F0));
        *(void**)(p + 0x1F0) = 0;
        *(u8*)(p + 0x1E5) = 0;
    }
    if (*(void**)(p + 0x1F4)) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x1F4));
        *(void**)(p + 0x1F4) = 0;
        *(u8*)(p + 0x1E6) = 0;
    }
    if (*(void**)(p + 0x1F8)) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x1F8));
        *(void**)(p + 0x1F8) = 0;
    }
    if (*(void**)(p + 0x1FC)) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x1FC));
        *(void**)(p + 0x1FC) = 0;
    }
    if (*(void**)(p + 0x200)) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x200));
        *(void**)(p + 0x200) = 0;
    }
    if (*(void**)(p + 0x204)) {
        free__13gfHeapManagerFPv(*(void**)(p + 0x204));
        *(void**)(p + 0x204) = 0;
    }

    u32 index = *(u32*)(p + 0x1DC);
    *(u32*)(p + 0x2B4) = lbl_27_data_4B190[index][0];
    *(u32*)(p + 0x2B8) = lbl_27_data_4B190[index][1];
}
