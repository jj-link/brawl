#pragma force_active on
extern "C" void fn_27_112610(void* ptr, float value) {
    void* obj = *(void**)ptr;
    *(float*)((char*)obj + 0x49c) = value;
}
