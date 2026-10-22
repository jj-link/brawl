#pragma force_active on
extern "C" {
extern char lbl_24_data_478[];
extern float lbl_24_rodata_2C;

void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, unsigned short);
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* fn_800AFBFC(const void*, unsigned int, void*, unsigned int);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(void*, const char*, int, void*, int);
void changeAnimN__8MuObjectFPCc(void*, const char*);
void setUpdateRate__16gfModelAnimationFf(void*, float);

struct Self {
    char pad[0x40];
    void* a;
    void* b;
    void* obj;
};

void fn_24_1344(Self* self, void* archive) {
    const char* const data = lbl_24_data_478;
    self->a = getData__9gfArchiveF11ARCNodeTypeiUs(archive, 2, 1, 0xFFFE);
    Init__Q34nw4r3g3d7ResFileFPv(&self->a);
    self->b = fn_800AFBFC(data + 0xc, 0x10, archive, 0xa);
    self->obj = create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(&self->a, data + 0x18, 1, 0, 0x2a);
    changeAnimN__8MuObjectFPCc(self->obj, data + 0x2c);
    setUpdateRate__16gfModelAnimationFf(*(void**)((char*)self->obj + 0x14), lbl_24_rodata_2C);
}
}
