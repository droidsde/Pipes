//
//  Pipe.cpp
//  Pipes
//
//  Created by Victor Wee on 5/4/14.
//
//

#include "Pipe.h"

USING_NS_CC;

//--------------------
// Constructor
//--------------------
Pipes::Pipes(void)
{
    m_pipeType = E_STRAIGHT;
    m_Sprite = NULL;
}

//--------------------
// Destructor
//--------------------
Pipes::~Pipes(void)
{
    
}

void Pipes::Init( E_PIPE_TYPES newType, E_PIPE_DIRECTION newDir, ushort x, ushort y )
{
    m_pipeType = newType;
    m_direction = newDir;
    switch ( m_direction) {
        case E_45 :
            m_Sprite = cocos2d::Sprite::create("E_45.png");
            break;
        case E_135 :
            m_Sprite = cocos2d::Sprite::create("E_135.png");
            break;
        case E_90:
            m_Sprite = cocos2d::Sprite::create("E_90.png");
            break;
        default :
            m_Sprite = cocos2d::Sprite::create("E_0.png");
            break;
    }
    //m_Sprite->setScale(0.1875f);
    Render( x, y);
}

void Pipes::Rotate ( void )
{
    if ( m_direction == E_135 ) m_direction = E_0;
    else m_direction = (E_PIPE_DIRECTION)(m_direction + 1);
    
    switch ( m_direction) {
        case E_45 :
            m_Sprite->setTexture("E_45.png");
            break;
        case E_135 :
            m_Sprite->setTexture("E_135.png");
            break;
        case E_90:
            m_Sprite->setTexture("E_90.png");
            break;
        default :
            m_Sprite->setTexture("E_0.png");
            break;
    }
//    Render( x, y);
}

//--------------------
// Render function
// x - horizontal
// y - vertical
//--------------------
void Pipes::Render (ushort x, ushort y)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // position the sprite on the center of the screen
    float f_posX = visibleSize.width/2 + (x - 5)*48 + 24;
    float f_posY = visibleSize.height/2 + (y - 5)*48 + 24;
    m_Sprite->setPosition(Point(f_posX, f_posY));
}
