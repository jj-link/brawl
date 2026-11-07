#include <types.h>
#pragma force_active on

struct Entry {
    virtual void v0();
    virtual void* get(int i);
    virtual void v2();
    virtual int count();
};

struct CamObj {
    char pad[0x2c];
    Entry* list;
    char pad2[0xc0 - 0x30];
    char camData[1];
};

struct Copy {
    u32 w[12];
};

extern "C" void* getManager__15gfCameraManagerFv();
extern "C" int fn_27_36028(void* a, int b, int c);
extern "C" void fn_27_4B0E8(void* self, Copy* arg, int target);

extern "C" void fn_27_4C034(CamObj* self) {
    Copy local = *(Copy*)getManager__15gfCameraManagerFv();
    void* p;
    int i = 0;
    while (i < self->list->count()) {
        if (*(int*)self->list->get(i) != 0) {
            p = self->list->get(i);
            fn_27_4B0E8(p, &local, fn_27_36028(&self->camData, i, 0));
        }
        i++;
    }
}
