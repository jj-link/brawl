#include <types.h>
#pragma force_active on

extern "C" {

extern char lbl_8040FBE8[];

class SomeClass {
public:
    virtual void v0();
    virtual void v1(char*, int, void*);
    virtual void v2(char*, int, void*, u32, u32);
};

extern void fn_802FEA60(void*, void*);

void fn_802AA3D8(void* arg0, SomeClass* arg1) {
    char* self = (char*)arg0;
    arg1->v1(lbl_8040FBE8 + 0x22, 8, arg0);
    u32 flags = *(u32*)(self + 0x38);
    char* name = lbl_8040FBE8 + 0x2D;
    if (!(flags & 0x80000000)) {
        arg1->v2(name, 8, *(void**)(self + 0x30), *(u32*)(self + 0x34) * 4, flags * 4);
    }
    fn_802FEA60(self + 0x30, arg1);
}

}
