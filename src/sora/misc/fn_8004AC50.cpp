#include <types.h>
#pragma force_active on
extern "C" s32 fn_8004B328(void*);
struct fnAC50Obj {
u8 pad0[0x18]; void* m_18; u8 pad1C[8];
u8 : 2; u8 flag : 1; u8 : 5;
u8 pad25[2]; u8 m_27;
};
extern "C" s32 fn_8004AC50(fnAC50Obj* self) {
s32 result = 0;
if (self->m_18) result = fn_8004B328(self->m_18);
self->flag = 1;
self->m_27 = 0;
return result;
}