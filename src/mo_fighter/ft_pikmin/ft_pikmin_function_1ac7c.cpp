#pragma force_active on
struct V {
    virtual void v2(); virtual void v3();
    virtual void v4(); virtual void c14(int, void*); virtual void v6(); virtual void c1C(int, int);
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void c50(int);
    virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void cF0(int, int);
};
struct M { char p[0x1c]; V* a; char q[0x64-0x20]; V* b; char r[0x70-0x68]; V* c; };
struct O { char p[0xd8]; M* m; };
struct R { char p[0x60]; O* o; };

extern "C" void fn_113_1AC7C(R* self, int a, int b, int c) {
    self->o->m->b->c50(0x12000005);
    O* o = self->o;
    o->m->c->c14(0x2e, o);
    self->o->m->b->c1C(a, 0x20000000);
    self->o->m->b->c1C(b, 0x20000001);
    if (c >= 0) {
        self->o->m->b->c1C(c, 0x1000000D);
        self->o->m->a->cF0(0, c);
    } else {
        self->o->m->b->c1C(-1, 0x1000000D);
    }
}
