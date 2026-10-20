#pragma force_active on
class gfCallBack;

class stTrigger {
public:
    void setValidCallback(gfCallBack* cb);
};

extern "C" char lbl_27_data_4BCF8[];
extern "C" char __RTTI__10gfCallBack[];
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

void stTrigger::setValidCallback(gfCallBack* cb) {
    void** head = (void**)((char*)this + 0x20);
    if (*head) {
        void** p = (void**)*head;
        while (*p) {
            p = (void**)*p;
        }
        *p = cb;
    } else {
        *head = __dynamic_cast(cb, 4, lbl_27_data_4BCF8, __RTTI__10gfCallBack, 0);
    }
}
