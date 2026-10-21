#pragma force_active on
extern "C" {
    void* fn_80164908(void*, void*);
    void* fn_80163BD4(void* arg0) {
        return fn_80164908(*(void**)((char*)arg0 + 0x20), arg0);
    }
}
