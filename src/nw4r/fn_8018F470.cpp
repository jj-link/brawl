#pragma force_active on
extern "C" void* fn_8018F470(void** arg) {
    void* p = *arg;
    int offset = *(int*)((char*)p + 0x30);
    void* result;
    if (offset != 0) {
        result = (char*)p + offset;
    } else {
        result = 0;
    }
    if (result != 0) {
        return *(void**)((char*)result + 4);
    }
    return 0;
}
