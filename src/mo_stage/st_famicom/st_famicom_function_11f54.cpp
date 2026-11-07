#pragma force_active on

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void* model, unsigned long flag);
extern "C" const float lbl_68_rodata_1D8;

struct V3 { float x, y, z; };

extern "C" void fn_68_11F54(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* p = s + 0xd0;
    if (p != 0) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        unsigned char* m = *(unsigned char**)a;
        if (m != 0) {
            if (*(unsigned int*)(m + 0x11c) == 0) {
                *(unsigned int*)(p + 0xc) = 0;
                unsigned int* q = *(unsigned int**)(p + 4);
                *q = *(unsigned int*)(s + 0xc4);
                *(unsigned char**)(m + 0x11c) = p;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(m, 1);
                q = *(unsigned int**)(p + 4);
                *(short*)(m + 0x122) = (short)*q;
            }
            V3* arr = *(V3**)(s + 0x158);
            if (arr != 0 && *(unsigned char**)(s + 0x15c) != 0) {
                V3 v;
                switch (**(unsigned char**)(s + 0x15c)) {
                case 9: v = arr[0]; break;
                case 10: v = arr[1]; break;
                case 11: v = arr[2]; break;
                case 12: v = arr[3]; break;
                default: return;
                }
                float* d = (float*)(*(unsigned char**)(p + 4) + 0x2c);
                float z = lbl_68_rodata_1D8;
                float y = v.y;
                d[0] = z;
                d[1] = y;
                d[2] = z;
            }
        }
    }
}
