#pragma force_active on
struct Inner { unsigned int f00; float f04,f08,f0C,f10; char f14,f15,f16,f17,f18,f19; short f1A,f1C,f1E,f20,f22,f24,f26,f28,f2A,f2C,f2E; };
extern "C" void fn_801B5DC8(Inner** arg) {
 Inner* obj=*arg;
 if (!obj) return;
 int zero=0;
 obj->f00=0;
 float v=0.0f;
 obj->f04=v; obj->f08=v; obj->f0C=v; obj->f10=v;
 obj->f17=zero; obj->f16=zero; obj->f15=zero; obj->f14=zero; obj->f18=zero; obj->f19=zero;
 obj->f1A=zero; obj->f1C=zero; obj->f1E=zero; obj->f20=zero; obj->f22=zero; obj->f24=zero; obj->f26=zero; obj->f28=zero; obj->f2A=zero; obj->f2C=zero; obj->f2E=zero;
}