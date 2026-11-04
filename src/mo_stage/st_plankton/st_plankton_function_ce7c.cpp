#pragma force_active on
typedef unsigned int u32;
class Class_1E10 {
public:
 virtual void fn_74_9ADC();
 virtual void fn_74_8FA4();
 virtual void fn_74_8FB4();
 virtual void fn_74_6B18();
 virtual void fn_74_6758(int, int);
};
struct Sub { Class_1E10* vt; u32* p4; u32 f8; };
struct Obj {
 char pad0[0x3c]; void* vt; char pad40[0x90]; Sub sub;
 char padDC[0x74]; unsigned char b150; char pad151[3]; float f154; u32 w158;
 union { int w15c; unsigned char b15c[4]; };
 union { int w160; unsigned char b160[4]; };
 void* p164; int w168; int w16c;
};
extern "C" void fn_74_264C(Obj*);
extern char lbl_74_data_2E60[];
extern char lbl_74_data_3080[];
extern const float lbl_74_rodata_1C0;
extern "C" Obj* fn_74_CE7C(Obj* self) {
 fn_74_264C(self);
 self->vt = lbl_74_data_2E60;
 self->w15c = -1;
 self->w160 = -1;
 self->p164 = lbl_74_data_3080;
 self->w168 = 0;
 self->w16c = 0;
 self->b150 = 0;
 self->f154 = lbl_74_rodata_1C0;
 self->w158 = 0;
 self->b15c[0] = 0; self->b15c[1] = 0; self->b15c[2] = 0; self->b15c[3] = 0;
 self->b160[0] = 0; self->b160[1] = 0; self->b160[2] = 0; self->b160[3] = 0;
 Sub* s = &self->sub;
 if (s == 0) return self;
 s->f8 = 1;
 ((Class_1E10*)s)->fn_74_6758(0, 15);
 s->p4[1] |= 1;
 return self;
}