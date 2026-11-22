#include <types.h>
#include <revolution/CX/CXCompression.h>
#pragma force_active on
#define bswap32(x) ((((x) << 24) | (((x) << 8) & 0xff0000)) | (((x) >> 24) | (((x) >> 8) & 0xff00)))
void CXUncompressLZ(void* srcp, void* destp) {
    int mode;
    u8* in = (u8*)srcp + 4;
    u32 remaining = bswap32(*(u32*)srcp) >> 8;
    u8* dst = (u8*)destp;
    mode = (in[-4] & 15) != 0;
    if (remaining == 0) {
        remaining = bswap32(*(u32*)in);
        in += 4;
    }
    while (remaining != 0) {
        u32 flags = *in++;
        int i;
        for (i = 0; i < 8; i++) {
            if (!(flags & 0x80)) {
                *dst++ = *in++;
                remaining--;
            } else {
                s32 length = *in >> 4;
                u32 distance;
                if (!mode) {
                    length += 3;
                } else if (length == 1) {
                    length = ((in[0] & 15) << 12) | (in[1] << 4);
                    in += 2;
                    length |= *in >> 4;
                    length += 0x111;
                } else if (length == 0) {
                    length = ((in[0] & 15) << 4) | (in[1] >> 4);
                    in++;
                    length += 0x11;
                } else {
                    length++;
                }
                distance = (in[1] | ((in[0] & 15) << 8)) + 1;
                in += 2;
                if (length > remaining) length = remaining;
                remaining -= length;
                do {
                    length--;
                    *dst = *(dst - distance);
                    dst++;
                } while (length > 0);
            }
            if (remaining == 0) break;
            flags <<= 1;
        }
    }
}
