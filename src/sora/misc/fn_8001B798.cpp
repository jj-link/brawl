#pragma force_active on
class gfCallBack {};

class gfCallBackList {
public:
    void add(gfCallBack* cb);
};

extern gfCallBackList lbl_8059FFEC;

class gfFileIO {
public:
    class ErrorCallback : public gfCallBack {};
    static void setFatalErrorCallback(ErrorCallback* cb);
};

void gfFileIO::setFatalErrorCallback(ErrorCallback* cb) {
    lbl_8059FFEC.add((gfCallBack*)cb);
}
