#pragma force_active on
struct S2 { char pad[0x72]; unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1; };
struct S1 { char pad[4]; S2* p; };
struct V { virtual void a(); virtual S1* get(); };
struct T { char pad[0x28]; V* v; };
extern "C" bool fn_27_27888(T* __restrict t) {
    V* v = t->v;
    S1* r = v->get();
    S2* s = r->p;
    return ((s->b6 << 1) | s->b5) & 1;
}
