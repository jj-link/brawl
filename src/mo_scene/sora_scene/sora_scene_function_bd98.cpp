#pragma force_active on
extern "C" {
extern char lbl_1_data_3EA8[];

void* fn_800AFB94(const char*, int, const char*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void* getInstance__14gfSceneManagerFv();
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
void loadMenuSound__6muMenuFv();

void fn_1_BD98(char* self) {
    const char* data = lbl_1_data_3EA8;

    *(void**)(self + 0x35c) = fn_800AFB94(data + 0x24, 150, data + 0x3c);
    changeInput__16CameraControllerFQ216CameraController4Kind(
        getInstance__16CameraControllerFv(), 9);
    *(int*)(self + 0x38c) = 0;

    int mode = *(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280);
    if (mode < 0)
        mode = mode != -1;

    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x390, data + 0x68, 43, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x394, data + 0x84, 43, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x398, data + 0xa0, 43, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x39c, data + 0xc8, 43, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3a0, data + 0xe4, 43, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3a4, data + 0x100, 43, 0, 0);

    if (mode) {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3a8, data + 0x120, 43, 0, 0);
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3ac, data + 0x140, 43, 0, 0);
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3b0, data + 0x158, 43, 0, 0);
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3b4, data + 0x178, 43, 0, 0);
    }

    loadMenuSound__6muMenuFv();
}
}
