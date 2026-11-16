#pragma force_active on
typedef unsigned char u8;

class Counter {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void method(int);

    u8 pad[0xE0];
    int count;
};

class Entry2 {
    u8 pad[0x5C];

public:
    virtual void method(int);
};

extern "C" {
extern u8 lbl_4_data_1058[];

void free__13gfHeapManagerFPv(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_4_4718(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_4_6844(u8* object, int deleting) {
    if (object) {
        *(void**)(object + 0x3C) = lbl_4_data_1058;

        Counter* obj = *(Counter**)(*(u8**)(object + 0x40) + 0x48);
        int n;
        while ((n = obj->count) != 0) {
            if (n != 0)
                obj->method(n - 1);
        }

        if (*(void**)(object + 0x1210))
            free__13gfHeapManagerFPv(*(void**)(object + 0x1210));
        if (*(void**)(object + 0x1214))
            free__13gfHeapManagerFPv(*(void**)(object + 0x1214));

        u8* cursor = object;
        for (unsigned int i = 0; i < 0x21; ++i, cursor += 4) {
            void* entry = *(void**)(cursor + 0x1308);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
                *(void**)(cursor + 0x1308) = 0;
            }
        }

        unsigned int i2 = 0;
        u8* cursor2 = object;
        for (; i2 < 0x3C; ++i2, cursor2 += 4) {
            Entry2* entry = *(Entry2**)(cursor2 + 0x1218);
            if (entry) {
                if (entry) {
                    entry->method(1);
                }
                *(void**)(cursor2 + 0x1218) = 0;
            }
        }

        fn_800B8A0C(*(void**)(object + 0x4C), 1);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x1394));
        release__14gfFileIOHandleFv(object + 0x1394);
        fn_800B8A0C(*(void**)(object + 0x50), 1);
        exit__6gfTaskFv(*(void**)(object + 0x138C));
        *(void**)(object + 0x138C) = 0;
        exit__6gfTaskFv(*(void**)(object + 0x40));
        *(void**)(object + 0x40) = 0;

        __destroy_arr(object + 0x1394, __dt__14gfFileIOHandleFv, 4, 3);
        __destroy_arr(object + 0x54, fn_4_4718, 0xE8, 0x10);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0)
            __dl__FPv(object);
    }

    return object;
}
}
