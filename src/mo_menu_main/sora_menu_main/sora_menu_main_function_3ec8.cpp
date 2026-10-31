#pragma force_active on
#include <cstdio>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <gm/gm_global_mode_melee.h>

class CallbackView : public gmPlayerInitData {
public:
    virtual void callback(int) = 0;
};

extern "C" void fn_2_308C(void*, void*, void*);
extern "C" void fn_2_3C80(void*);
extern const char lbl_2_data_680[];
extern const char lbl_2_data_6B8[];

extern "C" int fn_2_3EC8(void* self) {
    char* p = (char*)self;
    int state = *(int*)(p + 0x34);

    if ((unsigned)(state - 4) <= 1u) {
        if (*(int*)(p + 0x38) == 0)
            return 0;
        if (!((gfFileIOHandle*)(p + 0x38))->isReady())
            return 0;
        if (((gfFileIOHandle*)(p + 0x38))->getBuffer() == 0) {
            ((gfFileIOHandle*)(p + 0x38))->readRequest(
                lbl_2_data_6B8, (HeapType)0x2b, 0, 0);
            return 0;
        }

        unsigned val58 = *(unsigned*)(p + 0x58);
        if (*(unsigned*)(p + 0x54) == val58) {
            *(int*)(p + 0x5c) = val58;
            *(int*)(p + 0x34) = 0;
            fn_2_3C80(self);
            return 0;
        }

        gfHeapManager::free(
            ((gfFileIOHandle*)(p + 0x38))->getBuffer());
        ((gfFileIOHandle*)(p + 0x38))->release();
        *(int*)(p + 0x34) = 5;
        fn_2_308C(self, *(void**)(p + 0x30), *(void**)(p + 0x0c));
    }

    state = *(int*)(p + 0x34);
    if (state == 1) {
        int val = *(int*)(p + 0x60) + 1;
        *(int*)(p + 0x60) = val;
        if (val >= 4) {
            void* obj = *(void**)(p + 0x14);
            if (obj)
                ((CallbackView*)obj)->callback(1);

            *(void**)(p + 0x14) = 0;
            void* obj3c = *(void**)(p + 0x3c);
            if (obj3c) {
                gfHeapManager::free(obj3c);
                *(void**)(p + 0x3c) = 0;
            }
            *(int*)(p + 0x34) = 2;
            *(int*)(p + 0x64) = 0;
        }
        return 1;
    }

    if (state == 2) {
        int val = *(int*)(p + 0x64) + 1;
        *(int*)(p + 0x64) = val;
        if (val >= 4) {
            ((gfFileIOHandle*)(p + 0x38))->release();
            int saved = *(int*)(p + 0x54);
            char buf[0x40];
            char* ptr30 = *(char**)(p + 0x30);
            sprintf(buf, lbl_2_data_680, *(int*)(ptr30 + 8));
            *(int*)(p + 0x58) = saved;
            ((gfFileIOHandle*)(p + 0x38))->readRequest(
                buf, (HeapType)0x2b, 0, 0);
            *(int*)(p + 0x34) = 4;
        }
        return 1;
    }

    return state == 0;
}
