#pragma force_active on
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, unsigned long index);

extern "C" void fn_80047AE0(void* arg0, signed char* arg1, unsigned long* arg2, int arg3) {
    void* tmp = *(void**)((char*)arg0 + 0xE8);
    unsigned int maxIdx = 0;
    int i;

    for (i = 0; i < arg3; i++) {
        unsigned long nodeIdx = arg2[i];
        void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&tmp, nodeIdx);
        while (node != 0) {
            unsigned int idx;
            if (node != 0) {
                idx = *(unsigned int*)((char*)node + 0xC);
            } else {
                idx = 0;
            }
            if (arg1[idx] >= 1) {
                break;
            }
            if (idx > maxIdx) {
                maxIdx = idx;
            }
            arg1[idx] = 3;
            {
                int off = *(int*)((char*)node + 0x5C);
                if (off != 0) {
                    node = (char*)node + off;
                } else {
                    node = 0;
                }
            }
        }
    }
    arg1[maxIdx] = 2;
}