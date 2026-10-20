#pragma force_active on
class itCounter {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int getCount();
};

class itManager {
public:
    static itManager* getInstance();
    char pad[0x6d8];
    itCounter m_counter;
};

extern "C" {
void* fn_27_2A8A00(itManager*, int);
int fn_27_28E91C(void*);
void removeItem__9itManagerFP8BaseItem(void*, void*);

void fn_96_1BFA4() {
    itManager* mgr = itManager::getInstance();
    int count = mgr->m_counter.getCount();

    for (int i = 0; i < count; ++i) {
        void* item = fn_27_2A8A00(itManager::getInstance(), i);
        if (item && fn_27_28E91C(item)) {
            removeItem__9itManagerFP8BaseItem(itManager::getInstance(), item);
            --i;
            --count;
        }
    }
}
}
