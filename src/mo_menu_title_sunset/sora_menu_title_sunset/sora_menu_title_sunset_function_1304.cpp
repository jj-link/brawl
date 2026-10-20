#pragma force_active on
extern "C" {
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void* create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
    void*, const char*, int, void*, int);
extern char lbl_25_data_1BC[];
extern const float lbl_25_rodata_24;
void fn_25_14C4(void*, float, float, float, float);
}

struct Buffer {
    void* data;
};

extern "C" void fn_25_1304(void* self, Buffer buffer) {
    char* base = (char*)self;
    void* buf = buffer.data;
    *(int*)(base + 0xB4) = 2;
    *(void**)(base + 0x44) = buf;
    Init__Q34nw4r3g3d7ResFileFPv(base + 0x44);
    void* obj =
        create__8MuObjectFPQ34nw4r3g3d7ResFilePCciPQ34nw4r3g3d7ResFileQ25Heaps8HeapType(
            base + 0x44, lbl_25_data_1BC, 1, 0, 0x2A);
    *(void**)(base + 0x48) = obj;
    float v = lbl_25_rodata_24;
    fn_25_14C4(self, v, v, v, v);
}
