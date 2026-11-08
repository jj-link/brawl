#pragma force_active on

extern "C" {
extern const char __RTTI__5Enemy[];
extern const char __RTTI__11StageObject[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_41_237A8(int);
void* getInstance__9emManagerFv();
unsigned int fn_41_D044(void*, int);
void* getEnemyPtrFromId__9emManagerFi(void*, int);
float getLr__23soExternalValueAccesserFP11StageObject(void*);
extern float lbl_41_rodata_D54;
extern const float lbl_41_rodata_D58;
}

extern "C" float fn_41_23CD4(void* acc, int id) {
    float result = lbl_41_rodata_D58;
    if ((unsigned long)id <= 3) {
        void* r = fn_41_237A8(id);
        if (r == 0) {
            return result;
        }
        result = getLr__23soExternalValueAccesserFP11StageObject(r);
        return result;
    }
    if ((unsigned long)id - 4 <= 1) {
        void* obj = *(void**)((char*)acc + 0x8);
        void* enemy = __dynamic_cast(obj, 0x3C, __RTTI__5Enemy, __RTTI__11StageObject, 1);
        int taskId = *(int*)((char*)enemy + 0xB0);
        if (id == 4) {
            result = getLr__23soExternalValueAccesserFP11StageObject(enemy);
        } else if (id == 5) {
            void* mgr = getInstance__9emManagerFv();
            unsigned int r2 = fn_41_D044(mgr, taskId);
            if (r2 == 0xffff) {
                return result;
            }
            mgr = getInstance__9emManagerFv();
            void* p = getEnemyPtrFromId__9emManagerFi(mgr, (int)r2);
            if (p == 0) {
                return result;
            }
            result = getLr__23soExternalValueAccesserFP11StageObject(p);
        }
        return result;
    }
    if (id == 6) {
        return lbl_41_rodata_D54;
    }
    if (id == 7) {
        return lbl_41_rodata_D54;
    }
    return result;
}
