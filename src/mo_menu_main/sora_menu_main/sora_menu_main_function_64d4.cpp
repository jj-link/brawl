#pragma force_active on

typedef unsigned char u8;
typedef int s32;

class MenuObject {
    char pad[0x5C];
public:
    virtual void f0(int);
};

extern "C" {
extern u8 lbl_2_data_DB8[];
extern void* g_sndSystem;

void fn_80075F1C(void*, int, int);
void fn_2_647C(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dt__9gfArchiveFv(void*, int);
void __dl__FPv(void*);

void* fn_2_64D4(u8* object, int arg1) {
    if (object) {
        s32 p0 = *(s32*)(object + 0x704);
        *(void**)(object + 0x3C) = lbl_2_data_DB8;
        if (p0 >= 0) {
            fn_80075F1C(g_sndSystem, p0, 0);
        }

        if (*(void**)(object + 0x40)) {
            for (int i = 0; i < 2; ++i) {
                void* p = *(void**)(*(u8**)(object + 0x40) + i * 4 + 0x1578);
                if (p) {
                    Destroy__Q34nw4r3g3d6G3dObjFv(p);
                }
            }

            void* p = *(void**)(*(u8**)(object + 0x40) + 0x1630);
            if (p) {
                Destroy__Q34nw4r3g3d6G3dObjFv(p);
            }

            for (int i = 0; i < 0x519; ++i) {
                MenuObject* m = *(MenuObject**)(*(u8**)(object + 0x40) + i * 4 + 0x114);
                if (m && m) {
                    m->f0(1);
                }
            }

            void* q = *(void**)(*(u8**)(object + 0x40) + 4);
            if (q) free__13gfHeapManagerFPv(q);
            q = *(void**)(*(u8**)(object + 0x40) + 0x10C);
            if (q) free__13gfHeapManagerFPv(q);
            q = *(void**)(*(u8**)(object + 0x40) + 0x110);
            if (q) free__13gfHeapManagerFPv(q);
            free__13gfHeapManagerFPv(*(void**)(object + 0x40));

            int i;
            u8* cursor = object + 0x44;
            *(void**)(object + 0x40) = 0;
            i = 0;
            for (; i < 0x44; ++i, cursor += 4) {
                cancelRequest__14gfFileIOHandleFv(cursor);
            }
        }

        __dt__9gfArchiveFv(object + 0x154, -1);
        __destroy_arr(object + 0x44, fn_2_647C, 4, 0x44);
        __dt__6gfTaskFv(object, 0);
        if (arg1 > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
}