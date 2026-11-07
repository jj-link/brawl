#include <gf/gf_heap_manager.h>
#include <cm/cm_camera_controller.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void fn_800A8DA8(void*, int);
extern "C" int fn_80052DB0();
extern "C" void* fn_800B08A8(int);
extern "C" void* fn_2_864C(void*, void*);
extern "C" char lbl_1_data_17A0[];
extern "C" char lbl_1_data_17C0[];
extern "C" void* g_GameGlobal;

struct Data {
    CameraController* camera;
    void* field4;
    void* field8;
    char fieldC;
};
struct Scene {
    char pad[8];
    Data* data;
};

extern "C" void fn_1_6BDC(Scene* self) {
    self->data = (Data*)gfHeapManager::alloc((Heaps::HeapType)0x2a, 0x10);
    self->data->camera = CameraController::getInstance();
    self->data->camera->changeInput(CameraController::Photo);
    fn_800A8DA8(__dynamic_cast(*(void**)((char*)self->data->camera + 0x48), 4, lbl_1_data_17A0, lbl_1_data_17C0, 0), 1);
    self->data->fieldC = 0;
    *(int*)((char*)*(void**)((char*)g_GameGlobal + 0x1c) + 0x34) = fn_80052DB0();
    self->data->field4 = fn_800B08A8(0x2a);
    self->data->field8 = fn_2_864C(self, (char*)*(void**)((char*)g_GameGlobal + 0x1c) + 0x30);
}