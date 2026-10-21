#include <types.h>
#pragma force_active on

struct EventSystem {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool isExist(long);
};

struct EventManager {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void eraseObserver(s16, s16);
};

extern "C" EventSystem* getInstance__13soEventSystemFv();
extern "C" EventManager* getManager__13soEventSystemFl(EventSystem*, long);

class soGimmickEventObserver;

template <typename T>
class soEventObserver {
public:
    ~soEventObserver();
    static char __vt[];

    void* vptr;
    s16 m4;
    s16 m6;
    s16 m8;
};

template <typename T>
soEventObserver<T>::~soEventObserver() {
    s16 id = m4;
    vptr = __vt;
    if (getInstance__13soEventSystemFv()->isExist(id) == true) {
        getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), m4)->eraseObserver(m6, m8);
    }
    m8 = -1;
    m4 = -1;
}

template class soEventObserver<soGimmickEventObserver>;
