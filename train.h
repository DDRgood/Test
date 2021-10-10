#include <iostream>
#include <cstring>
#pragma once

enum LocationStates
{
    AT_STATION_OPEN,
    AT_STATION_CLOSE,
    IN_TUNNEL_MOVE,
    IN_TUNNEL_STOP
};

enum Signal
{
    START_MOVE,
    STOP_MOVE,
    OPEN_DOOR,
    CLOSE_DOOR
};

class Train
{
    private:
        enum LocationStates location;
        bool doorIsOpen;
        bool isMoving;
        bool toggleState(Signal signal);

    public:
        Train(LocationStates state);
        Train();
        bool openDoor();
        bool closeDoor();
        bool startMove();
        bool stopMove();
        friend std::ostream& operator<<(std::ostream& stream, Train& obj);
        std::string getLocationStr();
        bool getDoorIsOpen();
        bool getIsMoving();
        LocationStates getLocationState();
};