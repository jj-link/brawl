#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" void fn_27_1F35E4(void* self, int arg);
extern "C" void fn_27_207F50(void* obj, int a, int b, void* c, unsigned char d);

extern "C" void fn_27_1F2548(u8* self, void* unused, s32 idx, unsigned char a, int b) {
    if (idx < 7) {
        u8* slot = self + idx * 4;
        void* obj = *(void**)(slot + 0x4c);
        if (obj != 0) {
            fn_27_1F35E4(obj, b);
            u8* base = *(u8**)(self + 0xf8);
            fn_27_207F50(base + idx * 0x1c4, idx, b, *(void**)(slot + 0x4c), a);
        }
    }
}
