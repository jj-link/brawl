#pragma force_active on
namespace {

struct ToonLinkVTable {
    void *m00;
    void *m04;
    void *m08;
    void *m0C;
    void *m10;
    void *m14;
    void *m18;
    void *m1C;
    void *m20;
    void *m24;
    void *m28;
    void *m2C;
    void *m30;
    void *m34;
    void *m38;
    void *m3C;
};

struct ToonLinkObject {
    ToonLinkVTable *vtable;
};

}

extern "C" ToonLinkVTable lbl_121_data_81B8;

extern "C" void fn_121_F2F0(ToonLinkObject *object)
{
    object->vtable = &lbl_121_data_81B8;
}