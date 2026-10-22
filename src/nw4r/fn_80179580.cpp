#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
float fn_80179580(void* arg0) {
    u8* p = (u8*)arg0;
    u8* r5 = *(u8**)(p + 0xC8);
    u8* r4 = *(u8**)(r5 + 0x24);
    u16 v = *(u16*)(r4 + 0x9C) & 0x6000;
    float f;

    switch (v) {
    case 0x4000:
        f = *(float*)(p + 0x34) * *(float*)(p + 0x38);
        break;
    case 0x2000:
        f = *(float*)(p + 0x30) * *(float*)(p + 0x3C);
        break;
    case 0x6000:
        f = *(float*)(p + 0x30) * *(float*)(p + 0x38);
        break;
    default:
        f = *(float*)(p + 0x34) * *(float*)(p + 0x3C);
        break;
    }
    return f * *(float*)(r5 + 0x5C);
}
}
