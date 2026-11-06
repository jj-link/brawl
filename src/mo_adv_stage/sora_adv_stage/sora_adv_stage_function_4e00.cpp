#pragma force_active on
#include <st/st_trigger.h>
#include <types.h>

struct RbIVec {
    s32 x;
    s32 y;
};

struct RbVec {
    f32 x;
    f32 y;
};

struct RbPos {
    RbIVec p0;
    RbVec pa;
    RbVec pb;
};

struct RbList {
    char pad[0x152];
    u16 count;
    RbPos* list;
};

struct RbOwner {
    char pad[0x578];
    RbList* rebirth;
};

struct RbCB {
    s32 m0;
    void* m4;
    s32 m8;
    RbPos pos;
};

struct RbBox {
    RbVec max;
    RbVec min;
};

extern "C" {
extern int lbl_40_data_724;
RbPos* fn_40_2E3CC(RbList* self, int index);
void fn_27_234414(stTrigger* trigger, RbVec* lo, RbVec* hi, int flag);
void fn_27_233F58(stTrigger* trigger, void* cb);
}

extern "C" void fn_40_4E00(RbOwner* self) {
    RbList* list = self->rebirth;
    if (list != 0) {
        u16 count = list->count;
        for (u32 i = 0; i < count; i++) {
            RbPos* e = fn_40_2E3CC(self->rebirth, i);
            stTrigger* trigger = g_stTriggerMng->createTrigger((Gimmick::AreaKind)5, -1);
            RbBox box;
            RbBox tmp;
            if (e->pb.x < e->pa.x) {
                box.min.x = e->pb.x;
                box.max.x = e->pa.x;
            } else {
                box.min.x = e->pa.x;
                box.max.x = e->pb.x;
            }
            if (e->pb.y < e->pa.y) {
                box.min.y = e->pb.y;
                box.max.y = e->pa.y;
            } else {
                box.min.y = e->pa.y;
                box.max.y = e->pb.y;
            }
            tmp = box;
            fn_27_234414(trigger, &tmp.min, &tmp.max, 0);
            RbCB* cb = (RbCB*)operator new(0x24, (Heaps::HeapType)0xf);
            if (cb != 0) {
                cb->m0 = 0;
                cb->m8 = 0;
                cb->m4 = &lbl_40_data_724;
                cb->pos = *e;
            }
            fn_27_233F58(trigger, cb);
        }
    }
}
