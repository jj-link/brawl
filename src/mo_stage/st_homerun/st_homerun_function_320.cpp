#pragma force_active on
extern "C" {
void* getManager__15gfCameraManagerFv();
void fn_80018610(void*);
void __dl__FPv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__9gfArchiveFv(void*, int);
void __dt__7stMeleeFv(void*, int);
extern unsigned char lbl_88_data_46C[];
}

struct stHomerun {
    unsigned char unk[0x3C];
    void* vtable;
    unsigned char unk2[0x7CC];
    void* ptr_80C;
};

extern "C" void* fn_88_320(stHomerun* self, int deleteFlag) {
    if (self != 0) {
        self->vtable = lbl_88_data_46C;
        void* manager = getManager__15gfCameraManagerFv();
        if (manager != 0)
            fn_80018610(manager);
        if (self->ptr_80C != 0)
            __dl__FPv(self->ptr_80C);
        releaseArchive__15stCommonGimmickFv(self);
        __dt__9gfArchiveFv((char*)self + 0x770, -1);
        __dt__9gfArchiveFv((char*)self + 0x6F0, -1);
        __dt__9gfArchiveFv((char*)self + 0x670, -1);
        __dt__9gfArchiveFv((char*)self + 0x5F0, -1);
        __dt__7stMeleeFv(self, 0);
        if (deleteFlag > 0)
            __dl__FPv(self);
    }
    return self;
}
