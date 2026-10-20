#pragma force_active on
class PikminList {
public:
    virtual ~PikminList();
    virtual void** get(int);
    virtual void slot10();
    virtual void slot14();
    virtual void reset();
};

struct PikminManager {
    char padding[0x80];
    PikminList list;
};

extern "C" void* fn_113_244FC(PikminManager* manager) {
    manager->list.reset();
    return *manager->list.get(0);
}
