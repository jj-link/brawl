#pragma force_active on
extern "C" {
extern char lbl_8045C594[];
void fn_800B96E8(void*, int, void*);
void* fn_800FBB18(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0xCC) = lbl_8045C594;
    fn_800B96E8(p + 0x24, 0xFF, lbl_8045C594);
    *(int*)(p + 0x00) = 0;
    *(int*)(p + 0x04) = 0;
    *(int*)(p + 0x08) = 0;
    *(int*)(p + 0x0C) = 0;
    *(int*)(p + 0x14) = 0;
    *(int*)(p + 0x18) = 0;
    *(char*)(p + 0x1C) = 0;
    *(int*)(p + 0x20) = 0;
    return self;
}
}