#pragma force_active on
typedef unsigned int u32;
extern "C" void* getEntity__14ftEntryManagerFUl(u32);
extern "C" u32 fn_27_10B050(void* __restrict self)
{
    void* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    return *(u32*)((char*)*(void**)((char*)entry + 0x28) + 0xD58);
}
