#pragma opt_common_subs off
#pragma opt_deadcode off
#pragma opt_propagation off
#pragma opt_dead_assignments off

#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed_ground_view.h>
#pragma force_active on

extern "C" {
extern const float lbl_113_rodata_90;

DededeSpeed fn_27_899AC(const DededeSpeed*, const DededeSpeed*);
void fn_113_1DA94(DededeSpeed*, const DededeSpeed*);
void fn_113_BC00(DededeSpeed*, const DededeSpeed*);
}

inline const DededeSpeed* speedWords(const Vec2f& value) {
    return reinterpret_cast<const DededeSpeed*>(&value);
}

extern "C" void fn_113_1D850(
    int kind,
    const DededeSpeed* input,
    unsigned char* energies,
    soModuleAccesser* accesser
) {
    switch (kind) {
    case 0: {
        DededeSpeed speed = {lbl_113_rodata_90, lbl_113_rodata_90};

        switch (accesser->getSituationModule().getKind()) {
        case 0: {
            DededeGroundSpeedView* ground =
                reinterpret_cast<DededeGroundSpeedView*>(&accesser->getGroundModule());
            Vec2f normal;
            Vec2f::copy(
                normal,
                *reinterpret_cast<const Vec2f*>(
                    &ground->getTouchNormal(static_cast<grCollStatus::TouchMask>(8), 0)
                )
            );
            speed = fn_27_899AC(
                speedWords(Vec2f(input->x, lbl_113_rodata_90)),
                speedWords(normal)
            );
            break;
        }
        }

        if (lbl_113_rodata_90 != speed.x || lbl_113_rodata_90 != speed.y) {
            bool flag = false;
            bool* flagPtr = &flag;
            (void)flagPtr;
            fn_113_1DA94(reinterpret_cast<DededeSpeed*>(energies + 0x78), &speed);
            *reinterpret_cast<float*>(energies + 0x94) += lbl_113_rodata_90;
            energies[0x75] |= 0x80;
        }
        break;
    }
    case 1: {
        DededeSpeed speed = {lbl_113_rodata_90, lbl_113_rodata_90};
        DededeSpeed accel = {lbl_113_rodata_90, lbl_113_rodata_90};

        switch (accesser->getSituationModule().getKind()) {
        case 0:
            speed.x = input->x;
            accel.x = soValueAccesser::getConstantFloat(accesser, 0xfc8, 0);
            break;

        case 2:
        case 3:
            speed.x = input->x;
            speed.y += input->y;
            accel.x = soValueAccesser::getConstantFloat(accesser, 0xfc8, 0);
            break;
        }

        if (lbl_113_rodata_90 != speed.x || lbl_113_rodata_90 != speed.y) {
            bool flag = false;
            bool* flagPtr = &flag;
            (void)flagPtr;
            fn_113_1DA94(reinterpret_cast<DededeSpeed*>(energies + 0xe0), &speed);
            *reinterpret_cast<float*>(energies + 0xe8) =
                soValueAccesser::getConstantFloat(accesser, 0xfe0, 0);
            fn_113_BC00(reinterpret_cast<DededeSpeed*>(energies + 0xcc), &accel);
            energies[0xb1] |= 0x80;
        }
        break;
    }
    case 2:
        break;
    }
}
