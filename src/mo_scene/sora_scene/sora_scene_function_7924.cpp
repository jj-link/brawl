#pragma force_active on
extern "C" {
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* fn_800AFB94(const char*, int, const char*);
void* fn_800B08A8(int);
void* fn_8_0(void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
}

extern const char lbl_1_data_1A68[];
extern const char lbl_1_data_1A78[];

extern "C" void fn_1_7924(void* self) {
    void* result;
    void** task;

    *(void**)((char*)self + 0x35c) =
        alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, 0x10);

    result = fn_800AFB94(lbl_1_data_1A68, 0x21, lbl_1_data_1A78);
    task = *(void***)((char*)self + 0x35c);
    task[0] = result;

    result = fn_800B08A8(0x2a);
    task = *(void***)((char*)self + 0x35c);
    task[2] = result;

    result = fn_8_0(self);
    task = *(void***)((char*)self + 0x35c);
    task[1] = result;

    changeInput__16CameraControllerFQ216CameraController4Kind(
        getInstance__16CameraControllerFv(), 9);

    task = *(void***)((char*)self + 0x35c);
    *((unsigned char*)task + 0xc) = 0;
}
