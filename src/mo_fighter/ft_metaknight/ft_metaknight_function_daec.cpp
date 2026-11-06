#pragma force_active on
#include <so/so_module_accesser.h>

extern "C" void fn_111_DC30(Rect2D* out, const Rect2D* a, const Rect2D* b);
extern "C" soCameraModule* fn_27_8CDE4(StageObject* p);

extern "C" void fn_111_DAEC(soModuleAccesser* accesser) {
    Rect2D rect;
    Rect2D parent;
    Rect2D out;

    if (accesser->getWorkManageModule().isFlag(0x22000010) != 1) {
        accesser->getCameraModule().getCameraRangeGlobalRect(&rect, 0);
        for (int i = 6; i < 12; i++) {
            StageObject* p = accesser->getLinkModule().getParent(i);
            if (p != 0) {
                fn_27_8CDE4(p)->getCameraRangeGlobalRect(&parent, 0);
                fn_111_DC30(&out, &rect, &parent);
                rect = out;
            }
        }
        accesser->getCameraModule().setOffsetGlobalRectCenter(&rect, accesser, 0);
        accesser->getCameraModule().setCameraRangeGlobalRect(&rect, accesser, 0);
    }
}
