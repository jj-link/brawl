#pragma force_active on
extern "C" void fn_113_263DC(void*, void*);
extern "C" const float lbl_113_rodata_128;
struct Iface {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
 virtual void v5(int, unsigned int);
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12();
 virtual void v13(float, unsigned int);
 virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(unsigned int);
};
struct Mid { char pad[0x64]; Iface* iface; };
struct Ft { char pad[0xd8]; Mid* mid; };
extern "C" void fn_113_26AE4(void* a, Ft* b) {
 fn_113_263DC(a,b);
 b->mid->iface->v5(0x5a,0x20000001);
 b->mid->iface->v5(0x5a,0x20000000);
 b->mid->iface->v13(lbl_113_rodata_128,0x21000001);
 b->mid->iface->v18(0x22000000);
}