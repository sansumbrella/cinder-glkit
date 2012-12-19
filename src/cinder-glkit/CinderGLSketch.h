#pragma once

#include "cinder/Vector.h"
#include "cinder/Area.h"
#include "cinder/Timer.h"
#include "cinder/Timeline.h"
#include "cinder/app/TouchEvent.h"

#include <ostream>

namespace cinder {

class CinderGLSketch {
public:

    enum UIInterfaceOrientation {
        UIInterfaceOrientationPortrait           = 1,
        UIInterfaceOrientationPortraitUpsideDown = 2,
        UIInterfaceOrientationLandscapeRight     = 3,
        UIInterfaceOrientationLandscapeLeft      = 4
    };

    CinderGLSketch()
    : mNeedsSetup(true)
    , mTimer(true)
    , mTimeline(Timeline::create())
    , mFrameCount(0)
    {};
    
    virtual ~CinderGLSketch(){};

    void privateSetup__();
    void privateUpdate__();

    virtual void setup(){}
    virtual void tearDown(){}
    virtual void update(){}
    virtual void draw(const Area &area){}
    
    Timeline& timeline(){ return *mTimeline; }
    
    const Vec2i& getSize() const { return mSize; }
    void         setSize(const Vec2i &size){ mSize = size; }
    Area         getBounds() const { return Area(0, 0, mSize.x, mSize.y); }
    float        getAspectRatio() const { return (float)mSize.x / (float)mSize.y; }
    
    double getElapsedSeconds() const { return mTimer.getSeconds(); }
    uint32_t getElapsedFrames() const { return mFrameCount; }

    virtual void touchesBegan(app::TouchEvent event){}
    virtual void touchesMoved(app::TouchEvent event){}
    virtual void touchesEnded(app::TouchEvent event){}
    virtual void touchesCanceled(app::TouchEvent event){}
    virtual bool supportsInterfaceOrientation(UIInterfaceOrientation orientation){ return true; }
    
    const std::vector<app::TouchEvent::Touch>& getActiveTouches() const { return mActiveTouches; }
    void setActiveTouches(std::vector<app::TouchEvent::Touch> touches){ mActiveTouches = touches; }
    
    std::ostream& console(){ return std::cout; }
    
    bool mNeedsSetup;

protected:

    Vec2i mSize;
    Timer mTimer;
    TimelineRef mTimeline;
    
    uint32_t mFrameCount;
    
    std::vector< app::TouchEvent::Touch > mActiveTouches;

};

} // namespace cinder