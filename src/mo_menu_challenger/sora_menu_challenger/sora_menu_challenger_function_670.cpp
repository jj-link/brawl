#pragma force_active on

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void f34(void*, void*);
};

extern "C" {
extern char lbl_23_section4_0[0x1A4];
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* fn_800AFB94(const char*, int, const char*);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
}

#pragma push
#pragma opt_propagation off
extern "C" void fn_23_670(char* self, void* archive) {
    char* p = lbl_23_section4_0;
    *(void**)(self + 0x40) = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 0, 0xFFFE);
    *(void**)(self + 0x44) = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 1, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x40);
    Init__Q34nw4r3g3d7ResFileFPv(self + 0x44);
    *(void**)(self + 0x48) = fn_800AFB94(p + 0x1d8, 0x10, p + 0x1e8);
    *(void**)(self + 0x4C) = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(self + 0x40, p + 0x214, 1, 0, 0x2a);
    *(void**)(self + 0x50) = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(self + 0x44, self + 0x5c + (*(int*)(self + 0x54) << 6), 1, 0, 0x2a);
    VObj* a = *(VObj**)(*(char**)(self + 0x48) + 0x48);
    a->f34(*(void**)((char*)a + 0xe4), *(void**)(*(char**)(self + 0x4C) + 0xc));
    VObj* b = *(VObj**)(*(char**)(self + 0x48) + 0x48);
    b->f34(*(void**)((char*)b + 0xe4), *(void**)(*(char**)(self + 0x50) + 0xc));
}
#pragma pop
