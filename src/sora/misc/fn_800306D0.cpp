#pragma force_active on

#include <gf/gf_archive.h>
#include <gf/gf_file_io_handle.h>

extern "C" {
extern void free__13gfHeapManagerFPv(void*);
extern void fn_8014E520(void*, int);
extern void __dt__9gfArchiveFv(void*, int);
extern void __dt__14gfFileIOHandleFv(void*, int);
extern void __dl__FPv(void*);

void* fn_800306D0(void* self, int flag) {
    if (self) {
        void* a0 = *(void**)self;
        if (a0) {
            free__13gfHeapManagerFPv(a0);
            *(void**)self = 0;
        }
        void* a1 = *(void**)((char*)self + 0x8C);
        if (a1) {
            free__13gfHeapManagerFPv(a1);
            *(void**)((char*)self + 0x8C) = 0;
        }
        void* a2 = *(void**)((char*)self + 0x90);
        if (a2) {
            free__13gfHeapManagerFPv(a2);
            *(void**)((char*)self + 0x90) = 0;
        }
        void* a3 = *(void**)((char*)self + 0x94);
        if (a3) {
            free__13gfHeapManagerFPv(a3);
            *(void**)((char*)self + 0x94) = 0;
        }
        void* a4 = *(void**)((char*)self + 0x9C);
        if (a4) {
            fn_8014E520(a4, 1);
            *(void**)((char*)self + 0x9C) = 0;
        }
        __dt__9gfArchiveFv((char*)self + 0xC, -1);
        __dt__14gfFileIOHandleFv((char*)self + 0x8, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
