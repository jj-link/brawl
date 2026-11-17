#pragma force_active on
#include <types.h>
extern "C" char* strcat(char*, const char*);
extern char lbl_8059E148;
struct Text { char data[0x41]; };
struct Arg { s32 id; char name[0x41]; };
extern "C" void fn_800C70A4(u8* self, const Arg* arg) {
    const s32 v = arg->id;
    Text buf;
    buf.data[0] = 0;
    strcat(buf.data, &lbl_8059E148);
    buf.data[0] = 0;
    strcat(buf.data, arg->name);
    *(Text*)(self + 0x15D) = buf;
    *(s32*)(self + 0x380) = v;
    *(u8**)(self + 0x384) = self + 0x15D;
    *(s32*)(self + 0x350) = 6;
}
