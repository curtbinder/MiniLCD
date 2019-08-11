#ifndef __LCD_H__
#define __LCD_H__

#include <wx/string.h>

class LCD
{
    public:
        LCD();
        ~LCD();
        inline void setHorizontalGraphEnabled(bool fEnable) { m_fHorizontalGraphEnabled = fEnable; }
        inline bool getHorizontalGraphEnabled() { return m_fHorizontalGraphEnabled; }
        inline void setVerticalGraphEnabled(bool fEnable) { m_fVerticalGraphEnabled = fEnable; }
        inline bool getVerticalGraphEnabled() { return m_fVerticalGraphEnabled; }
        inline void setGPIO(bool fEnable) { m_fGPIO = fEnable; }
        inline bool getGPIO() { return m_fGPIO; }
        inline void setShowCursor(bool fEnable) { m_fShowCursor = fEnable; }
        inline bool getShowCursor() { return m_fShowCursor; }
        inline void setBlinkCursor(bool fEnable) { m_fBlinkCursor = fEnable; }
        inline bool getBlinkCursor() { return m_fBlinkCursor; }
        inline void setAutoScroll(bool fEnable) { m_fAutoScroll = fEnable; }
        inline bool getAutoScroll() { return m_fAutoScroll; }
        inline void setLineWrap(bool fEnable) { m_fLineWrap = fEnable; }
        inline bool getLineWrap() { return m_fLineWrap; }
        void ClearScreen();
        inline void setMessage(wxString msg) { m_sMessage = msg; }
        inline wxString getMessage() { return m_sMessage; }
        void NewLine();
        void SendMessage(wxString msg);

    protected:

    private:
        bool m_fHorizontalGraphEnabled;
        bool m_fVerticalGraphEnabled;
        bool m_fGPIO;
        bool m_fShowCursor;
        bool m_fBlinkCursor;
        bool m_fAutoScroll;
        bool m_fLineWrap;
        wxString m_sMessage;
};

#endif // __LCD_H__
