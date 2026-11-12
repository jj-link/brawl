#include <types.h>
#include <gf/gf_camera.h>

extern s32 g_efScreen;

extern "C" {
void* fn_801647B4();
void fn_80164C0C(void* obj, f32* vec, s32* blk, s32 r6, f32 f1, f32 f2);
u32 __cvt_fp2unsigned(f32);
void fn_8005D7D8(s32 screen, f32 f);
}

class Class_8042EC38;
struct Class_8042EC38_base {
    Class_8042EC38* next;
    char pad04[0x44];
};

class Class_8042EC38 : public Class_8042EC38_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void fn_8005A898();
};

struct Node {
    Node* next;
    Node* prev;
};

struct ListEntry {
    s32 count;
    Node head;
};

struct Arg {
    char pad0[0x40];
    u8 flag;
    char pad41[0xB];
    f32 f4c;
    f32 f50;
    f32 f54;
    char pad58[0xB0];
    ListEntry lists[3];
};

struct BlkData {
    s32 w[12];
};

struct Blk {
    s32 w[12];
    s32 pad[2];
};

#pragma force_active on
#pragma auto_inline off

extern "C" void fn_8005B6F0(Arg* arg0) {
    Blk b;
    Node* sentinel;
    void* obj;
    Node* node = (Node*)gfCameraManager::getManager();
    char* mgr = (char*)node;
    u32 k;
    ListEntry* list;
    f32 vec[3];

    obj = fn_801647B4();

    *(BlkData*)&b = *(BlkData*)mgr;
    vec[0] = *(f32*)(mgr + 0x6C);
    vec[1] = *(f32*)(mgr + 0x70);
    vec[2] = *(f32*)(mgr + 0x74);
    f32 f2 = *(f32*)(mgr + 0xE0);
    f32 f1 = *(f32*)(mgr + 0xDC);
    fn_80164C0C(obj, vec, b.w, b.w[10], f1, f2);

    list = arg0->lists;
    for (k = 0; k < 3; k++) {
        node = list->head.next;
        sentinel = &list->head;
        while (node != sentinel) {
            ((Class_8042EC38*)node)->fn_8005A898();
            node = node->next;
        }
        list++;
    }

    if (!((arg0->flag >> 7) & 1)) {
        b.pad[1] = __cvt_fp2unsigned(arg0->f4c);
        b.pad[0] = 0x43300000;
    }

    arg0->f54 = arg0->f4c;
    fn_8005D7D8(g_efScreen, arg0->f50);
}
