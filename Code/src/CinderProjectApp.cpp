/*

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
 
using namespace ci;
using namespace ci::app;
using namespace std;
 
class MouseKeyboardApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event );    
    void mouseUp( MouseEvent event );    
    void mouseMove( MouseEvent event );    
    void mouseDrag( MouseEvent event );    
 
    void update();
    void draw();
 
    int mouseX, mouseY,
        clickX, clickY,
        clickXr, clickYr;
    bool dragging;

	//Declaring the ship sprite
	gl::Texture ship;
 
    // These following two X and Y locations will be the center
     //   of a circle that slowly moves towards the mouse XY.  
    int enemyX, enemyY;
	int spriteX, spriteY;
};
 
void MouseKeyboardApp::setup()
{

	
	//Loading the image for the ship
	ship = gl::Texture( loadImage( loadAsset("Sprite-0001.png") ) );
    // set the dragging variable initially equal to false
    dragging = false;
 
    // start the enemy circle half way in the screen
    enemyX = enemyY = 250;

	ship.disable();

		//Trans
	gl::enableAlphaBlending();
	
}
 
void MouseKeyboardApp::mouseDown( MouseEvent event )
{
    // Check to see what mouse button is pressed and set appropriate vars
    if( event.isLeft() ) {
        clickX = event.getX();
        clickY = event.getY();
    } else if ( event.isRight() ) {
        clickXr = event.getX();
        clickYr = event.getY();
    }
 
    // set the dragging bool to true
    dragging = true;
}
 
void MouseKeyboardApp::mouseUp( MouseEvent event )
{
    dragging = false;
}
 
void MouseKeyboardApp::mouseMove( MouseEvent event )
{
    mouseX = event.getX();
    mouseY = event.getY();
}
 
void MouseKeyboardApp::mouseDrag( MouseEvent event )
{
    mouseX = event.getX();
    mouseY = event.getY();
}
 
void MouseKeyboardApp::update()
{
    // add new lines
    console() << endl << endl;
 
    // Output current XY
    console() << "Current (x, y) : (" << mouseX << ", " << mouseY << ")" << endl;
 
    // Keep track of Left Clicks
    console() << "Last Left Clicked (x, y) : (" << clickX << ", " << clickY << ")" << endl;
 
    // Move the enemy towards the mouse
    enemyX += (mouseX - enemyX) / 20;
    enemyY += (mouseY - enemyY) / 20;
 
}
 
void MouseKeyboardApp::draw()
{
    // clear out the window with white
    gl::clear( Color( 1, 1, 1 ) );  
 
    // draw a teal circle diameter 20 at current mouse XY
	gl::draw(ship, Area(mouseX - 32, mouseY - 64, mouseX + 32, mouseY));
     
    //draw a pink circle diameter 10 at left click location
    gl::color(Color(1, 0.8, 0.8));
    gl::drawSolidCircle( Vec2f(clickX, clickY), 10);
     
    //draw a yellow circle diameter 35 at right click location
    gl::color(Color(1, 1, 0));
    gl::drawSolidCircle( Vec2f(clickXr, clickYr), 35);
 
    //If dragging, draw a green circle of diameter 22 atcurrent mouseXY
    if(dragging) {
        gl::color(Color(0, 1, 0));
        gl::drawSolidCircle(Vec2f(mouseX, mouseY), 22);
    }
 
    // Draw enemy circle in red
    gl::color(Color(1,0,0));
    gl::drawSolidCircle(Vec2f(enemyX, enemyY), 15);
 
}
 
CINDER_APP_NATIVE( MouseKeyboardApp, RendererGl )
	*/

	#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
 
using namespace ci;
using namespace ci::app;
using namespace std;
 
class KeyboardApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );
    void keyUp( KeyEvent event );
    void update();
    void draw();
 
    bool KEY_W, KEY_S, KEY_A, KEY_D,
         KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT,
         KEY_SPACE;
 
    int x, y;
};
 
void KeyboardApp::setup()
{
    KEY_W = KEY_S = KEY_A = KEY_D =
         KEY_UP = KEY_DOWN = KEY_LEFT = KEY_RIGHT =
         KEY_SPACE = false;
 
    x = 200;
    y = 240;
}
 
void KeyboardApp::mouseDown( MouseEvent event )
{
}
 
void KeyboardApp::keyDown( KeyEvent event )
{
    /* First we switch the getChar() method
        This is pretty straightforward, 
        duplicate for other keys */
    switch(event.getChar()) 
    {
    case 'w':
        KEY_W = true;
        break;
    case 's':
        KEY_S = true;
        break;
    case 'a':
        KEY_A = true;
        break;
    case 'd':
        KEY_D = true;
        break;
    }
 
    /* Now we switch the integer Key Code
       Cinder provides constants for these 
       numbers in the form of KeyEvent::KEY_X
       where X is an identifier. Visual C++
       will help you auto-complete. 
        
       NOTE: we can also use straight integers
       values here, this is shown for the third
       case, which is for KEY_LEFT*/
    switch(event.getCode()) 
    {
    case KeyEvent::KEY_UP:
        KEY_UP = true;
        break;
    case KeyEvent::KEY_DOWN:
        KEY_DOWN = true;
        break;
    case 276:
        KEY_LEFT = true;
        break;
    case KeyEvent::KEY_RIGHT:
        KEY_RIGHT = true;
        break;
    case KeyEvent::KEY_SPACE:
        KEY_SPACE = true;
        break;
    }
}
 
void KeyboardApp::keyUp( KeyEvent event ) 
{
    switch(event.getChar()) 
    {
    case 'w':
        KEY_W = false;
        break;
    case 's':
        KEY_S = false;
        break;
    case 'a':
        KEY_A = false;
        break;
    case 'd':
        KEY_D = false;
        break;
    }
    switch(event.getCode()) 
    {
    case KeyEvent::KEY_UP:
        KEY_UP = false;
        break;
    case KeyEvent::KEY_DOWN:
        KEY_DOWN = false;
        break;
    case KeyEvent::KEY_LEFT:
        KEY_LEFT = false;
        break;
    case KeyEvent::KEY_RIGHT:
        KEY_RIGHT = false;
        break;
    case KeyEvent::KEY_SPACE:
        KEY_SPACE = false;
        break;
    }
}
 
void KeyboardApp::update()
{
    if(KEY_UP || KEY_W) y -= 5; 
    if(KEY_DOWN || KEY_S) y += 5; 
    if(KEY_LEFT || KEY_A) x -= 5; 
    if(KEY_RIGHT || KEY_D) x += 5; 
}
 
void KeyboardApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) ); 
 
    if(KEY_SPACE) {
        gl::color(Color(0, 1, 0) );
        gl::drawSolidCircle( Vec2f( x, y ), 20, 5);
    } else {
        gl::color(Color(1, 0, 0));
        gl::drawSolidRect( Rectf( x - 10, y - 10, x + 10, y + 10) );
    }
}
 
CINDER_APP_NATIVE( KeyboardApp, RendererGl )