#pragma force_active on

typedef int s32;
typedef short s16;

struct FnDst {
    s32 a;
    s32 b;
    s16 c;
    s16 d;
};

struct SubObj {
    virtual void v08();
    virtual void v0c();
    virtual void* v10(s32);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34(s32, FnDst*);
    virtual void v38();
    virtual void v3c();
    virtual unsigned int v40();
};

struct MainObj {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual s32 v18();
    virtual void v1c();
    virtual unsigned int v20(s32);

    char pad04[0xC];
    SubObj sub;
    char pad14[0x38];
    unsigned char flag;

    s32 find(s16 limit) {
        if (limit <= -1)
            return v18();

        s32 count = v18();
        for (s32 i = 0; i < count; ++i) {
            s16 value = *(s16*)((char*)sub.v10(i) + 0xA);
            if (value <= -1) {
                return i;
            } else if (value <= limit) {
                continue;
            } else {
                return i;
            }
        }
        return count;
    }
};

extern "C" s32 fn_27_1E79D8(MainObj*);
extern "C" void fn_27_FE14C(FnDst*, s32*, s32, s16*, s16);

extern "C" s32 fn_27_1E71C0(
    MainObj* self, s32* arg1, s32 arg2, s16* arg3, s16 arg4)
{
    if (self->sub.v40() == 1U)
        return -1;

    if ((self->flag == 0 || arg2 > -1) && self->v20(arg2) == 1U)
        return -1;

    if (self->flag == 0 && arg2 <= -1) {
        arg2 = fn_27_1E79D8(self);
        if (arg2 <= -1)
            return -1;
    }

    s32 index = self->find(arg4);
    if (index < 0)
        return -1;

    s16 value = *arg3;
    FnDst dst;
    fn_27_FE14C(&dst, arg1, arg2, &value, arg4);
    self->sub.v34(index, &dst);
    return arg2;
}
