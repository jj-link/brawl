#pragma force_active on
extern "C" {

struct StateEntry {
    void (*enter)(void*);
    int (*update)(void*);
};

struct Menu {
    char pad[0x1368];
    int state;
    int previous;
};

extern const StateEntry lbl_26_rodata_0[];
extern void* g_gfSceneRoot;
void fn_8000DB40(void*, int);

void fn_26_7E0(Menu* self) {
    if (self->previous != self->state) {
        if (lbl_26_rodata_0[self->state].enter)
            lbl_26_rodata_0[self->state].enter(self);
        self->previous = self->state;
    }
    if (lbl_26_rodata_0[self->state].update)
        self->state = lbl_26_rodata_0[self->state].update(self);
    fn_8000DB40(g_gfSceneRoot, 8);
}

}
