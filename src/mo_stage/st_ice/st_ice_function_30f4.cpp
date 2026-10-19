#pragma force_active on
extern "C" int fn_62_30F4(void* arg) {
    unsigned char b = *(unsigned char*)((char*)arg + 0x6c);
    return (b >> 3) & 1;
}
