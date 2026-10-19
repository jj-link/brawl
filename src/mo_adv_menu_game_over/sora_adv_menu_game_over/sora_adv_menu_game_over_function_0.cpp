#pragma force_active on
struct muAdvGameOverTaskParam;
struct muAdvGameOverTask;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_33_44(void* self, const muAdvGameOverTaskParam* param);

class muAdvGameOverTask {
public:
    static void create(const muAdvGameOverTaskParam* param);
};

void muAdvGameOverTask::create(const muAdvGameOverTaskParam* param) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x3f8, 0x2a);
    if (p != 0) {
        fn_33_44(p, param);
    }
}
