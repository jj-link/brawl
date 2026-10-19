#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    u8 pad[0x4c];
    u8 key;
};

struct FnNode {
    s32 pad;
    FnNode *next;
    FnObj *obj;
};

struct FnOwner {
    u8 pad[0x40];
    FnNode *head;
    u32 gap;
    FnNode *cur;
    u32 count;
};

extern "C" void fn_27_271FDC(FnObj *obj, s32 a1, s32 a2, s32 a3);

extern "C" void fn_27_271BA4(FnOwner *self, s32 a1, u32 key, s32 a3, s32 a4)
{
    u32 n = self->count;
    self->cur = self->head;
    for (u32 i = 0; i < n; i++) {
        FnNode *node = self->cur;
        FnObj *obj = node->obj;
        if (key == obj->key) {
            return fn_27_271FDC(obj, a1, a3, a4);
        }
        self->cur = node->next;
    }
}
