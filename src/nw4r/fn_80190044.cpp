#include <revolution/GX/GXDisplayList.h>
#pragma force_active on
struct Data { char pad[4]; int size; int offset; };
struct Obj { char pad[0x24]; Data data; };
struct Holder { Obj* obj; };
extern "C" void fn_801F4EAC(int, int);
extern "C" void fn_80190044(Holder* holder, int flag) {
    Data* data = &holder->obj->data;
    if (flag) {
        fn_801F4EAC(data->offset ? (int)((char*)data + data->offset) : 0, data->size);
    } else {
        void* ptr = data->offset ? (void*)((char*)data + data->offset) : 0;
        GXFastCallDisplayList(ptr, data->size);
    }
}