#pragma force_active on
extern "C" unsigned char lbl_96_data_CEFC[];

struct VFTbl {
    void *vptr;
};

extern "C" void fn_96_24428(VFTbl *object) {
    object->vptr = (void *)lbl_96_data_CEFC;
}
