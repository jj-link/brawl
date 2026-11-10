#include <types.h>
#pragma force_active on

class Sub {
public:
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
    virtual void v12(s32 a, s32 b, s32 c);
};

class Obj {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 v8();
    virtual s32 v9(s32 a);
    virtual void v10(s32 a, s32 b);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14(f32 a, f32 b);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual s32 v22();
    virtual s32 v23(f32 a, f32 b);

    s32 pad[9];
    Sub* sub;
};

extern "C" s32 fn_80278F5C(Obj* obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 f1, f32 f2) {
    s32 ret = 0;
    if (obj->v22() != 0) {
        if (obj->v23(f1, f2) != 0) {
            if (obj->v9(a1) != 0) {
                obj->v14(f1, f2);
                s32 r = obj->v8();
                obj->sub->v12(r, 3, a5);
            } else {
                obj->v10(a1, 1);
                obj->v11();
                s32 r = obj->v8();
                obj->sub->v12(r, 1, a5);
            }
            ret = 1;
        } else if (obj->v9(a1) != 0) {
            obj->v10(a1, 0);
            obj->v12();
            s32 r = obj->v8();
            obj->sub->v12(r, 2, a5);
        }
    }
    return ret;
}
