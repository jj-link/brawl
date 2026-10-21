#pragma force_active on
extern "C" void fn_80154C60(void* self, int value, int idx) {
    *(int*)((char*)self + 0x378) = value;
    *(unsigned char*)((char*)self + 0x37C) = 1;
    if (idx == 6) {
        *(unsigned char*)((char*)self + 0x36C) = 1;
        return;
    }
    if (idx == 7) {
        *(unsigned char*)((char*)self + 0x36C) = 1;
    }
}
