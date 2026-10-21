#pragma force_active on
class gfHeapManager {
public:
    void free(void* p);
};

extern "C" {
extern gfHeapManager* lbl_8059FFC8;

void fn_8001AC98(int unused, void* arg1) {
    lbl_8059FFC8->free(arg1);
    lbl_8059FFC8 = 0;
}
}
