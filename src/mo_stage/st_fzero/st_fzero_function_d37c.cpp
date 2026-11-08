#pragma force_active on
typedef unsigned int u32;
struct Flags { u32 pad; u32 flags; };
class Object_vptr_0 {
public:
 virtual void fn_61_BFE0();
 virtual void fn_61_B400();
 virtual void fn_61_B410();
 virtual void slot3();
 virtual void fn_61_A438(int, int);
 Flags* data;
 u32 state;
};
struct Obj {
 char pad0[0x3c];
 void* vtable;
 char pad40[0x90];
 Object_vptr_0 part;
 char paddc[0x7c];
 u32 a158, a15c, a160, a164, a168, a16c;
 float a170, a174, a178, a17c, a180, a184;
 unsigned char a188, a189, a18a;
 u32 a18c;
};
extern "C" Obj* fn_61_2320(Obj*, const char*);
extern "C" char lbl_61_data_36D8[];
extern "C" const float lbl_61_rodata_168;
extern "C" Obj* fn_61_D37C(Obj* self, const char* name) {
 fn_61_2320(self, name);
 self->a158 = 0;
 self->vtable = lbl_61_data_36D8;
 self->a15c = 0;
 self->a160 = 0;
 self->a164 = 0;
 self->a168 = 0;
 self->a16c = 0;
 const float f = lbl_61_rodata_168;
 self->a170 = f;
 self->a174 = f;
 self->a178 = f;
 self->a17c = f;
 self->a180 = f;
 self->a184 = f;
 self->a188 = 7;
 self->a189 = 0;
 self->a18a = 0;
 self->a18c = 0;
 Object_vptr_0* p = &self->part;
 if (!p) return self;
 p->state = 1;
 p->fn_61_A438(0, 15);
 p->data->flags |= 1;
 p->data->flags |= 2;
 return self;
}