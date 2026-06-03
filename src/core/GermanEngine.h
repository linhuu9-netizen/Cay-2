#pragma once
#include "CayData.h"
#include "CayTypes.h"

namespace Cay {

class GermanEngine {
public:
    GermanEngine();
    void OnKeyDown(Cay::KeyEvent& e);
    void ResetFull();
    InjectTextFunc OnInjectText = nullptr;

private:
    wchar_t _buf[MAX_BUFFER];
    int     _len;
    wchar_t _lastOutput[MAX_BUFFER];
    int     _lastOutputLen;
    bool _pendingAcute;
    void Inject(const wchar_t* newText, int newLen);
    void ResetState();
    static wchar_t GetUmlaut(wchar_t ch);
    void BuildOutput(wchar_t* out, int& outLen) const;
};

} // namespace Cay
