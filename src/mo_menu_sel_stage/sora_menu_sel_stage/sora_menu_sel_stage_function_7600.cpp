#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern const char lbl_11_data_668[];
extern char lbl_11_data_688[];

struct Counts {
    int a;
    int b;
};

extern Counts lbl_11_rodata_248;

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, gfTask::Category, int, int, bool);
void* fn_80038984(void*, int);
}

extern "C" void* fn_11_7600(void* self) {
    char* p = (char*)self;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        self, lbl_11_data_668, gfTask::Category_Menu, 15, 8, true);

    *(void**)(p + 0x3C) = lbl_11_data_688;
    *(int*)(p + 0x40) = 0;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x68) = 0;
    *(char*)(p + 0x398) = 0;

    Counts counts = lbl_11_rodata_248;
    *(unsigned char*)(p + 0x2C) &= ~2;
    memset(p + 0x48, 0, 0x20);

    int i = 0;
    int* cur = &counts.a;
    int offset = 0;
    do {
        void* ptr = gfHeapManager::alloc(
            (Heaps::HeapType)0x2A, *cur * 0x18);
        ++i;
        *(void**)(p + offset + 0x54) = ptr;
        ++cur;
        offset += 0x10;
    } while (i < 2);

    memset(p + 0x70, 0, 0x318);

    offset = 0;
    i = 0;
    do {
        void* ptr = gfHeapManager::alloc(
            (Heaps::HeapType)0x2A, 0x12C00, 0x20);
        ++offset;
        *(void**)(p + i + 0x80) = ptr;
        i += 0x58;
    } while (offset < 9);

    memset(p + 0x388, 0, 0x10);

    void* obj = operator new(0x194, (Heaps::HeapType)0x2A);
    if (obj) {
        obj = fn_80038984(obj, 0x2A);
    }
    *(void**)(p + 0x68) = obj;

    return self;
}
