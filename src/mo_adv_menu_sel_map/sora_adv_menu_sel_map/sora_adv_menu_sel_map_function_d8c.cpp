#pragma force_active on
struct Menu {
    char pad0[0x40];
    int mode;
    char pad44[0x460];
    int state;
    int previous;
    char pad4AC[0x12C];
    void* resource;
};

struct StateEntry {
    void (*enter)(Menu*);
    int (*update)(Menu*);
};

extern "C" {
extern const StateEntry lbl_31_rodata_8[];
extern void* g_gfSceneRoot;

void fn_800B9984(void*);
int fn_1_3E50(void*);
int isLoadFinishMenuSound__6muMenuFv();
void fn_31_1064(Menu*);
void fn_8000DB40(void*, int);

void fn_31_D8C(Menu* self) {
    if (self->previous != self->state) {
        if (lbl_31_rodata_8[self->state].enter)
            lbl_31_rodata_8[self->state].enter(self);
        self->previous = self->state;
    }

    if (lbl_31_rodata_8[self->state].update)
        self->state = lbl_31_rodata_8[self->state].update(self);

    fn_800B9984((char*)self + 0x64);
    fn_800B9984((char*)self + 0x10C);

    if (fn_1_3E50(self->resource) && isLoadFinishMenuSound__6muMenuFv())
        fn_31_1064(self);

    if (self->mode != 2 && self->mode != 3 && self->mode != 4 &&
        self->mode != 5 && self->mode != 6)
        fn_8000DB40(g_gfSceneRoot, 8);
}
}
