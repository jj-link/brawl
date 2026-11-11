#pragma force_active on
#pragma fp_contract on
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
struct Vec { float v[4]; Vec(); } __attribute__((aligned(16)));
struct State {
 int countA, countB, limitA, limitB;
 char flag; char pad[3]; int changed; char pad1[8];
 Vec a[4]; Vec unused[4]; Vec b[4]; Vec localB[4];
 Vec dir; float pad3[16]; int status;
 State() : flag(0) {}
};
inline Vec::Vec() {}
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10();
 virtual void slot11(void*, int, Vec*);
 char pad[8]; float radius;
};
struct Body {
 void* transform; float* mat;
 Object_vptr_0* shape_a; Object_vptr_0* shape_b; float threshold;
};
struct Flags { char pad[8]; signed char f0, f1, f2, f3; };
extern "C" int fn_803198C8(State*, Object_vptr_0*, Object_vptr_0*, void*, Vec*);
extern "C" void fn_8031AB44(State*, void*);
extern const float lbl_805A46B8;
inline Object_vptr_0* prepareFirstShape(State* state, Object_vptr_0* shape, int count) {
 state->countA = count;
 return shape;
}
inline void addScaled(Vec* out, float t, const Vec& direction, const float* base) {
 float x = t * direction.v[0] + base[0];
 float y = t * direction.v[1] + base[1];
 float z = t * direction.v[2] + base[2];
 float w = t * direction.v[3] + base[3];
 out->v[0] = x; out->v[1] = y; out->v[2] = z; out->v[3] = w;
}
extern "C" int fn_8031AD90(Body* __restrict body, Flags* flags, Vec* out1, Vec* out2) {
 Vec v;
 Vec result;
 State state;
 Object_vptr_0* shapeB = body->shape_b;
 Object_vptr_0* shapeA = prepareFirstShape(&state, body->shape_a, flags->f0);
 state.countB = flags->f1;
 state.limitA = flags->f2;
 state.limitB = flags->f3;
 state.changed = 0;
 shapeA->slot11(flags, state.countA, state.a);
 shapeB->slot11((char*)flags + state.countA * 2, state.countB, state.localB);
 fn_803198C8(&state, body->shape_a, body->shape_b, body->transform, &v);
 if (state.changed) fn_8031AB44(&state, flags);
 Object_vptr_0* first = body->shape_a;
 Object_vptr_0* second = body->shape_b;
 float* m = body->mat;
 float w_a = first->radius;
 float x = v.v[0], y = v.v[1], z = v.v[2];
 float w_b = second->radius;
 float diff = (v.v[3] - w_a) - w_b;
 out1->v[0] = z * m[8] + (x * m[0] + y * m[4]);
 out1->v[1] = z * m[9] + (x * m[1] + y * m[5]);
 out1->v[2] = z * m[10] + (x * m[2] + y * m[6]);
 out1->v[3] = diff;
 if (diff < body->threshold) {
  if (state.countA == 1) {
   float t = second->radius - v.v[3];
   addScaled(&result, t, v, state.a[0].v);
  } else if (state.countB == 1) {
   float t = second->radius;
   addScaled(&result, t, v, state.b[0].v);
  } else {
   float t = second->radius - v.v[3];
   addScaled(&result, t, v, state.pad3);
  }
  m = body->mat;
  float pz = result.v[2], py = result.v[1], px = result.v[0];
  out2->v[0] = m[12] + (pz * m[8] + (px * m[0] + py * m[4]));
  out2->v[1] = m[13] + (pz * m[9] + (px * m[1] + py * m[5]));
  out2->v[2] = m[14] + (pz * m[10] + (px * m[2] + py * m[6]));
  out2->v[3] = lbl_805A46B8;
  return 0;
 }
 return 1;
}
