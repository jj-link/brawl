#pragma force_active on
extern "C" {

struct StateEntry {
    void (*enter)(void*);
    int (*update)(void*);
};

struct Menu {
    char pad[0x1C8];
    int state;
    int previous;
};

struct SceneRoot {
    char pad[0x44];
    void* child;
};

extern const StateEntry lbl_32_rodata_0[];
extern SceneRoot* g_gfSceneRoot;
void fn_32_574(void* self);
void fn_8000DB40(void*, int);
void fn_800B9984(void*);
void fn_801AC758(void*);

void fn_32_4B0(Menu* self) {
    if (self->previous != self->state) {
        if (lbl_32_rodata_0[self->state].enter)
            lbl_32_rodata_0[self->state].enter(self);
        self->previous = self->state;
    }
    if (lbl_32_rodata_0[self->state].update)
        self->state = lbl_32_rodata_0[self->state].update(self);

    fn_800B9984((char*)self + 0x54);
    fn_800B9984((char*)self + 0xFC);
    fn_32_574(self);

    SceneRoot* root = g_gfSceneRoot;
    fn_801AC758(root->child);
    fn_8000DB40(root, 8);
}

}
