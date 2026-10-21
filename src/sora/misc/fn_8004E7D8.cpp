#pragma force_active on
extern "C" void fn_8004E7D8(void* self)
{
    void* obj = *(void**)((char*)self + 0x24);
    unsigned int* field = (unsigned int*)((char*)obj + 0x268);
    *field |= 1;
}
