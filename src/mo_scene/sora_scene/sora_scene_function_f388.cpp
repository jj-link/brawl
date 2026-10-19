#pragma force_active on
typedef unsigned char u8;

struct Scene {
    u8 padding[0x378];
    void* h378;
    void* h37C;
    void* h380;
    void* h384;
    void* h388;
    void* h38C;
};

extern "C" {
void fn_25_11B4(void*);
void fn_25_2A74(void*);
void fn_24_1EC4(void*);
void fn_24_1650(void*);
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_1_406C(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void fn_1_F388(Scene* self) {
    if (self->h380) {
        fn_25_11B4(self->h380);
        exit__6gfTaskFv(self->h380);
        self->h380 = 0;
    }
    if (self->h384) {
        fn_25_2A74(self->h384);
        exit__6gfTaskFv(self->h384);
        self->h384 = 0;
    }
    if (self->h388) {
        fn_24_1EC4(self->h388);
        exit__6gfTaskFv(self->h388);
        self->h388 = 0;
    }
    if (self->h38C) {
        fn_24_1650(self->h38C);
        exit__6gfTaskFv(self->h38C);
        self->h38C = 0;
    }
    if (self->h378) {
        __dt__9gfArchiveFv(self->h378, 1);
        self->h378 = 0;
    }
    void* h = self->h37C;
    if (h) {
        if (h) {
            fn_1_406C(h);
            __dt__14gfFileIOHandleFv(h, -1);
            __dl__FPv(h);
        }
        self->h37C = 0;
    }
}
