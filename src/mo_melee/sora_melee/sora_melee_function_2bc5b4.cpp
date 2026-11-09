#include <types.h>
#pragma force_active on
extern "C" {
struct Item { u8 pad[0xE8]; u32 value; };
struct Table { u32 value; Item** items; };
struct CastResult {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual s32 get();
};
struct Inner { u32 pad[2]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void* get(); u32 data[3]; };
struct SelfRaw { u32 pad0; u8 flag; u8 pad5[3]; u32 vtable; Inner inner; u32 ptr24; s32 val28; Table* table; u32 val30; Item* item; u32 result; };
struct SelfVirt { u32 pad[2]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void apply(u32, u32, u32); Inner inner; u32 ptr24; s32 val28; Table* table; u32 val30; Item* item; u32 result; };
extern char lbl_27_data_7A048[]; extern char lbl_27_data_7A050[]; extern char lbl_27_data_7A0C8[]; extern char lbl_27_data_CBA0[];
void* __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc(void*, unsigned long, void*, unsigned char);
void* __dynamic_cast(void*, long, const void*, const void*, short);
s32 fn_27_2BCDD8(CastResult*);
Table* fn_27_2B25BC(s32, s32, s32);
SelfRaw* fn_27_2BC5B4(SelfRaw* self, s32 arg1, u8 arg2, void* arg3) {
 self->flag = 0;
 self->vtable = (u32)lbl_27_data_7A0C8;
 self->pad0 = (u32)(lbl_27_data_7A0C8 + 8);
 __ct__20soResourceModuleImplFUlP20soResourceIdAccesserUc((void*)&self->inner, 2, arg3, arg2);
 self->ptr24 = (u32)&self->inner;
 self->val28 = -1;
 self->vtable = (u32)lbl_27_data_7A050;
 self->pad0 = (u32)(lbl_27_data_7A050 + 8);
 self->table = 0;
 self->val30 = 0;
 self->item = 0;
 ((SelfVirt*)self)->apply(arg2, 0xFF, (u32)lbl_27_data_7A050);
 CastResult* cast = (CastResult*)__dynamic_cast(self->inner.get(), 0, lbl_27_data_7A048, lbl_27_data_CBA0, 1);
 self->table = fn_27_2B25BC(arg1, fn_27_2BCDD8(cast), cast->get());
 self->val30 = self->table->value;
 self->item = 0;
 s32 index = fn_27_2BCDD8(cast);
 if (self->table) self->item = self->table->items[index];
 if (self->item) self->result = self->item->value;
 return self;
}
}