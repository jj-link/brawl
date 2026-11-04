#pragma force_active on
extern "C" int getFrameCount__16gfModelAnimationFd(char* self, double arg) {
    int result = 0;
    char* p = *(char**)(self + 0xC);
    if (p) {
        int n = *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C);
        result = n & ~(n >> 31);
    }
    p = *(char**)(self + 8);
    if (p) {
        result = result > *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C) ? result : *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C);
    }
    p = *(char**)(self + 0x10);
    if (p) {
        result = result > *(unsigned short*)(*(char**)(p + 0x2C) + 0x2C) ? result : *(unsigned short*)(*(char**)(p + 0x2C) + 0x2C);
    }
    p = *(char**)(self + 0x14);
    if (p) {
        result = result > *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C) ? result : *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C);
    }
    p = *(char**)(self + 0x18);
    if (p) {
        result = result > *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C) ? result : *(unsigned short*)(*(char**)(p + 0x2C) + 0x1C);
    }
    p = *(char**)(self + 0x1C);
    if (p) {
        result = result > *(unsigned short*)(*(char**)(p + 0x2C) + 0x20) ? result : *(unsigned short*)(*(char**)(p + 0x2C) + 0x20);
    }
    return result;
}