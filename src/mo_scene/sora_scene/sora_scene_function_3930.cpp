#pragma force_active on
extern "C" {
extern char lbl_1_data_128[];
extern void* g_ftManager;
int fn_27_109478(void*, int, int, int, int);
int fn_27_109490(void*, int);
void fn_27_1095D8(void*, int, int);
}
struct Scene3930 { char pad[0x1c]; int id; int state; int count; int entries[8]; };
extern "C" int fn_1_3930(Scene3930* self) {
 char* data = lbl_1_data_128;
 int state = self->state;
 if (state == 0x513) goto e8;
 if (state >= 0x513) goto b6;
 if (state == 0x50a) goto l9;
 if (state >= 0x50a) goto ret;
 if (state == 0) goto l8;
 goto ret;
b6: if (state == 0x518) goto a40;
 goto ret;
l8: self->id = *(int*)(data + 0x150); self->state = 0x50a;
l9: self->count = 0; goto a70;
a4: self->entries[self->count] = fn_27_109478(g_ftManager, self->count + 0x2e, 0, 0, self->count + 3); goto e8;
b11: self->id = *(int*)(data + 0x154); self->state = 0x513; goto ret;
e8: if (fn_27_109490(g_ftManager, self->entries[self->count]) == 0) goto b11;
 fn_27_1095D8(g_ftManager, self->entries[self->count], 0); goto a40;
b14: self->id = *(int*)(data + 0x158); self->state = 0x518; goto ret;
a40: if (fn_27_109490(g_ftManager, self->entries[self->count]) == 0) goto b14;
 self->count = self->count + 1; goto a70;
a70: if (self->count < 4) goto a4;
 self->id = *(int*)(data + 0x15c); self->state = 0x51d;
ret: return self->count < 4;
}