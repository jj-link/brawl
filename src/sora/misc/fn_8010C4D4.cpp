#pragma force_active on
#include <mu/mu_object.h>
extern const float lbl_805A2870;
struct Obj { MuObject* entries[194]; int unk308; };
extern "C" void fn_8010C4D4(Obj* self, int arg1) {
 float frame = lbl_805A2870;
 self->unk308 = arg1;
 self->entries[arg1 + 13]->setFrameNode(frame);
 self->entries[self->unk308 + 13]->setFrameMatCol(lbl_805A2870);
}
