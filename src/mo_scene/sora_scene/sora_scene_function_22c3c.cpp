#pragma force_active on
struct SceneObject {
    const char* name;
    const void* data;
    int value;
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const char lbl_1_data_6F50[];
extern "C" const char lbl_1_data_7004[];

extern "C" SceneObject* fn_1_22C3C() {
    SceneObject* obj = static_cast<SceneObject*>(__nw__FUlQ25Heaps8HeapType(0x1C, 0x2E));
    if (obj != 0) {
        obj->name = lbl_1_data_6F50;
        obj->data = lbl_1_data_7004;
        obj->value = 0;
    }
    return obj;
}
