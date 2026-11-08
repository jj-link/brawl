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

extern "C" s32 fn_2_5B90(TrophiesPage* self, s32 arg1, s32 arg2) {
    s32 count = self->count;
    if (count != 0) {
        if (arg1 != 0) {
            s32 flag = self->flag;
            s32 newCount = count - 1;
            self->count = newCount;
            if (flag == 0) {
                self->result = getFigListSeries__20tyFigListDataManagerFlUlPUl(self->mgr, self->page, (u32)newCount, self->figList);
            } else {
                self->result = getFigListKind__20tyFigListDataManagerFlUlPUl(self->mgr, self->page + 0x17, (u32)newCount, self->figList);
            }
            if (arg2 != 0) {
                self->cursor = 0;
            } else {
                self->cursor = self->cursor + 2;
            }
            playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1ee8, -1, 0, 0, -1);
        }
        return 1;
    }
    s32 page;
    s32 result;
    u32 R;
    u32 C;
    if (self->flag == 0) {
        page = self->page;
        while (page > 0) {
            result = getPageNumSeries__20tyFigListDataManagerFl(self->mgr, page - 1);
            if (result != 0) {
                if (arg1 != 0) {
                    s32 newPage = page - 1;
                    s32 newCount = result - 1;
                    self->saved = result;
                    self->page = newPage;
                    self->count = newCount;
                    R = getFigListSeries__20tyFigListDataManagerFlUlPUl(self->mgr, newPage, (u32)newCount, self->figList);
                    self->result = R;
                    if (arg2 != 0) {
                        self->cursor = 0;
                    } else {
                        C = (u32)self->cursor;
                        for (;;) {
                            if (R > C + 2) {
                                self->cursor = C + 2;
                                break;
                            }
                            if (R > C) {
                                self->cursor = C + (R % 3) - 1;
                                break;
                            }
                            C -= 3;
                        }
                    }
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1ee8, -1, 0, 0, -1);
                }
                return 1;
            }
            page--;
        }
    } else {
        page = self->page;
        while (page > 0) {
            result = getPageNumKind__20tyFigListDataManagerFl(self->mgr, page + 0x16);
            if (result != 0) {
                if (arg1 != 0) {
                    s32 newPage = page - 1;
                    s32 newCount = result - 1;
                    self->saved = result;
                    self->page = newPage;
                    self->count = newCount;
                    R = getFigListKind__20tyFigListDataManagerFlUlPUl(self->mgr, newPage + 0x17, (u32)newCount, self->figList);
                    self->result = R;
                    if (arg2 != 0) {
                        self->cursor = 0;
                    } else {
                        C = (u32)self->cursor;
                        for (;;) {
                            if (R > C + 2) {
                                self->cursor = C + 2;
                                break;
                            }
                            if (R > C) {
                                self->cursor = C + (R % 3) - 1;
                                break;
                            }
                            C -= 3;
                        }
                    }
                    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1ee8, -1, 0, 0, -1);
                }
                return 1;
            }
            page--;
        }
    }
    return 0;
}