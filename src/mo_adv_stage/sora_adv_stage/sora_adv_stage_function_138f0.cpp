#pragma force_active on
struct Params { char pad[0x66]; unsigned char count; char pad67[0x15]; unsigned short id; };
struct Slot { unsigned char active; char pad[0x1b]; };
struct Self { char pad[0x90]; Params* params; Slot* slots; };
struct List { char pad[0x188]; int capacity; int count; };
extern "C" {
extern List* lbl_27_bss_5B98;
extern char lbl_40_data_2984[];
void fn_40_B48(const char*, ...);
int fn_40_12F14(Self*, int, void*);
}
inline int findSlot(Self* self, Params* params) {
    for (int slot = 0; slot < params->count; slot++) {
        if (self->slots[slot].active == 0) return slot;
    }
    return -1;
}
extern "C" int fn_40_138F0(Self* self, unsigned int id, void* over) {
    Params* params = self->params;
    if (params->id != id) return -1;
    int slot;
    if (lbl_27_bss_5B98 && lbl_27_bss_5B98->count >= lbl_27_bss_5B98->capacity) {
        fn_40_B48(lbl_40_data_2984);
        slot = -1;
    } else {
        slot = findSlot(self, params);
    }
    if (slot >= 0) return fn_40_12F14(self, slot, over);
    return -1;
}