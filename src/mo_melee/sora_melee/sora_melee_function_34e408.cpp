#pragma force_active on
#include <ft/ft_common_data_accesser.h>

struct LocalVec {
    float x, y, z;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void* slot21(int);
};

struct Class_90D8_base {
    char pad[8];
};

class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void* fn_27_7B2EC(void*);
};

struct X {
    Class_90D8* y;
};

struct Ctx8 {
    char pad[0x28];
    void* v;
};

struct Ctx {
    char pad[8];
    Ctx8* c8;
    char pad2[0xcc];
    X* x;
};

extern "C" {
extern char lbl_27_data_8D9E8[];
extern char lbl_27_data_C938[];
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
extern char lbl_27_data_31AD8[];
extern float lbl_27_rodata_7910;

void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_34E608(void*, void*, void*, void*);
void fn_27_1E1B14(
    void*, void*, void*, void*, int, int, LocalVec*,
    unsigned int, unsigned int, int, int, int, int, int, int, int, int, int
);
}

static inline int build13(void* self, Object_vptr_0* obj, Ctx* ctx) {
    void* castObj = __dynamic_cast(
        obj, 0, lbl_27_data_8D9E8, lbl_27_data_C938, 0
    );
    Object_vptr_0* d = (Object_vptr_0*)__dynamic_cast(
        ctx->x->y->fn_27_7B2EC(ctx->x),
        0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1
    );
    return fn_27_34E608(self, castObj, ctx, d->slot21(0x12));
}

extern "C" int fn_27_34E408(void* self, Object_vptr_0* obj, Ctx* ctx) {
    void* id;
    void* castObj;

    switch (obj->slot6()) {
    case 13: {
        castObj = __dynamic_cast(
            obj, 0, lbl_27_data_8D9E8, lbl_27_data_C938, 0
        );
        Object_vptr_0* d = (Object_vptr_0*)__dynamic_cast(
            ctx->x->y->fn_27_7B2EC(ctx->x),
            0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1
        );
        return fn_27_34E608(self, castObj, ctx, d->slot21(0x12));
    }
    case 14: {
        LocalVec v;
        void** r29 = *(void***)((char*)g_ftCommonDataAccesser.getData((ftKind)5) + 0x64);
        v.x = lbl_27_rodata_7910;
        v.y = lbl_27_rodata_7910;
        v.z = lbl_27_rodata_7910;

        id = ctx->c8->v;
        Class_90D8* y = ctx->x->y;
        void* ret = y->fn_27_7B2EC(ctx->c8);
        Object_vptr_0* d = (Object_vptr_0*)__dynamic_cast(
            ret, 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1
        );
        castObj = d->slot21(0x12);
        obj = (Object_vptr_0*)__dynamic_cast(
            obj, 0, lbl_27_data_31AD8, lbl_27_data_C938, 1
        );
        char* params = (char*)*r29 + 0xa8;
        fn_27_1E1B14(
            obj, id, castObj, params, 0, 0, &v,
            0xffff, 0xffff, 0, 1, 0, -1, 0, 0, 2, 0, 1
        );
        return 1;
    }
    default:
        return 0;
    }
}
