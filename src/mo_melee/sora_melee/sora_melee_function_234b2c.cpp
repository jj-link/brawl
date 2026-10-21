#include <st/st_trigger.h>
#include <types.h>
#pragma force_active on

struct FnNode {
    FnNode* next;
    u32 pad4;
    u32 pad8;
    int id;
    u8 kind;
};

extern "C" {
FnNode* fn_27_232304(const void* self, int id, u32 kind);
}

struct stTriggerDataHead {
    u16 id;
    u8 pad2;
    u8 kind;
};

struct TriggerList {
    char pad[0x10];
    void* arr[5];
    u32 count;
};

extern "C" bool fn_27_234B2C(void* self, stTriggerDataHead* data) {
    if (g_stTriggerMng != 0) {
        FnNode* node = fn_27_232304(g_stTriggerMng, data->id, data->kind);
        if (node == 0) {
            node = (FnNode*)g_stTriggerMng->createTrigger((Gimmick::AreaKind)0, (stTriggerData*)data);
        }
        if (node != 0) {
            TriggerList* w = (TriggerList*)self;
            w->arr[w->count] = (char*)node + 0x2c;
            w->count = w->count + 1;
            return true;
        }
    }
    return false;
}
