#pragma force_active on
extern "C" {

bool fn_801BD5D4(const void* self);
void fn_801BD5FC(void* arg);

struct Entry {
    void* pad0;
    void* pad4;
    void* owner;
};

void* fn_801CA79C(void** arg0, void* arg1) {
    *arg0 = arg1;
    if (fn_801BD5D4(arg1)) {
        fn_801BD5FC(*arg0);
    }
    void* entry = *arg0;
    ((Entry*)entry)->owner = arg0;
    return entry;
}

}
