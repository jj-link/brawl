#pragma force_active on
extern "C" void* fn_27_351D7C(void* p1, void*, int p3) {
    int index = p3 - *(int*)((char*)p1 + 0x18);
    return *(void**)((char*)p1 + index * 4 + 0x2C);
}
