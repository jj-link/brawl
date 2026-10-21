#pragma force_active on
typedef unsigned short u16;

int fn_803D6D8C(void* arg0) {
    return (((u16*)((char*)arg0 + 0x1f8c))[0] >> 5) & 1;
}
