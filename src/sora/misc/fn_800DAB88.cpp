#pragma force_active on
extern "C" {
void fn_800307B4(void*);
void exit__6gfTaskFv(void*);

void fn_800DAB88(void* self) {
    if (*(int*)((char*)self + 0x60))
        fn_800307B4(self);
    exit__6gfTaskFv(self);
}
}
