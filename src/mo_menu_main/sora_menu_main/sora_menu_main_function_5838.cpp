#include <types.h>
#pragma force_active on

extern "C" {
u32 getFigListSeries__20tyFigListDataManagerFlUlPUl(void* a, s32 b, u32 c, u32* d);
u32 getFigListKind__20tyFigListDataManagerFlUlPUl(void* a, s32 b, u32 c, u32* d);
s32 getPageNumSeries__20tyFigListDataManagerFl(void* a, s32 b);
s32 getPageNumKind__20tyFigListDataManagerFl(void* a, s32 b);
void playSE__9sndSystemF5SndIDiiii(void* a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void* g_sndSystem;
}

struct TrophiesPage {
    char pad0[0x4c];
    void* mgr;            // 0x4c
    u32 figList[12];      // 0x50 .. 0x80
    char pad1[0xac];      // 0x80 .. 0x12c
    s32 flag;             // 0x12c
    s32 page;             // 0x130
    s32 saved;            // 0x134
    s32 count;            // 0x138
    s32 result;           // 0x13c
    s32 cursor;           // 0x140
};

extern "C" s32 fn_2_5838(TrophiesPage* self, s32 arg1, s32 arg2) {
    u32 newCount = (u32)self->count + 1;
    if ((u32)self->saved > newCount) {
        if (arg1 != 0) {
            u32 n;
            u32 k;
            self->count = (s32)newCount;
            if (self->flag == 0) {
                self->result = getFigListSeries__20tyFigListDataManagerFlUlPUl(self->mgr, self->page, newCount, self->figList);
            } else {
                self->result = getFigListKind__20tyFigListDataManagerFlUlPUl(self->mgr, self->page + 0x17, newCount, self->figList);
            }
            k = (u32)self->cursor / 3;
            if ((u32)self->result % 3 == 0) {
                n = (u32)self->result / 3 - 1;
            } else {
                n = (u32)self->result / 3;
            }
            self->cursor = 0;
            if (arg2 == 0) {
                u32 i = 0;
                while (i < n && i < k) {
                    i++;
                    self->cursor = self->cursor + 3;
                }
            }
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1ee8, -1, 0, 0, -1);
        }
        return 1;
    }
    if (self->flag == 0) {
        s32 page = self->page;
        while (page < 0x15) {
            s32 found = getPageNumSeries__20tyFigListDataManagerFl(self->mgr, page + 1);
            if (found != 0) {
                if (arg1 != 0) {
                    u32 r;
                    u32 n;
                    u32 k;
                    self->saved = found;
                    self->page = page + 1;
                    self->count = 0;
                    r = getFigListSeries__20tyFigListDataManagerFlUlPUl(self->mgr, page + 1, 0, self->figList);
                    self->result = (s32)r;
                    k = (u32)self->cursor / 3;
                    if (r % 3 == 0) {
                        n = r / 3 - 1;
                    } else {
                        n = r / 3;
                    }
                    self->cursor = 0;
                    if (arg2 == 0) {
                        u32 i = 0;
                        while (i < n && i < k) {
                            i++;
                            self->cursor = self->cursor + 3;
                        }
                    }
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1ee8, -1, 0, 0, -1);
                }
                return 1;
            }
            page++;
        }
    } else {
        s32 page = self->page;
        while (page < 9) {
            s32 found = getPageNumKind__20tyFigListDataManagerFl(self->mgr, page + 0x18);
            if (found != 0) {
                if (arg1 != 0) {
                    u32 r;
                    u32 n;
                    u32 k;
                    s32 np = page + 1;
                    self->saved = found;
                    self->page = np;
                    self->count = 0;
                    r = getFigListKind__20tyFigListDataManagerFlUlPUl(self->mgr, np + 0x17, 0, self->figList);
                    self->result = (s32)r;
                    k = (u32)self->cursor / 3;
                    if (r % 3 == 0) {
                        n = r / 3 - 1;
                    } else {
                        n = r / 3;
                    }
                    self->cursor = 0;
                    if (arg2 == 0) {
                        u32 i = 0;
                        while (i < n && i < k) {
                            i++;
                            self->cursor = self->cursor + 3;
                        }
                    }
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1ee8, -1, 0, 0, -1);
                }
                return 1;
            }
            page++;
        }
    }
    return 0;
}
