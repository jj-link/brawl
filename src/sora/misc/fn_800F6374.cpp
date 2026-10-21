#pragma force_active on
struct gfArchive;
class IfFoxSmashAppearTask;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_800F609C(IfFoxSmashAppearTask* self, gfArchive* arg);

class IfFoxSmashAppearTask {
public:
    static void create(gfArchive* arg);
};

void IfFoxSmashAppearTask::create(gfArchive* arg) {
    void* p = __nw__FUlQ25Heaps8HeapType(0x428, 0xf);
    if (p != 0) {
        fn_800F609C((IfFoxSmashAppearTask*)p, arg);
    }
}
