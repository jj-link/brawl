#pragma force_active on
struct Stage {
    void processEnd();
};

extern "C" void processEnd__5StageFv();

extern "C" void fn_40_1D94(Stage*);

extern "C" void fn_40_222C(Stage* stage) {
    processEnd__5StageFv();
    fn_40_1D94(stage);
}
