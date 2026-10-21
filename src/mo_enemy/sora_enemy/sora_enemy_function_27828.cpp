#pragma force_active on
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_41_23270(void* self, unsigned int index);
int fn_41_230F8(int x);
void fn_41_232A4(void* unused, int x, void* out);
}
extern char __RTTI__16emAreaModuleImpl[];
extern char __RTTI__12soAreaModule[];

extern "C" void fn_41_27828(char* self, int index, float f1, float f2, float f3, float f4) {
    if (index != -1) {
        void* acc = *(void**)(self + 0x14);
        void* mod = *(void**)((char*)*(void**)((char*)acc + 0xD8) + 0x90);
        void* area = __dynamic_cast(mod, 0, __RTTI__16emAreaModuleImpl, __RTTI__12soAreaModule, (short)1);
        char* entry = (char*)fn_41_23270(area, index);
        if (entry != 0) {
            int r = fn_41_230F8(index);
            *(unsigned char*)entry = 0;
            fn_41_232A4(area, r, entry);
            *(int*)(entry + 0xC) = 0;
            *(float*)(entry + 0x10) = f1;
            *(float*)(entry + 0x14) = f2;
            *(float*)(entry + 0x18) = f3;
            *(float*)(entry + 0x1C) = f4;
        }
    }
}
