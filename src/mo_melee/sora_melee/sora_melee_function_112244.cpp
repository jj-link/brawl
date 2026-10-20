#pragma force_active on
extern "C" int fn_27_112244(void* ptr) {
    void* inner = *(void**)ptr;
    int* field = (int*)((char*)inner + 0x4b4);
    return *field;
}
