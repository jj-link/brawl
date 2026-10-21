#include <types.h>
#pragma force_active on

extern "C" void fn_27_5C600(void* self, void* arg);
extern "C" u8 lbl_27_data_6388[];
extern "C" u8 __vt__22soAnimCmdEventObserver[];

class ObsBase {
public:
    virtual void init(s32 a, s32 b);
};

class Getter {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual s16 get();
};

extern "C" void* fn_27_5BED0(void* self, void* arg) {
    unsigned char* p = (unsigned char*)self;
    unsigned char* a = (unsigned char*)arg;
    fn_27_5C600(self, arg);
    unsigned char* obj = *(unsigned char**)(*(unsigned char**)(a + 0xd8) + 0x80);
    s16 ret = ((Getter*)(obj + 8))->get();
    *(s16*)(p + 0x1c) = -1;
    *(s16*)(p + 0x1e) = 5;
    *(s16*)(p + 0x20) = -1;
    *(void**)(p + 0x18) = __vt__22soAnimCmdEventObserver;
    ((ObsBase*)(p + 0x18))->init((s32)ret, -1);
    *(u8**)(p + 0x8) = lbl_27_data_6388;
    *(u8**)(p + 0x0) = lbl_27_data_6388 + 8;
    *(u8**)(p + 0x18) = lbl_27_data_6388 + 0x58;
    *(s32*)(p + 0x24) = 1;
    *(s32*)(p + 0x28) = 0;
    *(u8*)(p + 0x2c) = 0xff;
    *(s32*)(p + 0x30) = 0;
    *(s32*)(p + 0x34) = 1;
    return self;
}
