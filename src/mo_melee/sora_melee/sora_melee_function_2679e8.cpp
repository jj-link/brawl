#pragma force_active on
typedef unsigned long u32;

class grYakumono {
public:
    bool isEnableAttackAttribute(u32 a, u32 b);
};

bool grYakumono::isEnableAttackAttribute(u32 a, u32 b) {
    u32 vb = *(u32*)b;
    if (vb == 0) {
        return true;
    }
    return *(u32*)a == vb;
}
