#pragma force_active on

extern "C" unsigned int fn_8001440C();
extern "C" unsigned int get__17gfArchiveDatabaseCFl(void*, unsigned int);

extern "C" unsigned int fn_80046958(void* arg0, unsigned int arg1) {
    if (arg1 != 0xFFFF) {
        void* db = *(void**)((char*)arg0 + 4);
        unsigned int result = get__17gfArchiveDatabaseCFl(db, arg1);
        if (result != 0) {
            return fn_8001440C();
        }
    }
    return 0;
}
