#pragma once

namespace ly
{

class Object
{
public:
    Object();

    // destructor for child class.
    virtual ~Object();
    // destroy the object.
    void destroy();
    // getter to know object destroyed.
    bool isPendingDestroy() const;

private:
    // flag to check if object is destroyed.
    bool mIsPendingDestroy;
};

    
} // namespace ly
