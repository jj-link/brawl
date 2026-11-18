#pragma force_active on
typedef unsigned char u8;

struct Pad5C {
    u8 pad[0x5C];
};

class VObj5C : public Pad5C {
public:
    virtual void f0(int);
};

extern "C" {
extern u8 __vt__20muWifiTimeResultTask[];
extern void* g_gfSceneRoot;
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_8000D7B8(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_21_2CC(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = __vt__20muWifiTimeResultTask;

        u8* cursor = object;
        for (int i = 0; i < 1; ++i, cursor += 4) {
            VObj5C* obj = *reinterpret_cast<VObj5C**>(cursor + 0x40);
            if (obj && obj) {
                obj->f0(1);
            }
        }

        fn_8000D7B8(g_gfSceneRoot);

        cursor = object + 0x140;
        for (int i = 0; i < 5; ++i, cursor += 4) {
            free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(cursor));
            release__14gfFileIOHandleFv(cursor);
        }

        __destroy_arr(object + 0x140, __dt__14gfFileIOHandleFv, 4, 5);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
