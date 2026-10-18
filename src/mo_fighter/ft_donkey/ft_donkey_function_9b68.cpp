#pragma force_active on
extern "C" void fn_92_9B68(void* self, void* value, unsigned int index) {
    void** arr = *(void***)((char*)self + 0xc);
    arr[index] = value;
}
