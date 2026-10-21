#pragma force_active on
class cmPhotoController {
public:
    void setFreezeMode(void *arg0);
    char pad0[0x60];
    int unk60;
};

void cmPhotoController::setFreezeMode(void *arg0) {
    int var_r4 = -1;
    if (arg0 != 0) {
        var_r4 = 1;
    }
    unk60 += var_r4;
}
