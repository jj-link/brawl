#pragma force_active on
class soModuleAccesser;

class emAreaModuleImpl {
public:
    static bool isExistTarget(soModuleAccesser* acc, unsigned long id);
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
int fn_41_237A8(int);
void* getInstance__9emManagerFv();
unsigned int fn_41_D044(void*, unsigned int);
void* getEnemyPtrFromId__9emManagerFi(void*, int);
}

bool emAreaModuleImpl::isExistTarget(soModuleAccesser* acc, unsigned long id) {
    int sid = (int)id;
    if (id <= 3) {
        return fn_41_237A8(id) != 0;
    }
    if (id - 4 <= 1) {
        void* obj = *(void**)((char*)acc + 0x8);
        void* enemy = __dynamic_cast(obj, 0x3C, __RTTI__5Enemy, __RTTI__11StageObject, 1);
        unsigned long taskId = *(unsigned long*)((char*)enemy + 0xB0);
        if (sid == 4) {
            return true;
        }
        if (sid == 5) {
            void* mgr = getInstance__9emManagerFv();
            unsigned int r = fn_41_D044(mgr, taskId);
            if (r == 0xffff) {
                return false;
            }
            mgr = getInstance__9emManagerFv();
            if (getEnemyPtrFromId__9emManagerFi(mgr, r) == 0) {
                return false;
            }
        }
        return true;
    }
    if (sid == 6) {
        return true;
    }
    return id == 7;
}
