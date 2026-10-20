#pragma force_active on
struct TaskObj {
    char pad_0[0x3C];
    void* field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    char pad_58[0x08];
    int field_60;
    int field_64;
};

extern "C" {
extern const char lbl_24_data_558[];
extern const char lbl_24_data_59C[];
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
TaskObj* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(TaskObj*, const char*, int, int, int, bool);

TaskObj* fn_24_1444() {
    TaskObj* obj = (TaskObj*)__nw__FUlQ25Heaps8HeapType(0x68, 0x2A);
    if (obj != 0) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(obj, lbl_24_data_558, 8, 0xF, 8, true);
        obj->field_3C = (void*)lbl_24_data_59C;
        obj->field_40 = 0;
        obj->field_44 = 0;
        obj->field_48 = 0;
        obj->field_4C = 0;
        obj->field_50 = 0;
        obj->field_54 = 0;
        obj->field_60 = 0;
        obj->field_64 = 0;
    }
    return obj;
}
}
