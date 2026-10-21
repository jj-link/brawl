#pragma force_active on
extern "C" {
void fn_802B193C(void* self);
extern char lbl_80486B68[];

void* fn_802B2870(void* self) {
    fn_802B193C(self);
    *(int*)((char*)self + 0x30) = 0;
    *(char**)self = lbl_80486B68;
    return self;
}
}
