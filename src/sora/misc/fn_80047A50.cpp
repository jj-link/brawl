#pragma force_active on
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* self, unsigned long index);

extern "C" void fn_80047A50(char* arg0, signed char* arg1, unsigned long arg2) {
    void* tmp = *(void**)(arg0 + 0xE8);
    void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&tmp, arg2);
    signed char v = 2;
    while (node != 0) {
        int idx;
        if (node != 0) {
            idx = *(int*)((char*)node + 0xC);
        } else {
            idx = 0;
        }
        if (arg1[idx] >= 1) {
            break;
        }
        arg1[idx] = v;
        v = 3;
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
