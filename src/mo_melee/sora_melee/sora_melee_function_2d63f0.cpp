#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <stdio.h>
#pragma force_active on
extern "C" char lbl_27_data_7B528[];
extern "C" int fn_27_2D63F0(char* base, int arg1) {
    char buffer[0x80];
    if (arg1 == 0 && *(int*)(base + 0x514) == 0 && *(int*)(base + 0x518) == 0) {
        int i = 0;
        char* p = base;
        for (; i < 65; i++, p += 0x14) {
            if (*(int*)(p + 0xC) != 0 && *(unsigned short*)(p + 0xA) != 0 && *(int*)(p + 0x10) == 0) {
                *(int*)(base + 0x518) = (int)p;
                break;
            }
        }
        if (*(int*)(base + 0x518) == 0) {
            p = base;
            for (int i = 0; i < 65; i++, p += 0x14) {
                if (*(int*)(p + 0xC) != 0 && *(int*)(p + 0x10) == 0) {
                    *(int*)(base + 0x518) = (int)p;
                    break;
                }
                }
        }
        if (*(int*)(base + 0x518) != 0) {
            char* found = (char*)*(int*)(base + 0x518);
            char* str = (char*)*(void**)((char*)*(void**)(found + 0xC) + 8);
            sprintf(buffer, lbl_27_data_7B528, str);
            ((gfFileIOHandle*)(base + 0x514))->readRequest(buffer, (Heaps::HeapType)0x2b, 0, 0);
        }
    }
    if (*(int*)(base + 0x514) != 0) {
        if (((gfFileIOHandle*)(base + 0x514))->isReady()) {
            if (*(int*)(base + 0x518) == 0 || arg1 != 0) {
                gfHeapManager::free(((gfFileIOHandle*)(base + 0x514))->getBuffer());
            } else {
                *(void**)(*(char**)(base + 0x518) + 0x10) = ((gfFileIOHandle*)(base + 0x514))->getBuffer();
                nw4r::g3d::ResFile::Init(*(char**)(base + 0x518) + 0x10);
                *(int*)(base + 0x518) = 0;
            }
            ((gfFileIOHandle*)(base + 0x514))->release();
        } else {
            return 0;
        }
    }
    return 1;
}