#pragma force_active on
extern "C" void fn_27_239F6C(void*);
extern "C" void releaseArchive__15stCommonGimmickFv(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void __dt__7stMeleeFv(void*, int);
extern "C" void __dl__FPv(void*);
extern "C" unsigned char lbl_71_data_3D0[];

extern "C" void* fn_71_1EC(void* self, int flag) {
    if (self) {
        *(void**)((char*)self + 0x3C) = lbl_71_data_3D0;
        fn_27_239F6C((char*)self + 0x2BC);
        fn_27_239F6C((char*)self + 0x2CC);
        releaseArchive__15stCommonGimmickFv(self);

        void* task = *(void**)((char*)self + 0x1D8);
        if (task) {
            exit__6gfTaskFv(task);
        }

        __dt__7stMeleeFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
