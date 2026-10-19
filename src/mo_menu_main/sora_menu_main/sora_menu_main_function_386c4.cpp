#pragma force_active on
extern "C" {
void fn_800307B4(void*);
void exit__6gfTaskFv(void*);

void fn_2_386C4(void* self) {
    if (*(int*)((char*)self + 0x1EC))
        fn_800307B4(self);
    exit__6gfTaskFv(self);
}
}
