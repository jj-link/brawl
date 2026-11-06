#include <types.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual s32* slot1(s32 idx);
    virtual void slot2();
    virtual void slot3();
    virtual u32 slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(s16* a, void* b, void* c, s32 d, s32 e);
    virtual void slot9();
    virtual void slot10(s32* out);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual u32 slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
};
struct Object_vptr_3c_base { char pad[0x3c]; };
class Object_vptr_3c : public Object_vptr_3c_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual s32 slot42(s32 id);
};
class Ctr {
public:
    char pad[0xc];
    s32 cnt;
};
struct Mid {
    char pad0[0x64];
    Ctr* unk64;
    char pad1[4];
    Object_vptr_0* unk6C;
};
struct Ctx {
    char pad0[8];
    Object_vptr_3c* unk8;
    char pad1[0xcc];
    Mid* unkD8;
};
struct Req16 {
    s16 a;
    s16 b;
    s32 c;
    s32 d;
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_73C90();
    virtual void fn_27_73D24();
    virtual void fn_27_74B94();
    virtual void fn_27_75684();
    virtual void fn_27_758E4();
    virtual void fn_27_73DA4();
    virtual void fn_27_73E50();
    virtual void fn_27_73EFC();
    virtual void fn_27_73FA8();
    virtual void fn_27_74054();
    virtual void fn_27_74100();
    virtual void fn_27_741AC();
    virtual void fn_27_74274();
    virtual void fn_27_74334();
    virtual void fn_27_7440C();
    virtual void fn_27_75498();
    virtual void fn_27_75E04();
    virtual void fn_27_75A48();
    virtual void fn_27_75DF8();
    virtual void fn_27_75DF0();
    virtual void fn_27_746B0();
    virtual void fn_27_75DDC();
    virtual void fn_27_75DC8();
    virtual void fn_27_75DB4();
    virtual void fn_27_75DA0();
    virtual void fn_27_75D8C();
    virtual void fn_27_75D78();
    virtual void fn_27_74B08();
    virtual void fn_27_749F8();
    virtual void fn_27_74A04();
    virtual void fn_27_74A7C();
    virtual void fn_27_758F0();
    virtual void fn_27_75C9C();
    virtual void fn_27_74E9C();
    virtual void fn_27_75B18();
    virtual void fn_27_75B2C();
    virtual void fn_27_75B6C();
    virtual void fn_27_74FB0(s32 id, Ctx* ctx);

    char pad4[0x34];
    s32 unk38;
    char pad3C[8];
    void** unk44;
    s32 unk48;
    Object_vptr_0 inner;
    char pad50[0x2c];
    u8 flag7c;
};

extern "C" s32 fn_27_74B94(soNullable* self, s32 arg1, Ctx* ctx) {
    struct Locals {
        s32 sp8;
        s16 spC;
        Req16 req;
    } locals;
    locals.sp8 = arg1;
    s32 id;
    gfTaskScheduler* sched = gfTaskScheduler::getInstance();

    if (sched != NULL) {
        s32 t = (s32)((((u32)*(u32*)sched) << 8) & 0xFF800000) >> 24;
        if (t <= 1 || t >= 6) {
            if ((&self->inner)->slot4() != 1) {
                while ((&self->inner)->slot4() == 0) {
                    id = *(&self->inner)->slot1(0);
                    (&self->inner)->slot6();
                    if (ctx->unk8->slot42(id)) {
                        ctx->unkD8->unk64->cnt++;
                        self->unk38 = id;
                        if (self->unk44 != NULL && id > -1 && id < self->unk48 && self->unk44[id] != NULL) {
                            locals.req.a = 1;
                            ctx->unkD8->unk6C->slot8(&locals.req.a, self->unk44[id], ctx, 1, 0);
                        }
                        self->fn_27_74FB0(self->unk38, ctx);
                        if (ctx->unkD8->unk64->cnt > 0) {
                            ctx->unkD8->unk64->cnt--;
                        }
                    }
                }
            }

            self->flag7c = 1;
            id = locals.sp8;
            if (ctx->unk8->slot42(id)) {
                ctx->unkD8->unk64->cnt++;
                self->unk38 = id;
                if (self->unk44 != NULL && id > -1 && id < self->unk48 && self->unk44[id] != NULL) {
                    locals.spC = 1;
                    ctx->unkD8->unk6C->slot8(&locals.spC, self->unk44[id], ctx, 1, 0);
                }
                self->fn_27_74FB0(self->unk38, ctx);
                if (ctx->unkD8->unk64->cnt > 0) {
                    ctx->unkD8->unk64->cnt--;
                }
            }
            return 1;
        }
    }

    if ((&self->inner)->slot14() != 1) {
        (&self->inner)->slot10(&locals.sp8);
    }
    return 0;
}
