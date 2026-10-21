#pragma force_active on
extern "C" void* fn_801923B0(void* p) {
    void* self = *(void**)p;
    int offset = *(int*)((char*)self + 0x28);
    if (offset)
        return (char*)self + offset;
    return 0;
}
