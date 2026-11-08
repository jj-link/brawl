#include <types.h>
#pragma force_active on

extern "C" {

void fn_802EFF2C(void* arg0, s8* arg1);
void fn_802FA0BC();

struct Outer {
    u32 pad_0x00[2];
    void* field_0x08;
};

struct Inner {
    u8 pad_0x00[0x7C];
    void* field_0x7C;
};

struct Msg {
    s8 flag;
    void* ptr;
    s8 a;
    s8 b;
    s8 c;
};

void fn_802E2FF8(Outer* arg0, s8 arg1, s8 arg2, s8 arg3) {
    if (arg0->field_0x08 && ((Inner*)arg0->field_0x08)->field_0x7C) {
        Msg msg;
        msg.flag = 4;
        msg.ptr = arg0;
        msg.a = arg1;
        msg.b = arg2;
        msg.c = arg3;
        fn_802EFF2C(arg0->field_0x08, (s8*)&msg);
    } else {
        fn_802FA0BC();
    }
}

}