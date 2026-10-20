#pragma force_active on
class gfScene {
public:
    void setLoadModule(const char* name, bool b);
};

extern "C" const char lbl_1_data_4D00[];

extern "C" void fn_1_10328(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_4D00, false);
}
