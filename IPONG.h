#ifndef IPONG_H
#define IPONG_H
// Abstract class in order to force the user
class Ipong
{
    public:
        // Method responsible for perform the start of the game
        virtual void play() = 0;
};

#endif