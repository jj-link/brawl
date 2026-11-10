#include <types.h>
#include <nw4r/g3d/g3d_obj.h>

#pragma force_active on

class MenuObject {
    char padding[0x5C];
public:
    virtual void method(int);
};

extern "C" {
extern char lbl_8045C814[];
void __dl__FPv(void*);

void* fn_800FE9C0(char* self, int flag) {
    if (self != 0) {
        char* cur = self;
        int i = 0;
        *(char**)(self + 0x124) = lbl_8045C814;
        do {
            nw4r::g3d::G3dObj* p = *(nw4r::g3d::G3dObj**)(cur + 0xF0);
            if (p != 0) {
                p->Destroy();
                *(nw4r::g3d::G3dObj**)(cur + 0xF0) = 0;
            }
            i++;
            cur += 4;
        } while (i < 8);
        cur = self;
        i = 0;
        do {
            MenuObject* p = *(MenuObject**)(cur + 4);
            if (p != 0) {
                if (p != 0) {
                    p->method(1);
                }
                *(MenuObject**)(cur + 4) = 0;
            }
            i++;
            cur += 4;
        } while (i < 0x3B);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}