#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

void* fn_803A976C(void* dest, int value, u32 size)
{
    u8* p = (u8*)dest;
    u32 fill;

    while (((u32)p & 3) && size) {
        *p++ = value;
        --size;
    }

    fill = value | (value << 8) | ((value << 24) | (value << 16));

    while (size > 3) {
        *(u32*)p = fill;
        p += 4;
        size -= 4;
    }

    while (size--) {
        *p++ = value;
    }

    return dest;
}
