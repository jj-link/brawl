#pragma force_active on
extern "C" unsigned char fn_800C8548();

extern "C" int fn_800CF18C(unsigned char *arg0) {
    unsigned char index = fn_800C8548();
    unsigned char *ptr;
    if (index == 0xFF) {
        ptr = (unsigned char *)0;
    } else {
        int offset = index * 0x218;
        int addr = (int)arg0 + offset;
        ptr = (unsigned char *)(addr + 0x70);
    }
    if (ptr == (unsigned char *)0) {
        return 1;
    }
    int result = 0;
    int v;
    v = ptr[0x68]; if (v == 1) result = 1;
    v = ptr[0x69]; if (v == 1) result += 1;
    v = ptr[0x6A]; if (v == 1) result += 1;
    v = ptr[0x6B]; if (v == 1) result += 1;
    return result;
}
