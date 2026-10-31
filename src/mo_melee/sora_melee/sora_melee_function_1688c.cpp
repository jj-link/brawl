#pragma force_active on

#include <types.h>
#include <nw4r/g3d/g3d_anmchr.h>

struct Big3 {
    f32 a;
    f32 b;
    f32 c;

    Big3() {}
    Big3(const Big3& other)
        : a(other.a), b(other.b), c(other.c) {}
};

struct AObj {
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
    virtual void set(s32, void*);
    virtual void v16();
    virtual void v17();
    virtual void setFrame(s32, f32);
};

struct ObjBase {
    u32 a;
    u32 b;
};

struct Obj : ObjBase {
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
    virtual Big3 getTransform(void*, s32);
    virtual void v36();
    virtual void v37();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void setAnimation(void*);
    virtual void clearAnimation(s32);
};

struct ArrObj {
    virtual void v0();
    virtual void* get(s32);
    virtual void v2();
    virtual s32 size();
};

struct N {
    u32 m0;
    Obj* m4;
};

struct M {
    u8 pad[0xD8];
    N* mD8;
};

struct T {
    u8 pad[0x94];
    AObj* m94;
    u8 pad2[0x168 - 0x98];
    M* m168;
};

extern "C" {
    nw4r::g3d::AnmObjChrRes* fn_27_151A4(
        T*, s32, s32, s32, s32, s32
    );

    extern const f32 lbl_27_rodata_340;
    extern const f32 lbl_27_rodata_344;

    void fn_27_1688C(T* self, s32 arg1, ArrObj* arrA, ArrObj* arrB)
    {
        nw4r::g3d::AnmObjChrRes* res;
        s32 i;
        s32 n;

        res = fn_27_151A4(self, arg1, -1, 1, 0, 1);

        if (res != 0) {
            if (self->m94 != 0) {
                self->m94->set(0, res);
                self->m94->setFrame(0, lbl_27_rodata_340);
                self->m94->setFrame(1, lbl_27_rodata_344);
                self->m168->mD8->m4->setAnimation(self->m94);
            } else {
                self->m168->mD8->m4->setAnimation(res);
            }

            self->m168->mD8->m4->v7();

            n = arrA->size();
            for (i = 0; i < n; i++) {
                Big3 value = self->m168->mD8->m4->getTransform(
                    *(void**)arrA->get(i), 0
                );
                Big3* dest = (Big3*)arrB->get(i);
                dest->a = value.a;
                dest->b = value.b;
                dest->c = value.c;
            }

            res->Destroy();
            self->m168->mD8->m4->clearAnimation(0);
        }
    }
}
