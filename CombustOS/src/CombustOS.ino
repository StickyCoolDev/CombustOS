#include <LiquidCrystal.h>

class PixelByPixel { // the name of the text user interface is pixel by pixel
public:
    
    PixelByPixel(LiquidCrystal &lcd_ref) : m_Screen(&lcd_ref){};
    void Init(unsigned short height, unsigned short width){
        // set the passed in values to memeber variables
        m_ScreenHeight = height;
        m_ScreenWidth = width;
    }; // like initrc from ncurses // it's also a separate function from the constructor as the initialisation of the liquid crystal glass is also not in its constructor
    void Update();
    void RenderScene(SceneData &ScreenToRender); // we will call the write , move, print on a scene class before rendering it by the TUI engine
private:

    LiquidCrystal *m_Screen; // using the screen as a reference

    // variables for height and weight
    unsigned short m_ScreenHeight; // unsigned shorts for memory
    unsigned short m_ScreenWidth; // usage improvement
};

class SceneData {
public:
    SceneData();

    virtual void OnRender(){

    }
private:
    char m_Data[16][2]; // set a constant value for now 
};

void setup(){}
void loop(){}
