#pragma force_active on
extern "C" {
extern char* g_gfApplication;
extern char* g_gfSceneRoot;
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
void fn_8000D7B8(void*);
int fn_1_192E8(void* self);

int fn_1_7E08(char* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    if (*(char**)(self + 0x104) == 0) {
        return 0;
    }
    exit__6gfTaskFv(**(void***)(self + 0x104));
    exit__6gfTaskFv(*(void**)(*(char**)(self + 0x104) + 0x4));
    free__13gfHeapManagerFPv(*(void**)(self + 0x104));
    *(void**)(self + 0x104) = 0;
    fn_8000D7B8(g_gfSceneRoot);
    fn_1_192E8(self);
    return 0;
}
}
