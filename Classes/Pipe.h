//
//  Pipe.h
//  Pipes
//
//  Created by Victor Wee on 5/4/14.
//
//

#ifndef __Pipes__Pipe__
#define __Pipes__Pipe__

#include <iostream>
#include "cocos2d.h"

//not used at the moment
enum E_PIPE_TYPES {
    E_STRAIGHT,
    E_TURN,
    E_JUNCTION
};

#define rotate = 90.0f;

enum E_PIPE_DIRECTION {
    E_0,
    E_45,
    E_90,
    E_135
};

class Pipes {

private:
    E_PIPE_TYPES m_pipeType;
    E_PIPE_DIRECTION m_direction;
    cocos2d::Sprite* m_Sprite;
    
public:
    Pipes();
    ~Pipes();
    void Init (E_PIPE_TYPES, E_PIPE_DIRECTION, ushort, ushort);
    void Rotate (void);
    void Render (ushort, ushort);
    cocos2d::Sprite* getSprite( void ) { return m_Sprite; };
};




#endif /* defined(__Pipes__Pipe__) */
