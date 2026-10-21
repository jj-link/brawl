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
int fn_27_28E85C(void*);

int fn_96_19DF4() {
    int i;
    for (i = 0; i < itManager::getInstance()->m_counter.getCount(); ++i) {
        void* item = fn_27_2A8A00(itManager::getInstance(), i);
        if (item && (fn_27_28E91C(item) || fn_27_28E85C(item))) {
            return 0;
        }
    }
    return 1;
}
}
