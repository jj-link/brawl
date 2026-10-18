#pragma force_active on
extern "C" {

struct StBoneHorn {
    float f[16];
};

struct BoneHornData {
    const StBoneHorn *pBoneHorn;
};

extern const StBoneHorn lbl_93_data_8560;

void fn_93_11074(BoneHornData *pBoneHornData)
{
    pBoneHornData->pBoneHorn = &lbl_93_data_8560;
    return;
}

} // extern "C"