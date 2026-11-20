#include <so/so_module_accesser.h>
#include <st/stage.h>

#pragma force_active on

extern "C" {
extern Stage* lbl_27_bss_5668;

void fn_119_8958(const Vec3f*, const Vec3f*, Vec3f*);
float fn_119_897C(Vec3f*);
void fn_119_7C40(Vec3f*, const Vec3f*);
}

extern "C" void fn_119_8C5C(Vec3f* out, char* object) {
    soModuleEnumeration* modules = *(soModuleEnumeration**)(object + 0xd8);
    Vec3f position = modules->m_modelModule->getNodeGlobalPosition(0, false);
    int kind = *(int*)((char*)lbl_27_bss_5668 + 0x44);

    if (kind == 0x33 || kind == 0x23 || kind == 0x2a) {
        Stage** const stage = &lbl_27_bss_5668;
        Vec3f a, b, d1, d2;
        (*stage)->getKirifudaPos(&a, 3);
        lbl_27_bss_5668->getKirifudaPos(&b, 4);
        fn_119_8958(&a, &position, &d1);
        float distance = fn_119_897C(&d1);
        fn_119_8958(&b, &position, &d2);

        if (distance < fn_119_897C(&d2)) {
            fn_119_7C40(out, &a);
        } else {
            fn_119_7C40(out, &b);
        }

        lbl_27_bss_5668->getKirifudaPos(&a, 1);
        out->m_y = a.m_y;
    } else {
        lbl_27_bss_5668->getKirifudaPos(out, 1);
    }
}
