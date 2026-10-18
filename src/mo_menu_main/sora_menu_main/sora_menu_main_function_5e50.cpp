#pragma force_active on
typedef long s32;
typedef unsigned long u32;

class tyFigListDataManager {
public:
    s32 getPageNumSeries(long page);
    u32 getFigListSeries(long page, unsigned long idx, unsigned long* out);
    s32 getPageNumKind(long page);
    u32 getFigListKind(long page, unsigned long idx, unsigned long* out);
};

struct FigListMenu {
    char pad0[0x4c];
    tyFigListDataManager* mgr; // 0x4c
    u32 unk50;                 // 0x50
    char pad1[0x12c - 0x54];
    s32 unk12c;
    s32 unk130;
    s32 unk134;
    u32 unk138;
    u32 unk13c;
    u32 unk140;
};

extern "C" {
int fn_2_5E50(FigListMenu* self, long r4, long r5) {
    long i;
    long n;
    s32 page;

    if (self->unk12c == 0) {
        if (r4 != 0) {
            for (i = self->unk130; i > 0; i--) {
                page = self->mgr->getPageNumSeries(i - 1);
                if (page != 0) {
                    if (r5 != 0) {
                        self->unk134 = page;
                        self->unk130 = i - 1;
                        self->unk138 = 0;
                        self->unk140 = 0;
                        self->unk13c = self->mgr->getFigListSeries(i - 1, 0, &self->unk50);
                    }
                    return 1;
                }
            }
        } else {
            for (i = self->unk130; i < 0x15; i++) {
                page = self->mgr->getPageNumSeries(i + 1);
                if (page != 0) {
                    if (r5 != 0) {
                        self->unk134 = page;
                        self->unk130 = i + 1;
                        self->unk138 = 0;
                        self->unk140 = 0;
                        self->unk13c = self->mgr->getFigListSeries(i + 1, 0, &self->unk50);
                    }
                    return 1;
                }
            }
        }
    } else {
        if (r4 != 0) {
            for (i = self->unk130; i > 0; i--) {
                page = self->mgr->getPageNumKind(i + 0x16);
                if (page != 0) {
                    if (r5 != 0) {
                        n = i - 1;
                        self->unk134 = page;
                        self->unk130 = n;
                        self->unk138 = 0;
                        self->unk140 = 0;
                        self->unk13c = self->mgr->getFigListKind(n + 0x17, 0, &self->unk50);
                    }
                    return 1;
                }
            }
        } else {
            for (i = self->unk130; i < 9; i++) {
                page = self->mgr->getPageNumKind(i + 0x18);
                if (page != 0) {
                    if (r5 != 0) {
                        n = i + 1;
                        self->unk134 = page;
                        self->unk130 = n;
                        self->unk138 = 0;
                        self->unk140 = 0;
                        self->unk13c = self->mgr->getFigListKind(n + 0x17, 0, &self->unk50);
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
}
