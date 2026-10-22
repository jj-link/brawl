#pragma force_active on
typedef unsigned char u8;

class Entry5C {
    u8 pad[0x5C];
public:
    virtual ~Entry5C();
};

class Entry1C {
    u8 pad[0x1C];
public:
    virtual ~Entry1C();
};

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void exit__6gfTaskFv(void*);
void fn_10_1B8B4(void*, int);
void fn_800B8A0C(void*, int);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
void* fn_10_3F4(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

void* fn_10_10EF8(void* object, int deleting) {
    if (object) {
        void* ptr = *reinterpret_cast<void**>((u8*)object + 0x1AC);
        if (ptr) {
            fn_10_1B8B4(ptr, 1);
        }

        void* task1 = *reinterpret_cast<void**>((u8*)object + 0x1A8);
        if (task1) {
            exit__6gfTaskFv(task1);
        }

        void* task2 = *reinterpret_cast<void**>((u8*)object + 0x150);
        if (task2) {
            exit__6gfTaskFv(task2);
            *reinterpret_cast<void**>((u8*)object + 0x150) = 0;
        }

        u8* cursor = (u8*)object;
        for (int i = 0; i < 2; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x404);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
            }
        }

        cursor = (u8*)object;
        for (int i = 0; i < 0x28; ++i, cursor += 4) {
            Entry5C* entry = *reinterpret_cast<Entry5C**>(cursor + 0xB0);
            if (entry) {
                delete entry;
            }
        }

        Entry1C* special = *reinterpret_cast<Entry1C**>((u8*)object + 0x41C);
        if (special) {
            delete special;
        }

        void* obj40C = *reinterpret_cast<void**>((u8*)object + 0x40C);
        if (obj40C) {
            fn_800B8A0C(obj40C, 1);
        }

        void* heap = *reinterpret_cast<void**>((u8*)object + 0x438);
        if (heap) {
            free__13gfHeapManagerFPv(heap);
            *reinterpret_cast<void**>((u8*)object + 0x438) = 0;
        }

        __destroy_arr((u8*)object + 0x154, (void(*)(void*,int))fn_10_3F4, 0xC, 7);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}
