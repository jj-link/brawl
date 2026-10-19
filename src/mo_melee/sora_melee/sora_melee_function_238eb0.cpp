#pragma force_active on

extern float *g_soWorld;

// .rodata float constant (lbl_27_rodata_3938)
extern "C" const float lbl_27_rodata_3938;

class stMelee {
public:
    static void setGravityHalf();
};

void stMelee::setGravityHalf()
{
    float gravity = lbl_27_rodata_3938;
    g_soWorld[0] = gravity;
    g_soWorld[1] = gravity;
}
