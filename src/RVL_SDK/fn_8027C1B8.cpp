#include <types.h>
#include <revolution/DVD/dvdfs.h>
#pragma force_active on

class Stream {
public:
    virtual void s0();
    virtual void s1();
    virtual u32 isReady();
    u8 pad[0x40];
    s32 pos;
    s32 len;
};

extern "C" s32 fn_8027C1B8(Stream *self, void *buf, s32 size) {
    s32 off;
    s32 end;
    s32 n;

    if ((s8)(self->isReady() >> 24) != 0) {
        off = self->pos;
        end = self->len;
        if (off + size > end) {
            size = ((end - off) + 0x1F) & ~0x1F;
        }
        n = DVDReadPrio((DVDFileInfo *)((u8 *)self + 8), buf, size, off, 2);
        if (n >= 1) {
            self->pos = self->pos + n;
            return n;
        }
        self->pos = self->len + 1;
    }
    return 0;
}
