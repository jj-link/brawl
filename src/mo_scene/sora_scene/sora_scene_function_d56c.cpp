#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" {
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_1_406C(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern u8* g_gfApplication;
u8* fn_80023AC8();
}

struct Scene {
    u8 pad0[0x35C];
    void* f35c;
    u8 pad360[0x4C];
    void* f3ac;
    void* f3b0;
    u8 pad3b4[0x4C];
    void* f400;
    u8 pad404[0x5];
    u8 f409;
    u8 f40a;
    u8 f40b;
    u8 f40c;
    void* f410;
    void* f414;
    void* f418;
};

extern "C" s32 fn_1_D56C(Scene* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);

    u8 c31;
    u8 c30;
    u8 c29;
    u8 c28;
    c28 = self->f40c;
    c29 = self->f40b;
    c30 = self->f40a;
    c31 = self->f409;

    u8* p = fn_80023AC8();
    p[0x2C] = c31;
    p[0x2D] = c30;
    p[0x2E] = c29;
    p[0x2F] = c28;

    if (self->f400) {
        exit__6gfTaskFv(self->f400);
        self->f400 = 0;
    }

    if (self->f35c) {
        exit__6gfTaskFv(self->f35c);
        self->f35c = 0;
    }

    if (self->f3ac) {
        __dt__9gfArchiveFv(self->f3ac, 1);
        self->f3ac = 0;
    }

    if (self->f3b0) {
        __dt__9gfArchiveFv(self->f3b0, 1);
        self->f3b0 = 0;
    }

    if (self->f410) {
        __dt__9gfArchiveFv(self->f410, 1);
        self->f410 = 0;
    }

    void* h = self->f414;
    if (h) {
        if (h) {
            fn_1_406C(h);
            __dt__14gfFileIOHandleFv(h, -1);
            __dl__FPv(h);
        }
        self->f414 = 0;
    }

    void* g = self->f418;
    if (g) {
        if (g) {
            fn_1_406C(g);
            __dt__14gfFileIOHandleFv(g, -1);
            __dl__FPv(g);
        }
        self->f418 = 0;
    }

    return 0;
}
