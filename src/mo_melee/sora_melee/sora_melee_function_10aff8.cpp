#pragma force_active on
typedef unsigned int u32;
extern "C" void* getEntity__14ftEntryManagerFUl(u32);
extern "C" char* fn_27_10AFF8(void* __restrict self)
{
    void* entry = getEntity__14ftEntryManagerFUl(*(u32*)((char*)self + 0x154));
    return (char*)*(void**)((char*)entry + 0x28) + 0xD54;
}
