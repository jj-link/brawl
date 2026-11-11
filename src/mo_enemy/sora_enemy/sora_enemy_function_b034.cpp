#pragma force_active on
struct Vec3f { float x,y,z; };
extern "C" void fn_41_534C(Vec3f*, const Vec3f*);
struct Data { void* p; Vec3f pos; float f; int a; unsigned char b; int c; };
class ObjA { public:
virtual void v0();
virtual void v1();
virtual void* v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19(unsigned int);
};
struct Pad8 { int a,b; };
class ObjB : public Pad8 { public:
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13();
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17();
virtual void v18();
virtual void v19();
virtual void v20();
virtual void v21();
virtual void v22();
virtual void v23();
virtual void v24();
virtual void v25();
virtual void v26();
virtual void v27();
virtual void v28();
virtual void v29();
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33();
virtual void v34();
virtual void v35();
virtual void v36();
virtual Vec3f v37(int,int,bool,bool);
};
inline void init(Data& d, const Vec3f& v, float f, int a, unsigned char b, void* self) {
 fn_41_534C(&d.pos, &v); d.f=f; d.a=a; d.b=b; d.c=*(int*)((char*)self+0xB0);
}
extern "C" bool fn_41_AEC8(void*, int, int);
extern "C" void fn_41_AFA0(void*, int, void*, int, int, unsigned int);
extern "C" unsigned int fn_27_2331C4(void*, int);
extern void* g_stTriggerMng;
extern "C" void fn_41_B034(void* self, int id, int arg2, int arg3, float farg, int arg4, unsigned char arg5, int arg6, int arg7, int arg_sp) {
 if (arg5 >= 1 || *(unsigned int*)((char*)self + 0xBC) <= 5) {
  if (fn_41_AEC8(self, id, arg_sp)) {
   ObjA* a = *(ObjA**)((char*)*(void**)((char*)self + 0x1B4) + 0x18);
   ObjA* b = (ObjA*)a->v2();
   Data data; data.p = b->v2();
   ObjB* ptr4 = *(ObjB**)((char*)*(void**)((char*)self + 0x1B4) + 0x4);
   init(data, ptr4->v37(arg2, arg3, 0, 0), farg, arg4, arg5, self);
   if (arg_sp == -1) {
    unsigned int count = fn_27_2331C4(g_stTriggerMng, id);
    for (unsigned int i = 0; i < count; i++) {
     fn_41_AFA0(self, id, &data, arg6, arg7, i);
     ObjA* inner = *(ObjA**)((char*)*(void**)((char*)self + 0x60) + 0xD8);
     inner = *(ObjA**)((char*)inner + 0x64);
     inner->v19(0x12000011);
    }
   } else {
    fn_41_AFA0(self, id, &data, arg6, arg7, arg_sp);
    ObjA* inner = *(ObjA**)((char*)*(void**)((char*)self + 0x60) + 0xD8);
    inner = *(ObjA**)((char*)inner + 0x64);
    inner->v19(0x12000011);
   }
  }
 }
}