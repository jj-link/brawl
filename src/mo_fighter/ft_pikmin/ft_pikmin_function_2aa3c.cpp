#pragma force_active on
class soPhotoController {
public:
    void setFreezeMode();
};

extern "C" void fn_113_2AA3C(void* a, void* b, int mode)
{
    if (mode < 4) {
        if (mode >= 1) {
            return;
        }
    }
    ((soPhotoController*)0)->setFreezeMode();
}
