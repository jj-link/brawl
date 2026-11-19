#include <gf/gf_archive.h>
#include <gf/gf_file_io_handle.h>
#include <mu/mu_msg.h>
#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern char lbl_3_data_0[];
extern char lbl_3_data_20[];
extern "C" void* fn_800B08A8(int);
extern "C" MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, HeapType, unsigned long);
extern "C" void fn_800151FC(void*, const char*, int, int, int, int);

inline void clearRange(int* begin, int* end) {
    int* p = begin;
    do {
        *p = 0;
        ++p;
    } while (p < end);
}

struct Entry {
    int a, b, c, d, e, f;
};
struct Fields {
    int pad;
    int array[94];
    char gap[0xf50 - 0x17c];
    Entry entries[16];
};

extern "C" void* fn_3_0(Fields* object, int arg1, int arg2) {
    u8* self = (u8*)object;
    clearRange((int*)(self + 0x17c), (int*)(self + 0x1f8));
    clearRange((int*)(self + 0x1f8), (int*)(self + 0x2f4));
    *(int*)(self + 0x2f8) = arg2;
    *(int*)(self + 0x10d0) = 0;
    *(int*)(self + 0x10d8) = arg1;
    *(int*)(self + 0x10dc) = 0;
    *(int*)(self + 0x10e8) = 0;
    u8* resource = (u8*)fn_800B08A8(0x2a);
    *(u8**)(self + 0x2f4) = resource;
    *(void**)(resource + 0x40) = self + 4;
    *(int*)(resource + 0x44) = 0x5e;
    for (int i = 0; i < 94; ++i)
        object->array[i] = 0;
    for (int i = 0; i < 16; ++i) {
        ((Fields*)self)->entries[i].a = 0;
        ((Fields*)self)->entries[i].b = 0;
        ((Fields*)self)->entries[i].c = 0;
        ((Fields*)self)->entries[i].d = 0;
        ((Fields*)self)->entries[i].e = 0;
        ((Fields*)self)->entries[i].f = 0;
    }
    *(int*)self = 0;
    *(u8*)(self + 0x10e0) = 0;
    gfArchive* archive = new ((HeapType)0x2b) gfArchive;
    *(gfArchive**)(self + 0x10e4) = archive;
    fn_800151FC(archive, lbl_3_data_0, 0x2b, 0, 0, 0xff);
    if (*(int*)(self + 0x10d8) == 0) {
        *(u8*)(self + 0x10e1) = 0;
        ((gfFileIOHandle*)(self + 0x10e8))->readRequest(lbl_3_data_20, (HeapType)0x2b, 0, 0);
    } else {
        *(u8*)(self + 0x10e1) = 1;
    }
    MuMsg* msg = create__5MuMsgFUlQ25Heaps8HeapTypeUl(2, (HeapType)0x2a, 0x2b);
    *(MuMsg**)(self + 0x10d4) = msg;
    msg->allocMsgBuf(0x40, 0x20);
    return self;
}
