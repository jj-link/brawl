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

extern "C" void* fn_105_1B04(void* self, short flag)
{
    if (self) {
        GimmickObserver* observer =
            (GimmickObserver*)((char*)self + 4);
        observer->~GimmickObserver();

        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
