#include <types.h>
#pragma force_active on

extern "C" void* getManager__15gfCameraManagerFv(void* self);
extern "C" void* fn_27_36028(void* self, u32 value, s32 index);
extern "C" void fn_27_4DC08(void* self, void* arg, void* object);

class ElemList {
public:
    virtual void slot0();
    virtual void* get(s32 index);
    virtual void slot2();
    virtual s32 count();
};

struct Copy48 {
    s32 v[12];
};

extern "C" void fn_27_4EDC8(char* self) {
                s32 value;
            s32 fx;
    Copy48 local = *(Copy48*)getManager__15gfCameraManagerFv(self);
    for (s32 i = 0; i < (*(ElemList**)(self + 0x2C))->count(); i++) {
        void* elem = (*(ElemList**)(self + 0x2C))->get(i);
        if (*(s32*)elem != 0) {
            fx = *(s32*)(self + 0xFC);
            if (fx == 0 || *(s32*)(self + 0x100) == fx) {
                value = *(s32*)((char*)(*(ElemList**)(self + 0x2C))->get(i) + 0x58);
                void* e = (*(ElemList**)(self + 0x2C))->get(i);
                void* r = fn_27_36028(self + 0xB8, i, value);
                fn_27_4DC08(e, &local, r);
            }
        }
    }
}
