#pragma force_active on

struct Entry {
    void* unk0;
    int (*unk4)(void*);
};

extern Entry lbl_80408C08[];

extern "C" {
void fn_800F0F84(void* arg0) {
    char* self = (char*)arg0;
    int idx = *(int*)(self + 0x34);
    int (*f)(void*) = lbl_80408C08[idx].unk4;
    if (f != 0) {
        *(int*)(self + 0x34) = f(arg0);
    }
    int idx2 = *(int*)(self + 0x34);
    if (idx2 != idx) {
        void (*g)(void*) = (void (*)(void*))lbl_80408C08[idx2].unk0;
        if (g != 0) {
            g(arg0);
        }
    }
}
}
