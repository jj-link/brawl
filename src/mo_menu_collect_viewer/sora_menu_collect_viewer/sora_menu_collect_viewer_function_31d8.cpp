#pragma force_active on
class MuObject {
public:
    void setFrameTex(float);
};
struct ViewerObjects { unsigned char padding[0x160]; MuObject* object; };
struct CollectViewer { unsigned char padding[0x1AC]; ViewerObjects* objects; };

extern "C" void fn_6_31D8(CollectViewer* viewer, int first, int second) {
    int frame = 0;
    if (first) frame |= 1;
    if (second) frame |= 2;
    viewer->objects->object->setFrameTex(frame);
}
