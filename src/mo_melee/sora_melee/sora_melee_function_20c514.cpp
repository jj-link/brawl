#pragma force_active on
extern "C" bool fn_27_20C514(void* self) {
    if (*(unsigned char*)((char*)self + 0xC0) == 0) {
        void* ptr = *(void**)((char*)self + 0xBC);
        if ((*(unsigned int*)((char*)ptr + 0x40) & 0x20) != 0) {
            return true;
        }
    }
    return false;
}
