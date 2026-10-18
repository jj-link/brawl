#pragma force_active on
class emManager {
public:
    static emManager* getInstance();
};

extern emManager* lbl_41_bss_30;

emManager* emManager::getInstance() {
    return lbl_41_bss_30;
}
