#include <types.h>
#include <cm/cm_subject.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on
struct Arg { u32 pad[3]; u32 index; };
struct Position { u32 x, y, z; };
extern "C" {
extern nw4r::ut::LinkList<cmSubject, 0> lbl_8049DEDC;
extern const float lbl_805A1F64;
static inline void copyPosition(Position* out, Position* in) {
    __memcpy(out, in, sizeof(Position));
}
void fn_800A3814(Position* out, Arg* arg) {
    nw4r::ut::LinkList<cmSubject, 0>* list = &lbl_8049DEDC;
    u32 count = 0;
    int found = 0;
    cmSubject* selected = 0;
    cmSubject* first = 0;
    if (!list->IsEmpty()) {
        nw4r::ut::LinkList<cmSubject, 0>::Iterator it = list->GetBeginIter();
        for (; it != list->GetEndIter(); it++) {
            u32 flags = *(u32*)((char*)&*it + 8);
            if ((u8)(((flags >> 26) & 7) + 254) <= 1) {
                if (!found) { first = &*it; found = 1; }
                if (count == arg->index) { selected = &*it; break; }
                count++;
            }
        }
    }
    if (selected) {
        copyPosition(out, (Position*)((char*)selected + 16));
        return;
    }
    arg->index = 0;
    if (first) {
        copyPosition(out, (Position*)((char*)first + 16));
        return;
    }
    ((float*)out)[0] = lbl_805A1F64;
    ((float*)out)[1] = lbl_805A1F64;
    ((float*)out)[2] = lbl_805A1F64;
}
}