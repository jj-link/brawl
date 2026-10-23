#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 DVDReadPrio(void* fileInfo, void* addr, s32 length, s32 offset, s32 prio);

void fn_8015D1D8(u8* self, void* buf, s32 len) {
    s32 offset = *(s32*)(self + 0x18);
    s32 total = *(s32*)(self + 0x14);
    s32 end = (offset + len + 0x1f) & ~0x1f;
    s32 cap = (total + 0x1f) & ~0x1f;

    if ((u32)end > (u32)cap) {
        len = (total - offset + 0x1f) & ~0x1f;
    }
    DVDReadPrio(self + 0x28, buf, len, offset, *(s32*)(self + 0x68));
}
}
