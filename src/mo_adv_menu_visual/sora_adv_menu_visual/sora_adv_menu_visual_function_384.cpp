#pragma force_active on
typedef unsigned char u8;

struct Pad5C {
    u8 pad[0x5C];
};

class VObj : public Pad5C {
public:
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_29_data_1C4[];
void free__13gfHeapManagerFPv(void*);
void fn_800B8A0C(void*, int);
void cancelRequest__14gfFileIOHandleFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void fn_29_2B8(void*, int);
void fn_29_344(void*, int);
}

extern "C" void* fn_29_384(u8* self, int deleting) {
    if (self) {
        *reinterpret_cast<void**>(self + 0x3C) = lbl_29_data_1C4;

        u8* cursor = self;
        for (int i = 0; i < 0x1A; ++i, cursor += 4) {
            VObj* obj = *reinterpret_cast<VObj**>(cursor + 0x4C);
            if (obj) {
                obj->f0(1);
            }
        }

        if (*reinterpret_cast<void**>(self + 0x40)) {
            free__13gfHeapManagerFPv(*reinterpret_cast<void**>(self + 0x40));
        }
        if (*reinterpret_cast<void**>(self + 0x44)) {
            free__13gfHeapManagerFPv(*reinterpret_cast<void**>(self + 0x44));
        }
        if (*reinterpret_cast<void**>(self + 0x48)) {
            free__13gfHeapManagerFPv(*reinterpret_cast<void**>(self + 0x48));
        }

        if (*reinterpret_cast<void**>(self + 0x34C)) {
            fn_800B8A0C(*reinterpret_cast<void**>(self + 0x34C), 1);
        }

        cursor = self + 0x358;
        for (int i = 0; i < 3; ++i, cursor += 4) {
            cancelRequest__14gfFileIOHandleFv(cursor);
        }

        __destroy_arr(self + 0x358, fn_29_2B8, 4, 3);
        __destroy_arr(self + 0xBC, fn_29_344, 0xD8, 2);
        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
