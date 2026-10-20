#pragma force_active on
class gfScene {
public:
    void setLoadModule(const char* name, bool b);
};

extern "C" const char lbl_1_data_491C[];

extern "C" void fn_1_E9C8(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_491C, false);
}
