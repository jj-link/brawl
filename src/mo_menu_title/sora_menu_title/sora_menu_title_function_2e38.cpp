#pragma force_active on
extern "C" {
void fn_8007F148(void*);
void* fn_8007EF70(void*, int, int, int, int);

void fn_24_2E38(void* self) {
    fn_8007F148(*(void**)((char*)self + 0x54));
    fn_8007EF70(*(void**)((char*)self + 0x54), 0, 0, -1, -1);
}
}
