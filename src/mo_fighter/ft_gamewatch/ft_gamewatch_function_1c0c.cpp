#pragma force_active on
class soGimmickEventObserver;

template <class T>
class soEventObserver {
public:
    ~soEventObserver();
};

class GimmickObserver : public soEventObserver<soGimmickEventObserver> {
public:
    ~GimmickObserver() {}
};

extern "C" void __dl__FPv(void*);

extern "C" void* fn_107_1C0C(void* object, short flag)
{
    if (object) {
        GimmickObserver* observer =
            (GimmickObserver*)((char*)object + 4);
        observer->~GimmickObserver();

        if (flag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
