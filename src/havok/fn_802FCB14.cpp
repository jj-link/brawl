#pragma force_active on
extern "C" void fn_8027CE3C(void* self, int n);
extern "C" void* fn_8027EA20(void* heap, unsigned int size, int align);
extern "C" void* lbl_805A0EC8;

extern "C" void fn_802FCB14(char* self) {
    *(int*)(self + 0x4) = 0;
    if (*(int*)(self + 0x4) == (int)(*(unsigned int*)(self + 0x8) & 0x3FFFFFFF)) {
        fn_8027CE3C(self, 4);
    }
    *(int*)(self + 0x4) = *(int*)(self + 0x4) + 1;
    char* p = (char*)fn_8027EA20(lbl_805A0EC8, 0x200, 0x1D);
    if (p != 0) {
        *(int*)p = 0;
    }
    **(void***)self = p;
    p[0x13] = 0x10;
    p[0x10] = 1;
    *(int*)(p + 0x18) = -1;
    *(int*)p = 0x10;
}
