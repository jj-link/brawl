#pragma force_active on
class Stage {
public:
    void* getGround(int n);
};

void* Stage::getGround(int n) {
    void* p = *(void**)((char*)this + 0x88);
    while (n != 0 && p != 0) {
        p = *(void**)((char*)p + 0x50);
        n--;
    }
    return p;
}
