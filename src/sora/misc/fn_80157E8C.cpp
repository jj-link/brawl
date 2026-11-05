#include <types.h>

#pragma force_active on

extern "C" {
int fn_801541DC(int arg0);
void fn_80153488(void* arg0);
void* fn_801541F0(int arg0, u8 arg1);
void fn_80153498(void* arg0, int arg1);
int fn_80153504(void* arg0, int arg1);
void* fn_80153818(void* arg0, int arg1);
void fn_80152FA4(void);
u64 fn_801504AC(int arg0);
void fn_801E1D80(u64 arg0, void* arg1);
void fn_8014FC64(u16 a, u8 b, u8 c);
void fn_8014FC44(u16 a, u8 b, u8 c);
}

struct ObjBase {
    int type;
    int pad4;
};
class Obj : public ObjBase {
public:
    virtual void fn_80152F34(int arg1);
    virtual void fn_1();
    virtual void fn_2();
};

extern "C" int fn_80157E8C(void* self, int arg1) {
    int entry[2];
    int timeData[8];

    if ((u8)fn_801541DC(arg1) != 1) {
        return 0;
    }

    fn_80153488(entry);
    if (fn_80153504(entry, (int)fn_801541F0(arg1, 0)) == 0) {
        fn_80153498(entry, -1);
        return 0;
    }

    Obj* obj = (Obj*)fn_80153818(entry, *(int*)((char*)self + 0x350));
    if (obj == 0) {
        fn_80153498(entry, -1);
        return 0;
    }

    if (obj->type == 0) {
        fn_80152FA4();
        fn_801E1D80(fn_801504AC(0), timeData);
        fn_8014FC64((u16)timeData[5], (u8)(timeData[4] + 1), (u8)timeData[3]);
        fn_8014FC44((u16)timeData[5], (u8)(timeData[4] + 1), (u8)timeData[3]);
    }

    if (obj != 0) {
        obj->fn_80152F34(1);
    }

    fn_80153498(entry, -1);
    return 0;
}