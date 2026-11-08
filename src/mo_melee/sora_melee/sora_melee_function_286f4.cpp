#pragma force_active on
#include <types.h>

class Handle { public: virtual void fn0(); virtual Handle* fn1(u32); void* id; };
struct Self { u8 pad[0x28]; Handle* handle; };
struct Entry { void* node; int value; void* owner; u8 fieldC; u8 flag : 1; u8 rest : 7; };
struct Result { float x; float y; };
extern "C" u32 fn_80111CB0(u32*, void*);
extern "C" u32 fn_80134534(void*, u32);
extern "C" u32 fn_801140C0(const Entry*, Entry*);
extern "C" u32 fn_801141C0(const Entry*, Entry*);
extern "C" Result fn_80114E9C(const Entry*);
extern "C" void fn_8003DBA8(float*);
extern "C" const float lbl_27_rodata_3C0;
extern "C" const float lbl_27_rodata_3C4;
extern "C" u32 fn_27_286F4(Self* self, u32 arg1, float* out, u32 flags, u32 arg4) {
    u32 mode;
    if (flags & 1) mode = 0;
    else if (flags & 8) mode = 3;
    else if (flags & 2) mode = 1;
    else { mode = 0; if (flags & 4) mode = 2; }
    u32 id = fn_80134534(self->handle->fn1(arg4)->id, mode);
    Entry entry;
    entry.node = 0; entry.value = 0; entry.owner = 0; entry.fieldC = 0; entry.flag = 0;
    if (fn_80111CB0(&id, &entry) == 0) {
        out[0] = lbl_27_rodata_3C4; out[1] = lbl_27_rodata_3C0; return 0;
    }
    Entry out_entry;
    out_entry.node = 0; out_entry.value = 0; out_entry.owner = 0; out_entry.fieldC = 0; out_entry.flag = 0;
    u32 r;
    if (arg1 == 1) r = fn_801141C0(&entry, &out_entry); else r = fn_801140C0(&entry, &out_entry);
    if (r == 1) {
        Result res = fn_80114E9C(&out_entry);
        out[0] = res.x;
        out[1] = res.y;
        fn_8003DBA8(out);
        return 1;
    }
    return 0;
}