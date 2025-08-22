#include <LiquidCrystal.h>

// Class And Util
class SceneData {
public:
  char getData(unsigned short x, unsigned short y) {
    if (x < 16 && y < 2) {
      return m_Data[x][y];
    }
    return ' ';

  SceneData() {
    for (int i = 0; i < 16; ++i) {
      for (int j = 0; j < 2; ++j) {
        m_Data[i][j] = ' ';
      }
    }
  }
  virtual void Render() {}

protected:
  char m_Data[16][2]; 
};


class TerminalScene : public SceneData {
public:
  void Render() override {
    
    m_Data[0][0] = 'H';
    m_Data[1][0] = 'e';
    m_Data[2][0] = 'l';
    m_Data[3][0] = 'l';
    m_Data[4][0] = 'o';
  }
};

class PixelByPixel { 
public:
  PixelByPixel(LiquidCrystal &lcd_ref) : m_Screen(&lcd_ref) {};

  void Init(unsigned short height, unsigned short width) {
    m_ScreenHeight = height;
    m_ScreenWidth = width;
  }; 

  void RenderScene(SceneData &ScreenToRender);

private:
  LiquidCrystal *m_Screen;
  unsigned short m_ScreenHeight;
  unsigned short m_ScreenWidth;
};

void PixelByPixel::RenderScene(SceneData &ScreenToRender) {
  m_Screen->clear();

  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 16; ++x) {
      m_Screen->setCursor(x, y);
      m_Screen->write(ScreenToRender.getData(x, y));
    }
  }
}



// Main Code
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
PixelByPixel tui(lcd);
TerminalScene myTerminal;

void setup() {
  lcd.begin(16, 2);
  tui.Init(2, 16);
  myTerminal.Render();
  tui.RenderScene(myTerminal);
}

void loop(){}
