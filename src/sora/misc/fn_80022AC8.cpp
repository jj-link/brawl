#include <types.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_manager.h>
#include <gf/gf_file_io_request.h>
#include <gf/gf_thread.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on
extern "C" void fn_8020D38C(char*);
extern "C" void fn_8001BBB8();
extern "C" int fn_803C2F08();
extern "C" void fn_803C2F1C(void*, int);
extern "C" void fn_80044214(unsigned int*);
extern "C" void fn_801FC454(int);
extern "C" char lbl_80421714[];
extern "C" char __vt__8gfThread[];
struct Entry { u8 a, b; u16 c; };
struct Flags { u8 first : 3; u8 second : 1; };
struct ThreadFlags { u8 first : 1; };
inline void clearEntries(Entry* p, Entry* end) {
    do {
        p->a = 0; p->b = 0; p->c = 0;
        ++p;
    } while (p < end);
}
extern "C" gfFileIOManager* fn_80022AC8(gfFileIOManager* self) {
    *(int*)self = 0;
    self->m_thread = 0;
    self->m_queue1 = 0;
    *(void**)((char*)self + 0x10) = 0;
    *(u16*)((char*)self + 0x14) = 0x20;
    *(u16*)((char*)self + 0x16) = 0;
    clearEntries((Entry*)(self->_0x10 + 0x8), (Entry*)(self->_0x10 + 0x88));
    ((Flags*)((char*)self + 0x98))->first = 0;
    ((Flags*)((char*)self + 0x98))->second = 1;
    g_gfFileIOManager = self;
    char temp[0x40]; fn_8020D38C(temp); fn_8001BBB8();
    if (fn_803C2F08() == 0) { void* p = gfHeapManager::alloc((Heaps::HeapType)1, 0x4000); fn_803C2F1C(p, 0x4000); }
    void* obj = operator new(0xc, (Heaps::HeapType)1);
    if (obj) {
        *(unsigned int*)obj = 0x80;
        void* p = gfHeapManager::alloc((Heaps::HeapType)1, 0x5214);
        if (p) { *(unsigned int*)p = 0x80; fn_80044214((unsigned int*)p); }
        *(void**)((char*)obj+4)=p; *(void**)((char*)obj+8)=(char*)p+0x14;
    }
    *(void**)((char*)self+0x10)=obj;
    self->m_queue1 = new ((Heaps::HeapType)1) gfFileIORequestQueue;
    self->m_queue2 = new ((Heaps::HeapType)1) gfFileIORequestQueue;
    void* thread=operator new(0x348,(Heaps::HeapType)1);
    if(thread) {
        *(void**)thread=__vt__8gfThread;
        ((gfThread*)thread)->createThread((gfRunnable*)thread,0xf,0x3000,(Heaps::HeapType)1);
        *(void**)thread=lbl_80421714;
        ((ThreadFlags*)((char*)thread + 0x340))->first = 0;
    }
    self->m_thread=(gfThread*)thread;
    OSResumeThread((OSThread*)((char*)thread+8));
    ((u8*)self)[0x98]|=0x20;
    fn_801FC454(0);
    *(int*)self=1;
    return self;
}