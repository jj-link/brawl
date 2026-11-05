#include <types.h>
#pragma force_active on

class Class_Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(int, int);
};

extern "C" int fn_27_28CCF0(void*, int);

extern "C" s32 fn_27_29D8F0(void* unused, char* arg) {
    char* p = *(char**)(arg + 0x60);
    p = *(char**)(p + 0xd8);
    Class_Obj* obj = *(Class_Obj**)(p + 0x64);
    switch (*(s32*)(arg + 0x8c0)) {
    case 0x1C:
        obj->vf5(fn_27_28CCF0(arg, 0x6338), 0x1000000C);
        break;
    case 0x51:
        obj->vf5(fn_27_28CCF0(arg, 0x6D92), 0x1000000C);
        break;
    case 0x52:
        obj->vf5(fn_27_28CCF0(arg, 0x6DC4), 0x1000000C);
        break;
    }
    return 0;
}
