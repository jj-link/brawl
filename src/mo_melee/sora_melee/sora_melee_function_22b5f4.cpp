#pragma force_active on
extern "C" {
extern void releaseArchive__15stCommonGimmickFv(void*);
extern void __dt__7stMeleeFv(void*, int);
extern void __dl__FPv(void*);
extern void* getInstance__16CameraControllerFv();
extern void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
extern void releaseScnAnmRes__21cmAnimationControllerFv(void*);
extern unsigned char lbl_27_data_4AE20[];

void* fn_27_22B5F4(void* self, int deleteFlag) {
    if (self != 0) {
        *(void**)((char*)self + 0x3C) = lbl_27_data_4AE20;
        releaseArchive__15stCommonGimmickFv(self);
        changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 5);
        releaseScnAnmRes__21cmAnimationControllerFv(*(void**)((char*)getInstance__16CameraControllerFv() + 0x48));
        __dt__7stMeleeFv(self, 0);
        if (deleteFlag > 0)
            __dl__FPv(self);
    }
    return self;
}
}
