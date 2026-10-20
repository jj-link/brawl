#pragma force_active on
class soAnimCmdEventObserver;

template <class T>
class soEventObserver {
public:
    static void __vt(int, int);
};

struct Observer {
    void* vtable;
    short manageID;
    short unitID;
    short sendID;
};

extern "C" void fn_27_D40CC(Observer* self, int unitID) {
    self->manageID = -1;
    self->vtable = reinterpret_cast<void*>(
        &soEventObserver<soAnimCmdEventObserver>::__vt);
    self->unitID = unitID;
    self->sendID = -1;
}
