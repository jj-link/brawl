#pragma force_active on
namespace nw4r { namespace g3d { class ScnMdl; } }

struct ScnChild {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int v13(nw4r::g3d::ScnMdl*);
};

class gfSceneRoot {
public:
    int remove(nw4r::g3d::ScnMdl* arg);
};

int gfSceneRoot::remove(nw4r::g3d::ScnMdl* arg) {
    char* cur = (char*)this;
    int ret = 1;
    int i = 0;
    int found = 0;
    do {
        ScnChild* child = *(ScnChild**)(cur + 0x390);
        found = 0;
        if (child != 0) {
            found = child->v13(arg);
            if (found != 0) {
                *(unsigned short*)(cur + 0x39A) -= 1;
            }
        }
        if (found != 0) {
            ret = 1;
            break;
        }
        i++;
        cur += 0x18;
    } while (i < 9);
    return ret;
}
