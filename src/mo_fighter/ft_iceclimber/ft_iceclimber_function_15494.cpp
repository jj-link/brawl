#include <so/so_module_accesser.h>
#pragma force_active on
extern "C" {
extern float lbl_105_rodata_68;
void fn_105_1553C(void*, soModuleAccesser*);
void fn_105_15658(void*, soModuleAccesser*);
Vec3f* fn_105_C1C0(Vec3f*, float, float, float);
void fn_105_15494(void* self, soModuleAccesser* accesser) {
    if (accesser->getLinkModule().isModelConstraint() == 1) {
        fn_105_1553C(self, accesser);
        fn_105_15658(self, accesser);
        soModelModule& model = accesser->getModelModule();
        Vec3f vec;
        model.setNodeTranslate(2, fn_105_C1C0(&vec, lbl_105_rodata_68, lbl_105_rodata_68, lbl_105_rodata_68));
    }
}
}