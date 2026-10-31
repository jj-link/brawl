#pragma force_active on
struct B { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void f(int, bool, bool); };
struct M { char pad[0x88]; B* b; };
struct O { char pad[0xd8]; M* m; };
extern "C" void fn_96_13910(void* self, O* o, int id) {
    if (id != 0x129) {
        bool t = true;
        o->m->b->f(2, t, t);
    }
}