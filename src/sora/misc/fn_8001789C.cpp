#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;

extern "C" {
u64 OSGetTime(void);
void fn_80023AE4(void*);
void fn_800374DC(int, void*);
void fn_801B5AC8(void);
void fn_801F0248(void);
void fn_801F0A30(void);
void fn_801F0AF0(void);
void fn_801F1564(int, int, int, int);
void fn_801F15C8(int, int, int, int);
void fn_801F1E60(int, int);
void fn_801F3194(void);
void process__14gfCallBackListFv(void*);
void renderPre__15gfTaskSchedulerFv(void*);
void render__15gfTaskSchedulerFv(void*);
void render__17gfKeepFrameBufferFv(void*);
void update__17gfKeepFrameBufferFv(void*);
extern int g_gfHomeMenu;
}

extern "C" void fn_8001789C(u8* self) {
    update__17gfKeepFrameBufferFv(self + 0xD0);
    u8* p = *(u8**)(self + 0xE0);
    if (p != 0) {
        p[0x350] = p[0x350] | 0x40;
        u64 t = OSGetTime();
        u8* q = *(u8**)(self + 0xE0);
        *(u32*)(q + 0x34C) = (u32)t;
        *(u32*)(q + 0x348) = (u32)(t >> 32);
        fn_801F0A30();
        p = *(u8**)(self + 0xE0);
        p[0x350] = p[0x350] & ~0x40;
    } else {
        fn_801F0A30();
    }
    renderPre__15gfTaskSchedulerFv(*(void**)(self + 0xD8));
    fn_801B5AC8();
    fn_801F0248();
    fn_801F3194();
    fn_80023AE4(self + 0x58);
    process__14gfCallBackListFv(self + 0x114);
    render__15gfTaskSchedulerFv(*(void**)(self + 0xD8));
    process__14gfCallBackListFv(self + 0x118);
    if ((self[0xED] >> 1) & 1) {
        if (*(int*)(self + 0x10C) != 0) {
            fn_801F0A30();
            int handle = *(int*)(self + 0x10C);
            fn_801F1564(0, 0, 0x280, 0x1E0);
            fn_801F15C8(0x280, 0x1E0, 6, 0);
            fn_801F1E60(handle, 1);
            fn_801F0AF0();
            fn_801F3194();
            *(int*)(self + 0x10C) = 0;
        }
        self[0xED] = self[0xED] & ~2;
    }
    render__17gfKeepFrameBufferFv(self + 0xD0);
    fn_800374DC(g_gfHomeMenu, self + 0x58);
}
