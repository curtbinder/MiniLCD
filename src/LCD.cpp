#include "LCD.h"

LCD::LCD()
{
    //ctor
    m_fHorizontalGraphEnabled = false;
    m_fVerticalGraphEnabled = false;
    m_fGPIO = false;
    m_fShowCursor = false;
    m_fBlinkCursor = false;
    m_fAutoScroll = false;
    m_fLineWrap = false;
    m_sMessage = _("");
}

LCD::~LCD()
{
    //dtor
}

void LCD::ClearScreen()
{
    printf("Clear LCD screen\n");
}

void LCD::NewLine()
{
    printf("Send NEWLINE\n");
}

void LCD::SendMessage(wxString msg)
{
    printf("Send Message: %s\n", msg.GetData().AsChar());
}
