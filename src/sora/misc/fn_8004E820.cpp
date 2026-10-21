#pragma force_active on
extern "C" void fn_8004E820(void* self)
{
    void* obj = *(void**)((char*)self + 0x24);
    *(unsigned int*)((char*)obj + 0x268) |= 0x4;
}
