#pragma force_active on
struct Entry { unsigned char a, b, c, enabled; };
extern Entry lbl_14_rodata_290[];
extern "C" int fn_800B61C0(void*);
extern "C" int fn_14_3424(void*, int);
extern "C" void fn_14_3508(void* self) {
    unsigned int state = *(unsigned int*)((char*)self + 0x2b0);
    if (lbl_14_rodata_290[state].enabled && fn_800B61C0(*(void**)((char*)self + 0x4c))) {
        switch (state) {
        case 1: case 4: case 7: case 10: case 13:
            fn_14_3424(self, 0); break;
        case 2: fn_14_3424(self, 3); break;
        case 5: fn_14_3424(self, 6); break;
        case 8: fn_14_3424(self, 9); break;
        case 11: fn_14_3424(self, 12); break;
        case 14: fn_14_3424(self, 15); break;
        case 16: fn_14_3424(self, 12); break;
        }
    }
}