#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <it/it_manager.h>
#include <mu/mu_msg.h>
#include <cstring>
#pragma force_active on

extern "C" {
extern char lbl_2_data_300[];
extern char lbl_2_data_720[];
void fn_2_348(void*);
void fn_2_37C(void*);
void fn_2_3BC(void*);
void fn_2_3C8(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, gfTask::Category, int, int, bool);
void __dt__14gfFileIOHandleFv(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__20tyFigListDataManagerFb(void*, bool);
void* fn_800B08A8(int);
void fn_800B96E8(void*, int);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(unsigned long, Heaps::HeapType, unsigned long);
}

struct WordArray { char pad[0x604]; int words[5]; };
inline void clearWords(char* self) {
    WordArray* a = (WordArray*)self;
    int* p = a->words;
    do { *p = 0; ++p; } while (p < a->words + 5);
}

extern "C" gfTask* fn_2_0(gfTask* self) {
    unsigned int i;
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(self, lbl_2_data_300, (gfTask::Category)0x12, 0xE, 6, true);
    *(void**)((char*)self + 0x3C) = lbl_2_data_720;
    *(int*)((char*)self + 0x40) = 0;
    *(int*)((char*)self + 0x44) = 0;
    __construct_array((char*)self + 0x54, fn_2_348, fn_2_37C, 0xA8, 8);
    *(int*)((char*)self + 0x5A4) = 0;
    *(int*)((char*)self + 0x5A8) = 0;
    *(int*)((char*)self + 0x5B0) = 0;
    *(int*)((char*)self + 0x5FC) = 0;
    *(int*)((char*)self + 0x600) = 0;
    clearWords((char*)self);
    __construct_array((char*)self + 0x624, fn_2_3BC, __dt__14gfFileIOHandleFv, 4, 10);
    *(int*)((char*)self + 0x64C) = 0x270F;
    *(unsigned char*)((char*)self + 0x2C) &= ~2;
    void* it = fn_800B08A8(0x2A);
    *(void**)((char*)self + 0x5EC) = it;
    *(void**)((char*)it + 0x40) = (char*)self + 0x5B4;
    *(int*)((char*)it + 0x44) = 0xC;
    *(int*)((char*)self + 0x5B4) = 0;
    *(int*)((char*)self + 0x5B8) = 0;
    *(int*)((char*)self + 0x5BC) = 0;
    *(int*)((char*)self + 0x5C0) = 0;
    *(int*)((char*)self + 0x5C4) = 0;
    *(int*)((char*)self + 0x5C8) = 0;
    *(int*)((char*)self + 0x5CC) = 0;
    *(int*)((char*)self + 0x5D0) = 0;
    *(int*)((char*)self + 0x5D4) = 0;
    *(int*)((char*)self + 0x5D8) = 0;
    *(int*)((char*)self + 0x5DC) = 0;
    *(int*)((char*)self + 0x5E0) = 0;
    *(int*)((char*)self + 0x5E4) = 0;
    *(int*)((char*)self + 0x5E8) = 0;
    *(int*)((char*)self + 0x5FC) = 0;
    *(int*)((char*)self + 0x600) = 0;
    *(int*)((char*)self + 0x604) = 0;
    *(int*)((char*)self + 0x608) = 0;
    *(int*)((char*)self + 0x60C) = 0;
    *(int*)((char*)self + 0x610) = 0;
    *(int*)((char*)self + 0x614) = 0;
    *(unsigned char*)((char*)self + 0x618) = 0;
    *(unsigned char*)((char*)self + 0x619) = 0;
    *(unsigned char*)((char*)self + 0x61A) = 0;
    *(unsigned char*)((char*)self + 0x61B) = 0;
    *(unsigned char*)((char*)self + 0x61C) = 0;
    *(unsigned char*)((char*)self + 0x61D) = 0;
    *(unsigned char*)((char*)self + 0x61E) = 0;
    *(unsigned char*)((char*)self + 0x61F) = 0;
    *(unsigned char*)((char*)self + 0x620) = 0;
    *(unsigned char*)((char*)self + 0x621) = 0;
    void* figure = *(void**)((char*)itManager::getInstance() + 0x14B8);
    if (figure != NULL) {
        *(void**)((char*)self + 0x48) = *(void**)((char*)figure + 4);
    } else {
        void* m = __nw__FUlQ25Heaps8HeapType(0x1468, 0x2A);
        if (m != NULL) {
            m = __ct__20tyFigListDataManagerFb(m, true);
        }
        *(void**)((char*)self + 0x48) = m;
    }
    fn_2_3C8(self);
    MuMsg* m1 = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (Heaps::HeapType)0x2A, 0x2B);
    *(MuMsg**)((char*)self + 0x5F0) = m1;
    m1->allocMsgBuf(0x100, 3);
    MuMsg* m2 = create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (Heaps::HeapType)0x2A, 0x2B);
    *(MuMsg**)((char*)self + 0x5F4) = m2;
    m2->allocMsgBuf(0x800, 1);
    MuMsg* m3 = create__5MuMsgFUlQ25Heaps8HeapTypeUl(2, (Heaps::HeapType)0x2A, 0x2B);
    *(MuMsg**)((char*)self + 0x5F8) = m3;
    m3->allocMsgBuf(0x80, 1);
    for (i = 0; i < 8; i++) {
        fn_800B96E8((char*)self + (unsigned char)i * 0xA8 + 0x54, (unsigned char)i);
    }
    return self;
}
