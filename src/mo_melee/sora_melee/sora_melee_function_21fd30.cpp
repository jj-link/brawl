#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

extern "C" void* fn_27_21FD30(void* p, s32 key) {
    u32 count = *(u32*)((char*)p + 4);
    char* e = (char*)p;
    for (u32 i = 0; i < count; i++) {
        if (key == *(u16*)(e + 0x10)) {
            return (char*)p + i * 0x18 + 0x10;
        }
        e += 0x18;
    }
    return 0;
}
