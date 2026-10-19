#pragma force_active on
class soHeapModuleImpl {
public:
    ~soHeapModuleImpl();
};

class fn_121_1F54_Owner : public soHeapModuleImpl {
public:
    ~fn_121_1F54_Owner();
};

extern "C" void* fn_121_1F54(fn_121_1F54_Owner* p, short del) {
    if (p != 0) {
        p->soHeapModuleImpl::~soHeapModuleImpl();
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}
