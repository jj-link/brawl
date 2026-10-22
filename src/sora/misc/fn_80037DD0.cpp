#pragma force_active on

namespace Heaps {
enum HeapType { HeapType_Dummy = 0 };
}

class gfRunnable {
public:
    virtual ~gfRunnable();
};

class gfThread : public gfRunnable {
public:
    void createThread(gfRunnable* r, unsigned long size, unsigned long flags, Heaps::HeapType heap);
};

extern "C" {
extern int __vt__8gfThread[];
extern int lbl_804233B8[];
extern char lbl_80423398[];
extern char lbl_804233A8[];
void* memcpy(void* dst, const void* src, unsigned long n);
}

extern "C" gfThread* fn_80037DD0(gfThread* self) {
    unsigned char* p = (unsigned char*)self;
    *(int**)p = __vt__8gfThread;
    self->createThread(self, 0xC, 0x1000, (Heaps::HeapType)0x3A);
    *(int**)p = lbl_804233B8;
    memcpy(p + 0x340, lbl_80423398, 0x10);
    memcpy(p + 0x350, lbl_804233A8, 0x10);
    p[0x370] = 0;
    *(int*)(p + 0x374) = 0;
    *(int*)(p + 0x378) = 0;
    p[0x380] = 0;
    return self;
}
