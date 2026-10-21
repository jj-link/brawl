#pragma force_active on
extern "C" {

typedef void (*FnEnter)(void*);
typedef int (*FnUpdate)(void*);

struct StateEntry {
    FnEnter enter;
    FnUpdate update;
};

extern const StateEntry lbl_34_rodata_0[];
extern void fn_800B9984(void*);
extern int fn_1_3E50(void*);
extern int isLoadFinishMenuSound__6muMenuFv();
extern void fn_34_A04(void*);
extern void fn_8000DB40(void*, int);
extern void* g_gfSceneRoot;

void fn_34_934(void* self) {
    char* p = (char*)self;
    fn_800B9984(p + 0x4c);
    void* res = *(void**)(p + 0x5ac);
    if (fn_1_3E50(res) && isLoadFinishMenuSound__6muMenuFv()) {
        fn_34_A04(self);
    }
    int state = *(int*)(p + 0x1bc);
    int prev = *(int*)(p + 0x1c0);
    if (prev != state) {
        FnEnter enter = lbl_34_rodata_0[state].enter;
        if (enter) {
            enter(self);
        }
        *(int*)(p + 0x1c0) = *(int*)(p + 0x1bc);
    }
    FnUpdate update = lbl_34_rodata_0[*(int*)(p + 0x1bc)].update;
    if (update) {
        *(int*)(p + 0x1bc) = update(self);
    }
    fn_8000DB40(g_gfSceneRoot, 8);
}
}
