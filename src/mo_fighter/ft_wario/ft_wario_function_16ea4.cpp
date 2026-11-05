#pragma force_active on
struct ObjA {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
 virtual void v5(int, int);
 virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
 virtual int v17(unsigned int);
 virtual void v18(unsigned int);
 virtual void v19(unsigned int);
};
struct Data { int value; char flag; };
struct ObjB {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
 virtual void v15(int, Data*);
};
struct ObjC {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
 virtual int v32(int);
};
struct Inner { char pad[0x54]; ObjB* b; char pad2[0xc]; ObjA* a; char pad3[8]; ObjC* c; };
struct Holder { char pad[0xd8]; Inner* inner; };
extern "C" void fn_110_16EA4(void*, Holder* h) {
 ObjA* a = h->inner->a;
 ObjB* b = h->inner->b;
 if (a->v17(0x22000000)) {
  a->v19(0x22000000);
 } else {
  Data data;
  data.value = 0x838;
  data.flag = 0;
  b->v15(3, &data);
 }
 a->v19(0x22000002);
 int result = h->inner->c->v32(0);
 if (result != 3 && result != 14) {
  a->v19(0x2200000a);
 }
 a->v5(0, 0x20000004);
 a->v18(0x2200000c);
}