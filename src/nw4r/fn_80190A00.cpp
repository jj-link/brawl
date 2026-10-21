#pragma force_active on
extern "C" void* fn_80190A00(void** arg0) {
    void* obj = *arg0;
    int offset = *(int*)((char*)obj + 4);
    if (offset != 0) {
        return (char*)obj + offset;
    }
    return 0;
}
