#pragma force_active on
extern "C" {

extern char lbl_1_data_1FF8[];
extern char lbl_1_data_2004[];

void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* fn_800AFB94(const char*, int, const char*);
void* fn_800B08A8(int);
void* fn_7_0(void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);

void fn_1_8CC0(char* self) {
    *(char**)(self + 0x35c) = (char*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, 12);
    *(void**)(*(char**)(self + 0x35c) + 0) = fn_800AFB94((const char*)lbl_1_data_1FF8, 0x26, (const char*)lbl_1_data_2004);
    *(void**)(*(char**)(self + 0x35c) + 8) = fn_800B08A8(0x2a);
    *(void**)(*(char**)(self + 0x35c) + 4) = fn_7_0(self);
    changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
}

}
