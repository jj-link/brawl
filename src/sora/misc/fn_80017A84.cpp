#pragma force_active on
#include <gf/gf_task.h>
#include <gf/gf_archive.h>
#include <sr/sr_common.h>
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_80420A00[];
extern char lbl_80420B08[];
extern int lbl_8059C4B0;
extern gfArchive* lbl_8059FFB8;
}

struct ArchiveBlock {
    gfArchive a;
    gfArchive b;
    gfArchive c;
    gfArchive d;
    gfArchive e;
    char extra[8];
};

struct HighByte { unsigned int high : 8; unsigned int low : 24; };

struct Bits {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char rest : 6;
};

static inline void init(unsigned char* self) {
    self[0x40] |= 0x80;
    *(char**)(self + 0x3C) = lbl_80420B08;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 0;
    *(int*)(self + 0x4C) = 0;
    *(int*)(self + 0x50) = 0;
    *(int*)(self + 0x5C) = 0;
    ((HighByte*)(self + 0x64))->high = 0;
    *(int*)(self + 0x68) = 0;
    *(int*)(self + 0x6C) = 0;
    ((HighByte*)(self + 0x70))->high = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x7C) = lbl_8059C4B0;
    *(int*)(self + 0x80) = 0;
}

static inline void* construct(bool arg1, unsigned char* self) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_80420A00, 0, 0xE, 1, true);
    init(self);
    *(int*)(self + 0x60) = 0;
    *(unsigned int*)(self + 0x40) &= 0xC03FFFFF;
    ((Bits*)(self + 0x40))->b = arg1;
    self[0x42] = 0;
    *(int*)(self + 0x7C) = lbl_8059C4B0;
    *(int*)(self + 0x80) = 0;
    ArchiveBlock* temp = new (Heaps::ItemResource) ArchiveBlock;
    lbl_8059FFB8 = (gfArchive*)temp;
    return self;
}

extern "C" void* fn_80017A84(unsigned char* self, bool arg1) {
    return construct(arg1, self);
}
