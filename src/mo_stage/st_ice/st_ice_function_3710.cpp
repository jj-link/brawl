#pragma force_active on
extern "C" void processAnim__6GroundFv();

extern "C" void fn_62_3710(void* self) {
    void* saved = self;
    processAnim__6GroundFv();
    if (saved == 0) {
        return;
    }
}
