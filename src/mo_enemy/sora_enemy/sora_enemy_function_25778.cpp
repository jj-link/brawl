#pragma force_active on
struct soModuleAccesser;

class emAreaModuleImpl {
public:
    static bool isTargetFoundDir(soModuleAccesser* acc, long p2, long p3);
};

extern "C" void fn_41_25524(void* out, soModuleAccesser* acc, int p2, int flag);
extern "C" void* fn_41_245B8(soModuleAccesser* acc, void* buf);
extern "C" bool fn_41_24660(soModuleAccesser* acc, void* p, long p3);

bool emAreaModuleImpl::isTargetFoundDir(soModuleAccesser* acc, long p2, long p3) {
    char buf[16];
    fn_41_25524(buf, acc, (int)p2, 1);
    void* p = fn_41_245B8(acc, buf);
    return fn_41_24660(acc, p, p3);
}
