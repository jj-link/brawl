#pragma force_active on
typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];
public:
    virtual void method(int);
};

class Obj3B0 {
    u8 padding[0x3C];
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
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
};

extern "C" {
extern u8 lbl_4_data_774[];

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void release__14gfFileIOHandleFv(void*);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__14gfFileIOHandleFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_4_2128(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_4_data_774;

        u8* cursor = object;
        for (unsigned int i = 0; i < 6; ++i, cursor += 4) {
            void* entry = *reinterpret_cast<void**>(cursor + 0x358);
            if (entry) {
                Destroy__Q34nw4r3g3d6G3dObjFv(entry);
                *reinterpret_cast<void**>(cursor + 0x358) = 0;
            }
        }

        cursor = object;
        for (unsigned int i = 0; i < 0x23; ++i, cursor += 4) {
            MenuObject* entry = *reinterpret_cast<MenuObject**>(cursor + 0x2CC);
            if (entry) {
                if (entry) {
                    entry->method(1);
                }
                *reinterpret_cast<void**>(cursor + 0x2CC) = 0;
            }
        }

        __dt__9gfArchiveFv(*(void**)(object + 0x3B4), 1);
        __dt__9gfArchiveFv(*(void**)(object + 0x3B8), 1);

        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x3C4));
        release__14gfFileIOHandleFv(object + 0x3C4);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x3C8));
        release__14gfFileIOHandleFv(object + 0x3C8);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x3CC));
        release__14gfFileIOHandleFv(object + 0x3CC);
        free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(object + 0x3D0));
        release__14gfFileIOHandleFv(object + 0x3D0);

        fn_800B8A0C(*(void**)(object + 0xFC), 1);
        fn_800B8A0C(*(void**)(object + 0x100), 1);

        exit__6gfTaskFv(*(void**)(object + 0x370));
        *(void**)(object + 0x370) = 0;
        exit__6gfTaskFv(*(void**)(object + 0x40));
        *(void**)(object + 0x40) = 0;

        void* temp398 = *(void**)(object + 0x398);
        if (temp398) {
            exit__6gfTaskFv(temp398);
            *(void**)(object + 0x398) = 0;
        }

        Obj3B0* obj3B0 = *(Obj3B0**)(object + 0x3B0);
        if (obj3B0) {
            obj3B0->vf23();
            *(void**)(object + 0x3B0) = 0;
        }

        void* temp394 = *(void**)(object + 0x394);
        if (temp394) {
            exit__6gfTaskFv(temp394);
            *(void**)(object + 0x394) = 0;
        }

        __destroy_arr(object + 0x3C4, __dt__14gfFileIOHandleFv, 4, 4);
        __dt__6gfTaskFv(object, 0);

        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
}
