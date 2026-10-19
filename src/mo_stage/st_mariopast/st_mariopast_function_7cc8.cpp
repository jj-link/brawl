#pragma force_active on
class gfCamera {
public:
    void setGX();
};

class gfCameraManager {
public:
    static void* getManager();
};

extern "C" {
void fn_48_A624(void* obj);

void fn_48_7CC8(char* p, unsigned int n) {
    if (p != 0 && n != 1) {
        gfCamera* cam = (gfCamera*)gfCameraManager::getManager();
        cam->setGX();
        fn_48_A624(*(void**)(p + 0xf0));
    }
}
}
