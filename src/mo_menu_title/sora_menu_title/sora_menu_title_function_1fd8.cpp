#pragma force_active on

struct Self {
    char pad[0x48];
    void* resFileA;
    void* resFileB;
    void* obj1;
    void* obj2;
    void* obj3;
};

extern const char lbl_24_data_628[];

extern "C" {
void* fn_800B03F0(void*, int);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
void fn_24_240C(void* self);
extern void* g_GameGlobal;
}

extern "C" void fn_24_1FD8(Self* self, void* param) {
    const char* names = lbl_24_data_628;
    unsigned char flag = *(unsigned char*)((char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28);
    if (!((flag >> 7) & 1)) {
        self->resFileA = fn_800B03F0(param, 0xa);
    } else {
        self->resFileA = fn_800B03F0(param, 0xb);
    }
    self->resFileB = fn_800B03F0(param, 0x3c);
    Init__Q34nw4r3g3d7ResFileFPv(&self->resFileA);
    Init__Q34nw4r3g3d7ResFileFPv(&self->resFileB);
    self->obj1 = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &self->resFileB, names + 0xc8, 1, 0, 0x2a);
    self->obj2 = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &self->resFileB, names + 0xd0, 1, 0, 0x2a);
    self->obj3 = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
        &self->resFileB, names + 0xdc, 1, 0, 0x2a);
    fn_24_240C(self);
}
