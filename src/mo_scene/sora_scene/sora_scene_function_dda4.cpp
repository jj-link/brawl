#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" {
void fn_11_4D8(void*);
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
    u8 pad0[0x364];
    void* f364;
    u8 pad368[0x44];
    void* f3ac;
    u8 pad3b0[0x94];
    s32 f444;
    u8 f448;
    u8 f449, f44a, f44b, f44c;
    u8 pad44d[3];
    void* f450;
    void* f454;
};

inline void setColor(u8 r, u8 g, u8 b, u8 a) {
    u8* p = fn_80023AC8();
    p[0x2c] = r;
    p[0x2d] = g;
    p[0x2e] = b;
    p[0x2f] = a;
}

extern "C" s32 fn_1_DDA4(Scene* self) {
    if (self->f3ac) {
        fn_11_4D8(self->f3ac);
        self->f3ac = 0;
    }

    if (self->f364) {
        exit__6gfTaskFv(self->f364);
        self->f364 = 0;
    }

    if (self->f450) {
        __dt__9gfArchiveFv(self->f450, 1);
        self->f450 = 0;
    }

    void* h = self->f454;
    if (h) {
        if (h) {
            fn_1_406C(h);
            __dt__14gfFileIOHandleFv(h, -1);
            __dl__FPv(h);
        }
        self->f454 = 0;
    }

    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);

    if (self->f444 == 0) {
        setColor(self->f449, self->f44a, self->f44b, self->f44c);
    }

    return 0;
}
