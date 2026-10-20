#pragma force_active on
class gfScene {
public:
    void setLoadModule(const char* name, bool b);
};

extern "C" char lbl_1_data_4B6C[];

extern "C" void fn_1_FD14(gfScene* scene) {
    scene->setLoadModule(lbl_1_data_4B6C, false);
}
