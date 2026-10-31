#pragma force_active on

typedef unsigned char u8;

extern "C" {
void** getInstance__12ntFriendInfoFv();
void fn_8014CB1C(void*, int);
void* memset(void*, int, unsigned int);
}

extern "C" u8* fn_800D26D0(void* self, int index, u8* src) {
    u8* cursor;
    int count;
    u8* dst;
    u8* base;

    base = (u8*)*getInstance__12ntFriendInfoFv();
    base += index * 0x89;
    dst = base + 0x581;
    memset(dst, 0, 0x89);
    cursor = src;
    count = 5;
    memset(dst, 0, 0x0A);
    goto check;

copy:
    {
        u8 value;
        u8 other;
        other = cursor[0];
        value = cursor[1];
        cursor += 2;
        dst[0] = other;
        int combined = (dst[1] = value) | other;
        dst += 2;
        if (combined == 0) {
            goto done;
        }
    }
check:
    count -= 1;
    if (count >= 0) {
        goto copy;
    }

done:
    fn_8014CB1C(getInstance__12ntFriendInfoFv(), 1);
    return src;
}
