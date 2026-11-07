#include <ty/ty_fig_listmng.h>
#include <types.h>
#pragma force_active on

struct FigListMenu {
    char pad0[0x40];
    int state;
    int result;
    char pad48[4];
    tyFigListDataManager* mgr;
    u32 list[12];
    char pad80[0x128-0x80];
    int selection;
    u32 category;
    int group;
    int pages;
    u32 page;
    u32 count;
    u32 cursor;
    char pad144[4];
    void* object;
    void* controller;
    char pad150[0x20c-0x150];
};

extern "C" void fn_2_5178(FigListMenu*);
extern "C" void fn_2_6050(FigListMenu*, u32, s32);

extern "C" void fn_2_6050(FigListMenu* self, u32 id, s32 arg2) {
    tyFigListData* data = &self->mgr->m_data[id];
    self->selection = 2;
    self->category = (u32)arg2;

    if (arg2 == 0) {
        self->group = data->series;
        self->pages = (int)self->mgr->getPageNumSeries(data->series);
        u32 i = 0;
        while (i < (u32)self->pages) {
            u32 count = self->mgr->getFigListSeries(data->series, i, self->list);
            for (u32 j = 0; j < count; j++) {
                if (self->list[j] == id) {
                    self->count = count;
                    self->page = i;
                    self->cursor = j;
                    fn_2_5178(self);
                    return;
                }
            }
            i++;
        }
        fn_2_6050(self, self->mgr->nextIdSeries(id), arg2);
    } else {
        self->group = data->kind - 0x17;
        self->pages = (int)self->mgr->getPageNumKind(data->kind);
        u32 i = 0;
        while (i < (u32)self->pages) {
            u32 count = self->mgr->getFigListKind(data->kind, i, self->list);
            for (u32 j = 0; j < count; j++) {
                if (self->list[j] == id) {
                    self->count = count;
                    self->page = i;
                    self->cursor = j;
                    fn_2_5178(self);
                    return;
                }
            }
            i++;
        }
        fn_2_6050(self, self->mgr->nextIdKind(id), arg2);
    }
}