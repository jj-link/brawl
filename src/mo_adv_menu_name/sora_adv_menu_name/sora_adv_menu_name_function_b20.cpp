#pragma force_active on
extern "C" {

struct StateEntry {
    void (*enter)(void*);
    int (*update)(void*);
};

struct SubMenu {
    char pad[0xB8];
};

struct Menu {
    char pad[0x168];
    int state;
    int previous;
    SubMenu subs[2];
};

struct SceneRoot {
    char pad[0x44];
    void* child;
};

extern const StateEntry lbl_28_rodata_0[];
extern SceneRoot* g_gfSceneRoot;
void fn_28_C04(void*);
void fn_8000DB40(void*, int);
void fn_800B9984(void*);
void fn_801AC758(void*);

void fn_28_B20(Menu* self) {
    if (self->previous != self->state) {
        if (lbl_28_rodata_0[self->state].enter)
            lbl_28_rodata_0[self->state].enter(self);
        self->previous = self->state;
    }
    if (lbl_28_rodata_0[self->state].update)
        self->state = lbl_28_rodata_0[self->state].update(self);

    for (int i = 0; i < 2; i++)
        fn_800B9984(&self->subs[i]);

    fn_28_C04(self);

    SceneRoot* root = g_gfSceneRoot;
    fn_801AC758(root->child);
    fn_8000DB40(root, 8);
}

}
