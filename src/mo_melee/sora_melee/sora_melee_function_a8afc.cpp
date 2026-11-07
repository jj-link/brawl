#pragma force_active on
class soNullable { public: virtual void isNull(); virtual void fn_27_A7E40(); virtual void fn_27_A7F04(); virtual void fn_27_A81B8(); virtual void fn_27_A8AEC(); virtual void fn_27_A82BC(); virtual void fn_27_A8AFC(); virtual void fn_27_A8D3C(); virtual void fn_27_A8E30(); virtual void fn_27_A9040(); virtual void fn_27_A901C(); };
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(int,int,int); };
struct Inner { char pad[0x90]; Object_vptr_0* object; };
struct Access { char pad[0xd8]; Inner* inner; };
struct Owner { char pad[0x14]; Access* access; char pad2[0x10]; unsigned int* bits; char pad3[0xd]; unsigned char active; char pad4[2]; int a,b,c,d,e; };
inline unsigned int test(unsigned int bits, unsigned char active, int n) {
 return active == 0 ? 0 : ((1 << n) & bits) != 0;
}
extern "C" void fn_27_A8AFC(Owner* self, int arg) {
 Object_vptr_0* obj = self->access->inner->object;
 int n = self->a;
 if (n != -1) { if (test(*self->bits,self->active,n) == 1) obj->slot12(n,arg,-1); }
 n = self->b;
 if (n != -1) { if (test(*self->bits,self->active,n) == 1) obj->slot12(n,arg,-1); }
 n = self->c;
 if (n != -1) { if (test(*self->bits,self->active,n) == 1) obj->slot12(n,arg,-1); }
 n = self->d;
 if (n != -1) { if (test(*self->bits,self->active,n) == 1) obj->slot12(n,arg,-1); }
 n = self->e;
 if (n != -1) { if (test(*self->bits,self->active,n) == 1) obj->slot12(n,arg,-1); }
}