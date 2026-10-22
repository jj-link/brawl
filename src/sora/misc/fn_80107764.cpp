#pragma force_active on
extern "C" void fn_800E3378(void);
extern "C" void fn_800E26B8(void*);
extern "C" void fn_800E3384(void*);

class IfAdvMngr {
public:
    void renderPre();
    char pad0[0xE8];
    void* slots[7];
};

void IfAdvMngr::renderPre() {
    int i;
    char* p = (char*)this;
    fn_800E3378();
    i = 0;
    do {
        if (*(void**)(p + 0xE8) != 0) {
            fn_800E26B8(*(void**)(p + 0xE8));
            fn_800E3384(*(void**)(p + 0xE8));
        }
        i++;
        p += 4;
    } while (i < 7);
}
