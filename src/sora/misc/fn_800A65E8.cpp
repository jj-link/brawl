#pragma force_active on
extern "C" void fn_800A65E8(void* arg0) {
    void* src = *(void**)arg0;
    *(float*)((char*)arg0 + 0x14) = *(float*)((char*)src + 0xcc);
    *(float*)((char*)arg0 + 0x18) = *(float*)((char*)src + 0x60);
    *(float*)((char*)arg0 + 0x1c) = *(float*)((char*)src + 0x64);
    *(float*)((char*)arg0 + 0x20) = *(float*)((char*)src + 0x68);
    *(float*)((char*)arg0 + 0x24) = *(float*)((char*)src + 0xd0);
    *(unsigned char*)((char*)arg0 + 0x10) |= 0x80;
}
