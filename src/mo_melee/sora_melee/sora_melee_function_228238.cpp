#pragma force_active on
class Container {
public:
    virtual ~Container();
};

extern "C" Container* create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(void*, int);

extern "C" void fn_27_228238(Container** self, void* data) {
    if (data) {
        if (*self) {
            delete *self;
            *self = 0;
        }
        *self = create__20stDataMultiContainerFP19stDataContainerDataQ25Heaps8HeapType(data, 15);
    }
}
