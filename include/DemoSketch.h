#pragma once

#include "CinderGLSketch.h"

#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/Texture.h"

#include "cinder/Vector.h"
#include "cinder/Camera.h"

using namespace ci;

class DemoSketch : public CinderGLSketch {
public:
    
    void setup();
    void update();
    void draw(const Area &area);
    
    gl::Fbo m_fbo_read, m_fbo_write;
    Vec2i   m_fbo_size;
    
    gl::GlslProg m_shader;
    
    gl::Texture m_touch_tex;
    
    CameraOrtho m_camera;
    
    const static int PIXEL_SCALE = 2;
    
};