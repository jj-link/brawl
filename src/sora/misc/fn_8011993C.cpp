#include <types.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

struct Node {
    u8 pad[0xE];
    u8 flagsE;
    u8 flagsF;
};
struct Record {
    Node* node;
    u32 unk4;
    void* owner;
};
struct Segment {
    float x1, y1, x2, y2, extra;
};
extern "C" {
int fn_80113DF8(void*, Record*);
int fn_80113EC0(void*, Record*);
void fn_80111968(void*, Segment*, Node*, int);
extern float lbl_805A2980;

int fn_8011993C(Node self, void* arg1, Record* rec) {
    int result;
    if (self.flagsE & 4)
        result = fn_80113DF8(arg1, rec);
    else
        result = fn_80113EC0(arg1, rec);
    if (result != 0) {
        Segment seg;
        fn_80111968(rec->owner, &seg, rec->node, 0);
        if (seg.y1 >= seg.y2)
            result = 0;
        if (!((rec->node->flagsF >> 3) & 1))
            result = 0;
        if ((float)(double)nw4r::ut::Abs(seg.y2 - seg.y1) < lbl_805A2980)
            result = 0;
    }
    return result;
}
}
