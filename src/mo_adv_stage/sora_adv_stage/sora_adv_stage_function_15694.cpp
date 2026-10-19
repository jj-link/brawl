#pragma force_active on
class emManager {
public:
    static emManager* getInstance();
    void* getEnemyPtrFromId(int);
};

extern emManager* lbl_41_bss_30;

extern "C" {

void* fn_40_15694(int, int id)
{
    void* ptr = 0;
    if (lbl_41_bss_30)
        ptr = emManager::getInstance()->getEnemyPtrFromId(id);
    return ptr;
}

}
