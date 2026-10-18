#pragma force_active on
typedef struct Fn93Obj {
    int a;
    unsigned char b;
    int c;
} Fn93Obj;

typedef struct Fn93Local {
    int a;
    unsigned char b;
    int c;
    int d;
    int e;
} Fn93Local;

extern "C" void fn_93_10090(Fn93Obj *obj);

struct Fn93Base {
    int x;
    int y;
};

class Fn93Q : public Fn93Base {
public:
    virtual int v0(int, void *, int); virtual int v1(int, void *, int); virtual int v2(int, void *, int);
    virtual int v3(int, void *, int); virtual int v4(int, void *, int); virtual int v5(int, void *, int);
    virtual int v6(int, void *, int); virtual int v7(int, void *, int); virtual int v8(int, void *, int);
    virtual int v9(int, void *, int); virtual int v10(int, void *, int); virtual int v11(int, void *, int);
    virtual int v12(int, void *, int); virtual int v13(int, void *, int); virtual int v14(int, void *, int);
    virtual int v15(int, void *, int); virtual int v16(int, void *, int); virtual int v17(int, void *, int);
    virtual int v18(int, void *, int); virtual int v19(int, void *, int); virtual int v20(int, void *, int);
    virtual int v21(int, void *, int); virtual int v22(int, void *, int); virtual int v23(int, void *, int);
    virtual int v24(int, void *, int); virtual int v25(int, void *, int); virtual int v26(int, void *, int);
    virtual int v27(int, void *, int); virtual int v28(int, void *, int); virtual int v29(int, void *, int);
    virtual int v30(int, void *, int); virtual int v31(int, void *, int); virtual int v32(int, void *, int);
    virtual int v33(int); virtual int v34(int, void *, int); virtual int v35(int, void *, int);
};

class Fn93If {
public:
    virtual int v0(int, void *, int); virtual int v1(int, void *, int); virtual int v2(int, void *, int);
    virtual int v3(int, void *, int); virtual int v4(int, void *, int); virtual int v5(int, void *, int);
    virtual int v6(int, void *, int); virtual int v7(int, void *, int); virtual int v8(int, void *, int);
    virtual int v9(int, void *, int); virtual int v10(int, void *, int); virtual int v11(int, void *, int);
    virtual int v12(int, void *, int); virtual int v13(int, void *, int); virtual int v14(int, void *, int);
    virtual int v15(int, void *, int); virtual int v16(int, Fn93Local *, int); virtual int v17(int, void *, int);
    virtual int v18(int); virtual int v19(int, void *, int); virtual int v20(int, void *, int);
    virtual int v21(int, void *, int); virtual int v22(int, void *, int); virtual int v23(int, void *, int);
    virtual int v24(int, void *, int); virtual int v25(int, void *, int); virtual int v26(int, void *, int);
    virtual int v27(int, void *, int); virtual int v28(int, void *, int); virtual int v29(int, void *, int);
    virtual int v30(int, void *, int); virtual int v31(int, void *, int); virtual int v32(int, void *, int);
    virtual int v33(int, void *, int); virtual int v34(int, void *, int); virtual int v35(int, void *, int);
};

#define FN93_FIELD(p, t, o) (*(t*)((char*)(p) + (o)))

extern "C" void fn_93_10630(void *unused, Fn93Obj *obj)
{
    Fn93Local local;
    fn_93_10090((Fn93Obj *)&local);
    local.c = 3;
    local.d = ((Fn93Q *)FN93_FIELD(FN93_FIELD(obj, void *, 0xd8), void *, 0x4))->v33(0x12c);

    Fn93If *s = (Fn93If *)FN93_FIELD(FN93_FIELD(obj, void *, 0xd8), void *, 0x54);
    s->v16(0, &local, 0);

    Fn93If *t = (Fn93If *)FN93_FIELD(FN93_FIELD(obj, void *, 0xd8), void *, 0x64);
    t->v18(0x22000016);
}
