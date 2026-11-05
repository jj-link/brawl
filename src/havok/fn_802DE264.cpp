#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);

struct ParseInfo {
    s32 total;
    s32 storage;
    s32 extra;
    s32 count;
    void* data;
    s32 size;
};

extern "C" void fn_802DE264(char* p, s32 size, ParseInfo* out)
{
    out->data = p;
    out->size = size;
    out->total = 0;
    out->storage = 0;
    out->count = 0;
    out->extra = 0x18;

    if ((s8)((u32)__cntlzw(*(u16*)p - 0x16) >> 5)) {
        u16 n = *(u16*)(p + 4);
        out->count = n + 2;
        out->total = n * 0x30 + 0x80;
        out->storage = n * 0x30 + 0x60;
        out->extra = n * 4 + 0x30;
        if ((s32)n >= 2) {
            out->storage += 0x20;
            out->extra += 4;
            out->count += 1;
        }
        return;
    }

    char* end = p + size;
    while (p < end) {
    again:
        switch (*(u16*)p) {
        case 0:
            p = (char*)(((u32)p + 0xf) & ~0xf);
            goto again;
        case 5:
            p += 2;
            out->extra += 0xc;
            out->storage += 0x90;
            out->count += 3;
            break;
        case 6:
            p += 8;
            out->extra += 4;
            out->storage += 0x30;
            out->count += 1;
            break;
        case 7:
            p += 4;
            out->extra += 4;
            out->storage += 0x30;
            out->count += 1;
            break;
        case 8:
            p += 0xc;
            out->extra += 0xc;
            out->storage += 0x30;
            out->count += 1;
            break;
        case 9:
            p += 0xc;
            out->extra += 0xc;
            out->storage += 0x30;
            out->count += 1;
            break;
        case 10:
            p += 8;
            out->extra += 0xc;
            out->storage += 0x30;
            out->count += 1;
            break;
        case 11:
            p += 0x10;
            out->extra += 0x1c;
            out->storage += 0x30;
            out->count += 1;
            break;
        case 12:
            p += 4;
            out->extra += 8;
            out->storage += 0x40;
            out->count += 2;
            break;
        case 13: {
            u8 n = p[3];
            p += 4;
            out->extra += n * 4;
            out->storage += n << 5;
            out->count += n;
            break;
        }
        case 14:
            p += 0x10;
            out->extra += 0x10;
            out->storage += 0x20;
            out->count += 1;
            break;
        case 16:
            p += 0x14;
            out->extra += 0x10;
            out->storage += 0x20;
            out->count += 1;
            break;
        case 15:
            p += 0x14;
            out->extra += 0x10;
            out->storage += 0x20;
            out->count += 1;
            break;
        case 17: {
            u8 n = p[4];
            p += 0xc;
            out->extra += n * 0xc;
            out->storage += n << 5;
            out->count += n;
            break;
        }
        case 18:
            p += 0x14;
            out->extra += 0x1c;
            out->storage += 0x20;
            out->count += 1;
            break;
        case 19:
            p += 0x50;
            out->extra += 0x54;
            out->storage += 0x60;
            out->count += 3;
            break;
        case 20:
            p += 0x40;
            out->extra += 0xc;
            out->storage += 0x40;
            out->count += 1;
            break;
        case 2:
            p += 0x90;
            break;
        case 4:
            p += 0x70;
            break;
        case 3:
            p += 0x30;
            break;
        case 1:
        case 23:
        case 24:
        case 25:
        case 26:
            p = end;
            break;
        }
    }
}
