#pragma force_active on

typedef unsigned char u8;

class MenuObject {
    char pad[0x5C];

public:
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_2_data_12B8[];
extern u8 fn_2_647C[];
extern int lbl_2_bss_38;

void exit__6gfTaskFv(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void fn_800B8A0C(void*, int);
void cancelRequest__14gfFileIOHandleFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_2_89F8(u8* object, int deleting) {
    if (object) {
        void* p0 = *(void**)(object + 0x298);
        *(void**)(object + 0x3C) = lbl_2_data_12B8;
        if (p0) {
            exit__6gfTaskFv(p0);
        }

        void* p1 = *(void**)(object + 0x29C);
        if (p1) {
            Destroy__Q34nw4r3g3d6G3dObjFv(p1);
        }

        u8* cursor = object;
        for (int i = 0; i < 7; ++i, cursor += 4) {
            void* p = *(void**)(cursor + 0x168);
            if (p) {
                Destroy__Q34nw4r3g3d6G3dObjFv(p);
            }
        }

        cursor = object;
        for (int i = 0; i < 0x20; ++i, cursor += 4) {
            MenuObject* p = *(MenuObject**)(cursor + 0xE8);
            if (p && p) {
                p->f0(1);
            }
        }

        void* q;
        q = *(void**)(object + 0x9C);
        if (q) free__13gfHeapManagerFPv(q);
        q = *(void**)(object + 0xA4);
        if (q) free__13gfHeapManagerFPv(q);
        q = *(void**)(object + 0xA8);
        if (q) free__13gfHeapManagerFPv(q);
        q = *(void**)(object + 0xAC);
        if (q) free__13gfHeapManagerFPv(q);
        q = *(void**)(object + 0xB0);
        if (q) free__13gfHeapManagerFPv(q);
        q = *(void**)(object + 0xE4);
        if (q) free__13gfHeapManagerFPv(q);

        cursor = object;
        for (int i = 0; i < 4; ++i, cursor += 4) {
            void* p = *(void**)(cursor + 0xB4);
            if (p) free__13gfHeapManagerFPv(p);
        }

        q = *(void**)(object + 0xDC);
        if (q) free__13gfHeapManagerFPv(q);
        q = *(void**)(object + 0xE0);
        if (q) free__13gfHeapManagerFPv(q);

        q = *(void**)(object + 0x184);
        if (q) exit__6gfTaskFv(q);
        q = *(void**)(object + 0x188);
        if (q) exit__6gfTaskFv(q);

        q = *(void**)(object + 0x18C);
        if (q) Destroy__Q34nw4r3g3d6G3dObjFv(q);

        q = *(void**)(object + 0xD4);
        if (q) {
            free__13gfHeapManagerFPv(*(void**)((u8*)q + 4));
            fn_800B8A0C(*(void**)(object + 0xD4), 1);
        }

        cursor = object;
        for (int i = 0; i < 4; ++i, cursor += 4) {
            free__13gfHeapManagerFPv(*(void**)(cursor + 0x2A0));
        }

        cursor = object;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            free__13gfHeapManagerFPv(*(void**)(cursor + 0x2B0));
        }

        cursor = object + 0x264;
        for (int i = 0; i < 0xC; ++i, cursor += 4) {
            cancelRequest__14gfFileIOHandleFv(cursor);
        }

        lbl_2_bss_38 = 0;
        __destroy_arr(object + 0x264, (void (*)(void*, int))fn_2_647C, 4, 0xC);
        __dt__6gfTaskFv(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
