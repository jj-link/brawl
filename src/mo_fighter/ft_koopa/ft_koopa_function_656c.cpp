#pragma force_active on
template <class T> class soArray;
class soModelNodeSetUp;
class soModelVirtualNode;
class soModuleAccesser;
class soEventObserverRegistrationDesc;

class soModelModuleImpl {
public:
    soModelModuleImpl(soModuleAccesser*, soArray<soModelNodeSetUp>*, float,
                      void*, soArray<soModelVirtualNode>*,
                      soEventObserverRegistrationDesc*);
};

extern "C" void* fn_27_19A7DC(void*, int, int);
extern "C" void* fn_27_CC75C(void*, int, int);

extern "C" void* fn_102_656C(
    void* object, soModuleAccesser* accesser, float scale,
    void* context, soEventObserverRegistrationDesc* registration)
{
    unsigned char* storage = static_cast<unsigned char*>(object);
    fn_27_19A7DC(object, 8, 0);
    fn_27_CC75C(storage + 0x1AC, 3, 0);
    reinterpret_cast<soModelModuleImpl*>(storage + 0x1F4)->__ct(
        accesser,
        reinterpret_cast<soArray<soModelNodeSetUp>*>(object),
        scale,
        context,
        reinterpret_cast<soArray<soModelVirtualNode>*>(storage + 0x1AC),
        registration);
    return object;
}
