#pragma force_active on
extern "C" {
void* getInstance__14gfSceneManagerFv();
void startSequence__14gfSceneManagerFv(void* mgr, const char* seq, int arg);
void setNextSequence__14gfSceneManagerFv(void* mgr, const char* seq, int arg);
extern const char lbl_1_data_67E8[];

void sqSystemSetStartSequence__Fb(bool flag) {
    void* mgr = getInstance__14gfSceneManagerFv();
    if (flag) {
        startSequence__14gfSceneManagerFv(mgr, lbl_1_data_67E8, 0);
    } else {
        setNextSequence__14gfSceneManagerFv(mgr, lbl_1_data_67E8, 0);
    }
}
}
