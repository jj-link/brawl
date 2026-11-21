#pragma force_active on

extern "C" {

void nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(void*, bool);

struct Obj {
    unsigned char pad0[0x28];
    int f28;
    unsigned char pad2C[0x34 - 0x2C];
    void* f34;
    unsigned int f38;
    int f3C;
    unsigned char pad40[4];
    void* f44;
    unsigned char pad48[0x56 - 0x48];
    unsigned short f56;
};

void fn_80062F60(Obj* arg0, int arg1) {
                int offset;
    if (arg1 != 0) {
        arg0->f56 = arg0->f56 & 0x7FFF;
        if (arg0->f28 >= 0) {
            if (arg0->f44 != 0 && arg0->f3C != 0) {
                nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(arg0->f44, true);
            }
            if (arg0->f34 != 0) {
                unsigned int i;
                i = 0;
                offset = 0;
                void* ptr;
                while (i < arg0->f38) {
                    ptr = *(void**)((char*)arg0->f34 + offset);
                    if (ptr) {
                        *(unsigned char*)((char*)ptr + 0xD) |= 0x40;
                    }
                    offset += 4;
                    i++;
                }
            }
        }
    } else {
        arg0->f56 = arg0->f56 | 0x8000;
        if (arg0->f44 != 0) {
            nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(arg0->f44, false);
        }
        if (arg0->f34 != 0) {
            unsigned int i;
            i = 0;
            offset = 0;
            void* ptr;
            while (i < arg0->f38) {
                ptr = *(void**)((char*)arg0->f34 + offset);
                if (ptr) {
                    *(unsigned char*)((char*)ptr + 0xD) &= 0xFFFFFFBF;
                }
                offset += 4;
                i++;
            }
        }
    }
}

}
