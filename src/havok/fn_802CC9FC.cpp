#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(int a, int b, void* c);
    virtual void slot2(char* name, int size, void* data, unsigned int count, unsigned int flags);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
};

extern char lbl_80410050[];

extern "C" void fn_802CC9FC(void* arg0, Object_vptr_0* obj) {
    obj->slot1(0, 2, arg0);
    void* data = *(void**)((char*)arg0 + 0x1C24);
    if (data != 0) {
        obj->slot2(lbl_80410050 + 0x147, 4, data, 0xC00, 0);
        obj->slot2(lbl_80410050 + 0x147, 4, *(void**)((char*)arg0 + 0x1C28), 0xC00, 0);
        obj->slot2(lbl_80410050 + 0x147, 4, *(void**)((char*)arg0 + 0x1C2C), 0xC00, 0);
        obj->slot2(lbl_80410050 + 0x147, 4, *(void**)((char*)arg0 + 0x1C30), 0xC00, 0);
    }
    obj->slot6();
}
