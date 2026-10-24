#pragma force_active on
#pragma readonly_strings off
class CameraController {
public:
enum Kind { KIND_0, KIND_1, KIND_2, KIND_3, KIND_4, KIND_5, KIND_6, KIND_7, KIND_8, KIND_9, KIND_10, KIND_11, KIND_12, KIND_13, KIND_14 };
char m_pad0[0x4C];
CameraController* m_4C;
CameraController* m_50;
CameraController* m_54;
CameraController* m_58;
CameraController* m_5C;
CameraController* m_60;
CameraController* m_64;
CameraController* m_68;
CameraController* m_6C;
CameraController* m_70;
CameraController* m_74;
CameraController* m_78;
char m_pad7C[4];
CameraController* m_80;
CameraController* getCameraController(Kind kind);
};
CameraController* CameraController::getCameraController(Kind kind) {
switch ((unsigned int)kind) {
case 1:
case 5: return m_50;
case 2: return m_58;
case 3: return m_60;
case 4: return m_64;
case 6: return m_54;
case 7: return m_68;
case 8: return m_6C;
case 9: return m_70;
case 10: return m_74;
case 11: return m_78;
case 12: return m_5C;
case 13: return m_80;
case 14: return m_4C;
default: return this;
}
}
