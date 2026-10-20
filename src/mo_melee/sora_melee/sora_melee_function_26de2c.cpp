#pragma force_active on
class gfCamera {
public:
    void setGX();
};

class gfCameraManager {
public:
    static gfCamera* getManager();
};

class grGimmick {
public:
    void renderDebug();
};

void grGimmick::renderDebug() {
    gfCameraManager::getManager()->setGX();
}
