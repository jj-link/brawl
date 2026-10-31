#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
void* fn_27_213A44(u8* p) {
    u8 first = *p;
    u8 cur;
    int count = (first == 8);
    u8 prev = 0;
    for (;;) {
        cur = *p;
        if ((u8)(cur + 0xFA) <= 1) {
            if (prev != 8) count++;
        }
        if (first != 8 && cur == 8 && count == 1) return p;
        if (cur == 9) {
            count--;
            if (count <= 0) return p;
        }
        p += *(u16*)(p + 2);
        prev = cur;
    }
}
}
