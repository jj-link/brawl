#pragma force_active on
struct soGimmickEventObserver;
template <class T> struct soEventObserver {
    ~soEventObserver();
};
struct soGimmickEventObserverHolder : soEventObserver<soGimmickEventObserver> {
    ~soGimmickEventObserverHolder() {}
};

extern "C" {
void* fn_91_1B60(void* object, short deleting) {
    if (object != 0) {
        soGimmickEventObserverHolder* observer =
            reinterpret_cast<soGimmickEventObserverHolder*>(static_cast<unsigned char*>(object) + 4);
        observer->~soGimmickEventObserverHolder();
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
