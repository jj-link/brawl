#pragma force_active on
extern "C" {
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void fn_8000D6DC(void*, void*);
extern void* g_gfSceneRoot;

void fn_800FB3B4(void* self) {
    char* p = (char*)self;
    if (*(void**)(p + 0x48)) {
        void* spC;
        void* sp8;
        spC = GetResAnmScn__Q34nw4r3g3d7ResFileFi(p + 0x48, 0);
        sp8 = spC;
        fn_801971D0(&spC, &sp8);
        fn_8000D6DC(g_gfSceneRoot, &spC);
    }
}
}
