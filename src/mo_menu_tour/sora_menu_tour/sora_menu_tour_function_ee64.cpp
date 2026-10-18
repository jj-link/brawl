#pragma force_active on
extern "C" void* fn_3_EE64(void* arg) {
    void** field = *(void***)((char*)arg + 0x48);
    return *(void**)((char*)field + 4);
}