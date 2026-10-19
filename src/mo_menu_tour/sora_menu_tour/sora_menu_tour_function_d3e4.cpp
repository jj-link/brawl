#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];

public:
    virtual ~MenuObject();
};

extern "C" {
extern u8 lbl_3_data_D00[];

void free__13gfHeapManagerFPv(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_3_D3E4(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_3_data_D00;

        if (*reinterpret_cast<void**>(object + 0x268))
            free__13gfHeapManagerFPv(*reinterpret_cast<void**>(object + 0x268));

        u8* cursor = object;
        for (unsigned int i = 0; i < 8; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x26C);
            if (entry)
                free__13gfHeapManagerFPv(entry);
        }

        cursor = object;
        for (unsigned int i = 0; i < 7; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x2D8);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
                *reinterpret_cast<void**>(cursor + 0x2D8) = 0;
            }
        }

        cursor = object;
        for (unsigned int i = 0; i < 19; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0x28C);
            if (entry) {
                delete entry;
                *reinterpret_cast<void**>(cursor + 0x28C) = 0;
            }
        }

        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x34C));
        release__14gfFileIOHandleFv(object + 0x34C);

        fn_800B8A0C(*reinterpret_cast<void**>(object + 0xFC), 1);
        fn_800B8A0C(*reinterpret_cast<void**>(object + 0x100), 1);

        exit__6gfTaskFv(*reinterpret_cast<void**>(object + 0x40));
        *reinterpret_cast<void**>(object + 0x40) = 0;
        exit__6gfTaskFv(*reinterpret_cast<void**>(object + 0x2F4));
        *reinterpret_cast<void**>(object + 0x2F4) = 0;

        __destroy_arr(object + 0x34C, __dt__14gfFileIOHandleFv, 4, 10);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0)
            __dl__FPv(object);
    }

    return object;
}
}
