#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_80062F60(void*, u32);

extern "C" void setVisibleGroup__5ecMgrFUlbUlUl(
    void* p, u32 flag, u32 group, u32 maskArg, u32 unused)
{
    u32 idx;
    char* ptr;
    char* cp = (char*)p;
    u32 mask = maskArg;

    if (*(u32*)(cp + 0x6C) != 0) {
        idx = *(u32*)(cp + 0x70);
        ptr = (char*)*(void**)(cp + 0x60) + idx * 0x84;

        if (group & 0xFF000000) {
            mask |= 0xFF000000;
        }

        u32 val = group & mask;
        while (idx <= *(u32*)(cp + 0x74)) {
            if (*(u32*)(ptr + 0x7C) != 0) {
                if ((*(u32*)(ptr + 0x78) & mask) == val) {
                    fn_80062F60(ptr, flag);
                }
            }
            idx++;
            ptr += 0x84;
        }
    }
}
