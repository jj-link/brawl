#pragma force_active on
extern "C" void __dl__FPv(void*);

struct stClassInfo {
    ~stClassInfo();
};

stClassInfo::~stClassInfo() {
    if (this != 0) {
        // The deleting flag is passed in r4 by the ABI.
    }
}
