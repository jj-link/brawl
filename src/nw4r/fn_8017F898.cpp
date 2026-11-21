#include <types.h>
#pragma force_active on
#pragma fp_contract off

extern "C" {
extern const float lbl_805A3078;
extern const float lbl_805A30A0;
extern const double lbl_805A3098;

void* fn_80178868(void* self);
int fn_8017FBE4(void* dummy, unsigned short* arg1);
int fn_8017B78C(void* arg0, void* arg1);
int fn_8017FBF0(void* out, void* arg1);
void fn_8017FBFC(void* buf);
void fn_8017E288(void* self, void* buf, void* arg1, int arg3, void* cur, void* a, void* curAc, int arg4, int arg5, float f1, float f2);
void fn_8017EB30(void* self, int arg2, void* a, void* b, void* c, int arg3);
void fn_8017EDDC(void* self, void* a, void* b, void* c, int arg3);
void fn_8017F894(void);
void GXBegin(int prim, int fmt, unsigned short verts);
}

typedef void* (*Fn1)(void*);
typedef void* (*Fn2)(void*, void*);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Fn1 slot2(int);
    virtual Fn2 slot3(int);
    virtual void* slot4(void*);
};

struct Buf { char data[0x1c]; };

extern "C" void fn_8017F898(Object_vptr_0* self, void** arg1, int arg2, int arg3, int arg4, int arg5) {
    Buf buf[3];
    int n;
    int flags;
    u8* data;
    u8* obj;
    void* a;
    Fn1 f1;
    Fn2 f2;
    int old16;
    void* next;
    Buf* e;
    int r18;
    int r17;
    int i16;
    int i15;
    f32 f30;
    f32 f29;
    void* cur;
    unsigned short verts;

    obj = (u8*)*arg1;
    data = (u8*)fn_80178868(*(void**)(obj + 0x24));
    a = self->slot4(obj);
    flags = fn_8017FBE4(self, (unsigned short*)data);
    f1 = self->slot2(flags);
    f2 = self->slot3(flags);
    n = fn_8017B78C(self, obj);
    verts = (unsigned short)((n * arg2 + 1) * 2);
    f30 = lbl_805A30A0 * (f32)(s8)data[0x9d];
    GXBegin(0x98, 0, verts);
    switch (fn_8017FBF0(self, data)) {
    case 0:
    default:
        f29 = lbl_805A3078 / (f32)(n - 1);
        break;
    case 0x40:
        f29 = lbl_805A3078;
        break;
    }
    r18 = 0;
    r17 = 1;
    if (flags != 0) {
        r18 = n - 1;
        r17 = -1;
    }
    fn_8017FBFC(&buf[0]);
    fn_8017FBFC(&buf[1]);
    fn_8017FBFC(&buf[2]);
    i16 = 0;
    i15 = 0;
    cur = f1(obj);
    fn_8017E288(self, &buf[0], arg1, arg3, cur, a, (u8*)cur + 0xac, arg4, arg5, f30, f29 * (f32)r18);
    r18 += r17;
    next = f2(obj, cur);
    while (next != 0) {
        old16 = i16;
        i16 = i15;
        i15 = (i15 + 1) % 3;
        e = &buf[i15];
        fn_8017E288(self, e, arg1, arg3, next, a, (u8*)next + 0xac, arg4, arg5, f30, f29 * (f32)r18);
        fn_8017EB30(self, arg2, &buf[old16], &buf[i16], e, arg3);
        next = f2(obj, next);
        r18 += r17;
    }
    fn_8017EB30(self, arg2, &buf[i16], &buf[i15], &buf[i15], arg3);
    fn_8017EDDC(self, &buf[i16], &buf[i15], &buf[i15], arg3);
    fn_8017F894();
}
