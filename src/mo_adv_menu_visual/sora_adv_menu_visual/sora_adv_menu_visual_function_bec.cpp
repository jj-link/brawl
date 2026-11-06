#include <gf/gf_file_io_handle.h>
#pragma force_active on
typedef unsigned char u8;
struct Entry { char data[0xd8]; };
struct Menu {
    char pad0[0xb4];
    int state;
    int previous;
    Entry entries[2];
    char pad1[0x344 - 0x26c];
    int flag;
    char pad2[0x358 - 0x348];
    gfFileIOHandle handles[3];
    u8 ready;
    char pad3[3];
    int value;
};
struct StateEntry {
    void (*enter)(Menu*);
    int (*update)(Menu*);
};
extern "C" {
extern StateEntry lbl_29_rodata_0[];
void fn_29_4C8(Menu*);
void fn_29_D84(Menu*, int);
void fn_800B9984(void*);
int fn_800BA3D8(void*);
void fn_801AC758(void*);
void fn_8000DB40(void*, int);
extern void* g_gfSceneRoot;
}
static inline bool allReady(Menu* self) {
    gfFileIOHandle* handle = self->handles;
    for (int i = 0; i < 3; ++i, ++handle) {
        if (!handle->isReady()) return false;
    }
    return true;
}
extern "C" void fn_29_BEC(Menu* self) {
    if (!self->ready) {
        if (!allReady(self)) return;
        fn_29_4C8(self);
        self->ready = 1;
        self->flag = 1;
        if (self->value == 0xffff) self->state = 2;
    }
    Entry* entry = self->entries;
    int j;
    Entry* p = entry;
    for (int i = 0; i < 2; ++i, ++p) fn_800B9984(p);
    int state = self->state;
    if (self->previous != state) {
        void (*enter)(Menu*) = lbl_29_rodata_0[state].enter;
        if (enter) enter(self);
        self->previous = self->state;
    }
    int (*update)(Menu*) = lbl_29_rodata_0[self->state].update;
    if (update) self->state = update(self);
    for (j = 0; j < 2; ++j, ++entry) {
        if ((((unsigned int)fn_800BA3D8(entry) >> 31) ^ 1) != 0) fn_29_D84(self, j);
    }
    void* root = g_gfSceneRoot;
    fn_801AC758(*(void**)((char*)root + 0x44));
    fn_8000DB40(root, 8);
}